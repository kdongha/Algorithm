//
// Created by kdongha on 2020/02/13.
//

#include <bits/stdc++.h>

using namespace std;

int N, K, W, V;
int dp[100001];

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        for (int j = K; j - W >= 0; j--) {
            dp[j] = max(dp[j], dp[j - W] + V);
        }
    }
    cout << dp[K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}