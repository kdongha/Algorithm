//
// Created by kdongha on 2019/12/08.
//

#include <bits/stdc++.h>

int N, M;
int map[55][55];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Point {
    int x;
    int y;
};

bool inside(int x, int y) {
    return x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1;
}

int fill(int height) {
    std::queue<Point> q;
    q.push({0, 0});
    map[0][0] = height;
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];
            if (inside(nx, ny) && map[nx][ny] < height) {
                map[nx][ny] = height;
                q.push({nx, ny});
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] < height) {
                sum += height - map[i][j];
                map[i][j] = height;
            }
        }
    }
    return sum;
}

void solve() {
    std::cin >> N >> M;
    int max = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char tmp;
            std::cin >> tmp;
            map[i][j] = tmp - '0';
            max = std::max(max, map[i][j]);
        }
    }
    int sum = 0;
    for (int i = 2; i <= max; i++) {
        sum += fill(i);
    }
    std::cout << sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}