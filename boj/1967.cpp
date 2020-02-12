//
// Created by kdongha on 2020/02/13.
//

#include <bits/stdc++.h>

using namespace std;

int n, p, c, w;
int m, u, v;

vector<pair<int, int>> tree[10001];

void dfs(int prev, int current, int value) {
    if (value > m) {
        v = current;
        m = value;
    }
    for (auto next:tree[current]) {
        if (next.first != prev) {
            dfs(current, next.first, value + next.second);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> p >> c >> w;
        tree[p].push_back({c, w});
        tree[c].push_back({p, w});
    }
    m = 0;
    dfs(0, 1, 0);
    m = 0;
    u = v;
    dfs(0, u, 0);
    cout << m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}