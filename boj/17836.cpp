//
// Created by kdongha on 2019/12/06.
//

#include <bits/stdc++.h>

int N, M, T, ans;
int map[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Move {
    int x;
    int y;
    bool sword;
    int cnt;
};

std::priority_queue<Move> pq;

bool operator<(const Move &m1, const Move &m2) {
    return m1.cnt > m2.cnt;
}


bool inside(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= M;
}

void solve() {
    std::cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> map[i][j];
        }
    }
    ans = T + 1;
    pq.push({1, 1, false, 0});
    while (!pq.empty()) {
        Move m = pq.top();
        pq.pop();
        if (m.cnt >= ans) {
            break;
        } else if (m.x == N && m.y == M) {
            ans = m.cnt;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = m.x + dx[d];
            int ny = m.y + dy[d];
            if (inside(nx, ny)) {
                if (map[nx][ny] == 0) {
                    map[nx][ny] = 3;
                    pq.push({nx, ny, m.sword, m.cnt + 1});
                } else if (map[nx][ny] == 1 && m.sword) {
                    map[nx][ny] = 3;
                    pq.push({nx, ny, m.sword, m.cnt + 1});
                } else if (map[nx][ny] == 2) {
                    ans = std::min(ans, m.cnt + 1 + N - nx + M - ny);
                }
            }
        }
    }
    if (ans > T) {
        std::cout << "Fail";
    } else {
        std::cout << ans;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}