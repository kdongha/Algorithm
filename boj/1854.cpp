//
// Created by kdongha on 2020/02/09.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
priority_queue<int> ans[1001];
struct Path {
    int to;
    int cost;
};
vector<Path> adj[1001];

priority_queue<Path> pq;

bool operator<(const Path &p1, const Path &p2) {
    return p1.cost > p2.cost;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    pq.push({1, 0});
    ans[1].push(0);
    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();
        for (Path np:adj[p.to]) {
            int nto = np.to;
            int ncost = np.cost + p.cost;
            if (ans[nto].size() < k) {
                ans[nto].push(ncost);
                pq.push({nto, ncost});
            } else if (ans[nto].top() > ncost) {
                ans[nto].pop();
                ans[nto].push(ncost);
                pq.push({nto, ncost});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i].size() == k) {
            cout << ans[i].top() << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}