//
// Created by kdongha on 2019/12/08.
//

#include <bits/stdc++.h>

int N, M, ans;
int table[1005][1005];
int dp[1005][1005][3];

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> table[i][j];
        }
    }
    for (int j = 0; j < M; j++) {
        for (int d = 0; d < 3; d++) {
            dp[0][j][d] = table[0][j];
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0) {
                dp[i][j][1] = dp[i - 1][j][2] + table[i][j];
                dp[i][j][2] = std::min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + table[i][j];
            } else if (j + 1 < M) {
                dp[i][j][0] = std::min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + table[i][j];
                dp[i][j][1] = std::min(dp[i - 1][j][0], dp[i - 1][j][2]) + table[i][j];
                dp[i][j][2] = std::min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]) + table[i][j];
            } else {
                dp[i][j][0] = std::min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + table[i][j];
                dp[i][j][1] = dp[i - 1][j][0] + table[i][j];
            }
        }
    }
    ans = 0x7fffffff;
    for (int j = 0; j < M; j++) {
        for (int d = 0; d < 3; d++) {
            if (j == 0 && d == 0) continue;
            if (j == M - 1 && d == 2) continue;
            ans = std::min(ans, dp[N - 1][j][d]);
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