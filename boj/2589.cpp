//
// Created by kdongha on 2019/12/01.
//

#include <bits/stdc++.h>

int L, W, ans;
char map[55][55];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void go(int x, int y) {
    int dist[55][55];
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            dist[i][j] = 0x7fffffff;
        }
    }
    dist[x][y] = 0;
    std::queue<std::tuple<int, int, int>> q;
    q.push({x, y, 0});
    while (!q.empty()) {
        int i, j, c, ni, nj, nc;
        std::tie(i, j, c) = q.front();
        q.pop();
        ans=std::max(ans, c);
        for (int d = 0; d < 4; d++) {
            ni = i + di[d];
            nj = j + dj[d];
            nc = c + 1;
            if (ni >= 0 && ni < L && nj >= 0 && nj < W && map[ni][nj] == 'L' && dist[ni][nj] > nc) {
                dist[ni][nj] = nc;
                q.push({ni, nj, nc});
            }
        }
    }
}

void solve() {
    std::cin >> L >> W;
    for (int i = 0; i < L; i++) {
        std::cin >> map[i];
    }
    ans = 0;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 'L') {
                go(i, j);
            }
        }
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}