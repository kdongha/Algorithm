//
// Created by kdongha on 2019/12/05.
//

#include <bits/stdc++.h>

int N, M, K, a, b, c, ans;
int map[305][305];
int dp[305][305];

void solve() {
    std::cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        std::cin >> a >> b >> c;
        if (a < b) {
            map[a][b] = std::max(map[a][b], c);
            if (a == 1) {
                dp[b][2] = map[a][b];
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int m = 2; m < M; m++) {
            for (int j = i + 1; j <= N; j++) {
                if (dp[i][m] != 0 && map[i][j] != 0) {
                    dp[j][m + 1] = std::max(dp[j][m + 1], dp[i][m] + map[i][j]);
                }
            }
        }
    }

    ans = 0;
    for (int m = 1; m <= M; m++) {
        ans = std::max(ans, dp[N][m]);
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