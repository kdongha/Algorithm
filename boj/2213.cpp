//
// Created by kdongha on 2019/12/29.
//

#include <bits/stdc++.h>

int n;
std::vector<int> list[10005];
int w[10005];
int dp[10005][2];
bool visited[10005];
std::vector<int> ans;

void setDp(int c, int p) {
    dp[c][1] = w[c];
    for (auto next:list[c]) {
        if (next != p) {
            setDp(next, c);
            dp[c][1] += dp[next][0];
            dp[c][0] += std::max(dp[next][0], dp[next][1]);
        }
    }
}

void find(int c, int p, bool pSelect) {
    bool cSelect = false;
    if (!pSelect && dp[c][1] > dp[c][0]) {
        cSelect = true;
        ans.push_back(c);
    }
    for (auto next:list[c]) {
        if (next != p) {
            find(next, c, cSelect);
        }
    }
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    setDp(1, 0);
    find(1, 0, false);
    std::cout << (std::max(dp[1][0], dp[1][1])) << "\n";
    std::sort(ans.begin(), ans.end());
    for (auto i: ans) {
        std::cout << i << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}