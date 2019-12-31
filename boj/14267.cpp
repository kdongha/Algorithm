//
// Created by kdongha on 2020/01/01.
//

#include <bits/stdc++.h>

int n, m;
int parent[100001];
int cost[100001];
int dp[100001];

int getW(int idx) {
    if (dp[idx] == -1) {
        dp[idx] = cost[idx] + getW(parent[idx]);
    }
    return dp[idx];
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> parent[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        cost[a] += b;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
    }
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        std::cout << getW(i)<<" ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}