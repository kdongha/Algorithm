//
// Created by kdongha on 2020/02/21.
//

#include <bits/stdc++.h>

using namespace std;

int Tc, n, m, t, s, g, h, a, b, d;
struct path {
    int to;
    int dist;
    bool over;
};

bool operator<(const path &p1, const path &p2) {
    return p1.dist > p2.dist;
}

void solve() {
    cin >> Tc;
    while (Tc--) {
        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<pair<int, bool>> dist(n + 1, {2000001, false});
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        priority_queue<path> pq;
        pq.push({s, 0, false});
        while (!pq.empty()) {
            path p = pq.top();
            pq.pop();
            if (dist[p.to].first > p.dist) {
                dist[p.to] = {p.dist, p.over};
            } else if (dist[p.to].first == p.dist && !dist[p.to].second && p.over) {
                dist[p.to].second = true;
            } else {
                continue;
            }
            for (pair<int, int> next:adj[p.to]) {
                int nextTo = next.first;
                int nextDist = next.second + p.dist;
                bool over = p.over || (p.to == g && nextTo == h) || (p.to == h && nextTo == g);
                if (dist[nextTo].first >= nextDist) {
                    pq.push({nextTo, nextDist, over});
                }
            }
        }
        vector<int> answer;
        for (int i = 0; i < t; i++) {
            cin >> a;
            if (dist[a].second) {
                answer.push_back(a);
            }
        }
        sort(answer.begin(), answer.end());
        for (int ans:answer) {
            cout << ans << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}