//
// Created by kdongha on 2020/02/18.
//

#include <bits/stdc++.h>

int Tc, N, M;
long long int dist[500005];
struct Edge {
    int to;
    int cost;
};

struct Path {
    int to;
    long long int cost;
    int add;

};

bool operator<(const Path &p1, const Path &p2) {
    if (p1.cost != p2.cost) {
        return p1.cost > p2.cost;
    } else {
        return p1.add > p2.add;
    }
}

void solve() {
    std::cin >> N >> M;
    std::vector<std::vector<Edge>> list(N + 1, std::vector<Edge>());
    for (int i = 0; i < M; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        list[u].push_back({v, c});
        list[v].push_back({u, c});
    }
    std::fill(dist, dist + N + 1, -1);
    dist[1] = 0;
    std::priority_queue<Path> pq;
    for (auto e:list[1]) {
        pq.push({e.to, e.cost, e.cost});
    }
    long long int ans = 0;
    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();
        if (dist[p.to] == -1 || dist[p.to] > p.cost) {
            dist[p.to] = p.cost;
            ans += p.add;
            for (auto e:list[p.to]) {
                if (dist[e.to] == -1 || dist[e.to] > dist[p.to] + e.cost) {
                    pq.push({e.to, dist[p.to] + e.cost, e.cost});
                }
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}