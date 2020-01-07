//
// Created by kdongha on 2020/01/08.
//

#include <bits/stdc++.h>

int N, M, ans;
int map[20][20];
bool checked[20][20];
struct Point {
    int i;
    int j;
};
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool inside(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void count() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            checked[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2 && !checked[i][j]) {
                std::queue<Point> q;
                int cnt = 1;
                bool die = true;
                q.push({i, j});
                checked[i][j] = true;
                while (!q.empty()) {
                    Point p = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ni = p.i + di[d];
                        int nj = p.j + dj[d];
                        if (inside(ni, nj) && !checked[ni][nj]) {
                            if (map[ni][nj] == 2) {
                                q.push({ni, nj});
                                checked[ni][nj] = true;
                                cnt += 1;
                            } else if (map[ni][nj] == 0) {
                                die = false;
                            }
                        }
                    }
                }
                if (die) {
                    sum += cnt;
                }
            }
        }
    }
    ans = std::max(ans, sum);
}

void put(int cnt, int idx) {
    if (cnt == 0) {
        count();
    } else if (idx < N * M) {
        int i = idx / M;
        int j = idx % M;
        if (map[i][j] == 0) {
            map[i][j] = 1;
            put(cnt - 1, idx + 1);
            map[i][j] = 0;
        }
        put(cnt, idx + 1);
    }
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    ans = 0;
    put(2, 0);
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}