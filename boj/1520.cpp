//
// Created by kdongha on 2019/12/11.
//

#include <bits/stdc++.h>

int M, N;
int map[505][505];
int dp[505][505];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool inside(int i, int j) {
    return i >= 0 && i < M && j >= 0 && j < N;
}

int getDp(int i, int j) {
    if (dp[i][j] < 0) {
        dp[i][j] = 0;
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (inside(ni, nj) && map[i][j] < map[ni][nj]) {
                dp[i][j] += getDp(ni, nj);
            }
        }
    }
    return dp[i][j];
}

void solve() {
    std::cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;
    std::cout << getDp(M - 1, N - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}