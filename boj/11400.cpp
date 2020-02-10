//
// Created by kdongha on 2020/02/11.
//

#include <bits/stdc++.h>

using namespace std;
int V, E, number;
vector<int> adj[100001];
int discovered[100001];
vector<pair<int, int>> ans;

int dfs(int prev, int current) {
    discovered[current] = ++number;
    int m = discovered[current];
    for (int next:adj[current]) {
        if (next == prev) {
            continue;
        }
        if (discovered[next] > 0) {
            m = min(m, discovered[next]);
            continue;
        }
        int n = dfs(current, next);
        if (n > discovered[current]) {
            ans.push_back({min(current, next), max(current, next)});
        }
        m = min(m, n);
    }
    return m;
}

void solve() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= V; i++) {
        if (discovered[i] == 0) {
            dfs(0, i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto a:ans) {
        std::cout << a.first << " " << a.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}