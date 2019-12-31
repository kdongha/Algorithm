//
// Created by kdongha on 2019/12/31.
//

#include <bits/stdc++.h>

int R, C, N;
char map[101][101];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void left(int r) {
    for (int c = 1; c <= C; c++) {
        if (map[r][c] == 'x') {
            map[r][c] = '.';
            break;
        }
    }
}

void right(int r) {
    for (int c = C; c > 0; c--) {
        if (map[r][c] == 'x') {
            map[r][c] = '.';
            break;
        }
    }
}

bool inside(int r, int c) {
    return r > 0 && r <= R && c > 0 && c <= C;
}

void down() {
    bool visited[101][101];
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            visited[r][c] = false;
        }
    }
    for (int c = 1; c <= C; c++) {
        if (!visited[1][c] && map[1][c] == 'x') {
            visited[1][c] = true;
            std::queue<std::pair<int, int>> q;
            q.push({1, c});
            while (!q.empty()) {
                auto current = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = current.first + dr[d];
                    int nc = current.second + dc[d];
                    if (inside(nr, nc) && map[nr][nc] == 'x' && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    int drop = R;
    for (int r = 2; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (!visited[r][c] && map[r][c] == 'x') {
                bool flag = false;
                for (int k = r - 1; k >= 1; k--) {
                    if (!visited[k][c] && map[k][c] == 'x') {
                        flag = true;
                        break;
                    } else if (map[k][c] == 'x') {
                        drop = std::min(drop, r - k - 1);
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    drop = std::min(drop, r - 1);
                }
            }
        }
    }
    for (int r = 2; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (!visited[r][c] && map[r][c] == 'x') {
                map[r][c] = '.';
                map[r - drop][c] = 'x';
            }
        }
    }
}

void solve() {
    std::cin >> R >> C;
    for (int r = R; r >= 1; r--) {
        for (int c = 1; c <= C; c++) {
            std::cin >> map[r][c];
        }
    }
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int r;
        std::cin >> r;
        if (i % 2 == 0) {
            left(r);
        } else {
            right(r);
        }
        down();
    }
    for (int r = R; r >= 1; r--) {
        for (int c = 1; c <= C; c++) {
            std::cout << map[r][c];
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}