//
// Created by kdongha on 2019/12/13.
//

#include <bits/stdc++.h>

int N, M;
struct Room {
    int x;
    int y;
};
std::list<Room> list[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool light[101][101];
bool visited[101][101];
int cnt = 0;

bool inside(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

void reset() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = false;
        }
    }
}

void go() {
    std::queue<Room> q;
    visited[1][1] = true;
    q.push({1, 1});
    while (!q.empty()) {
        Room r = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = r.x + dx[d];
            int ny = r.y + dy[d];
            if (inside(nx, ny) && light[nx][ny] && !visited[nx][ny]) {
                bool flag = false;
                for (auto nr:list[nx][ny]) {
                    if (!light[nr.x][nr.y]) {
                        flag = true;
                        light[nr.x][nr.y] = true;
                        cnt++;
                    }
                }
                list[nx][ny].clear();
                if (flag) {
                    reset();
                    q = std::queue<Room>();
                }
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;
        list[x][y].push_back({a, b});
    }
    light[1][1] = true;
    cnt++;
    for (Room r:list[1][1]) {
        if (!light[r.x][r.y]) {
            cnt++;
            light[r.x][r.y] = true;
        }
    }
    list[1][1].clear();
    go();
    std::cout << cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}