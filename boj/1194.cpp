//
// Created by kdongha on 2019/12/09.
//

#include <bits/stdc++.h>

int N, M, ans;
char map[55][55];
struct Point {
    int x;
    int y;
    int cost;
    int keys;
};
Point start;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool visited[55][55][64];

bool keyCheck(int bit, char door) {
    switch (door) {
        case 'A':
            return bit & 1;
        case 'B':
            return bit & 2;
        case 'C':
            return bit & 4;
        case 'D':
            return bit & 8;
        case 'E':
            return bit & 16;
        case 'F':
            return bit & 32;
        default:
            return false;
    }
}

int keyVal(char key) {
    switch (key) {
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'c':
            return 4;
        case 'd':
            return 8;
        case 'e':
            return 16;
        case 'f':
            return 32;
        default:
            return 0;
    }
}

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int go() {
    std::queue<Point> q;
    visited[start.x][start.y][start.keys] = true;
    q.push(start);
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];
            if (inside(nx, ny) && !visited[nx][ny][p.keys]) {
                visited[nx][ny][p.keys] = true;
                Point np = {nx, ny, p.cost + 1, p.keys};
                if (map[nx][ny] == '#') {
                    continue;
                } else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
                    if (!keyCheck(p.keys, map[nx][ny])) {
                        continue;
                    }
                } else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
                    if ((np.keys & keyVal(map[nx][ny])) == 0) {
                        np.keys += keyVal(map[nx][ny]);
                    }
                } else if (map[nx][ny] == '1') {
                    return p.cost + 1;
                }
                q.push(np);
            }
        }
    }
    return -1;
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == '0') {
                map[i][j] = '.';
                start = {i, j, 0, 0};
            }
        }
    }
    std::cout << go();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}