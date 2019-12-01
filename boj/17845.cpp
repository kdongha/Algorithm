//
// Created by kdongha on 2019/12/01.
//

#include <bits/stdc++.h>


int N, K;
int dp[10005];

void solve() {
    std::cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int importance, time;
        std::cin >> importance >> time;
        for (int t = N; t - time >= 0; t--) {
            if (dp[t - time] + importance > dp[t]) {
                dp[t] = dp[t - time] + importance;
            }
        }
    }
    std::cout << dp[N];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}