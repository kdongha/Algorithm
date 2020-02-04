//
// Created by kdongha on 2020/02/05.
//

#include <bits/stdc++.h>

#define INF 1234567890

int N, ans;
int dp[100001][18];
std::vector<int> adj[100001];

int getDp(int cur, int prev, int color) {
    if (dp[cur][color] == 0) {
        int sum = 0;
        for (int next:adj[cur]) {
            int min = INF;
            if (next != prev) {
                for (int nextColor = 1; nextColor <= 17; nextColor++) {
                    if (nextColor != color) {
                        min = std::min(min, getDp(next, cur, nextColor));
                    }
                }
                sum += min;
            }
        }
        dp[cur][color] = sum + color;
    }
    return dp[cur][color];
}

void solve() {
    std::cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = INF;
    for (int i = 1; i <= 17; i++) {
        ans = std::min(ans, getDp(1, 0, i));
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