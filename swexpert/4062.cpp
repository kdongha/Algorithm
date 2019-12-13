//
// Created by kdongha on 2019/12/13.
//

#include <bits/stdc++.h>

int Tc, N;
char map[1005][1005];
int dp[1005][1005];

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                std::cin >> map[i][j];
            }
        }
        int max = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == '0') {
                    dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    max = std::max(max, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        std::cout << "#" << tc << " " << max << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}