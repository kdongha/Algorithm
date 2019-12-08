//
// Created by kdongha on 2019/12/09.
//

#include <bits/stdc++.h>

int V, E;
int parent[10005];
struct Edge {
    int u;
    int v;
    int cost;
};
std::priority_queue<Edge> pq;

bool operator<(const Edge &e1, const Edge &e2) {
    return e1.cost > e2.cost;
}

void init() {
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
}

int find(int u) {
    if (parent[u] == u) {
        return u;
    } else {
        return parent[u] = find(parent[u]);
    }
}

void Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u > v) {
        parent[u] = v;
    } else {
        parent[v] = u;
    }
}

void solve() {
    std::cin >> V >> E;
    init();
    for (int i = 0; i < E; i++) {
        int u, v, cost;
        std::cin >> u >> v >> cost;
        pq.push({u, v, cost});
    }
    long long int sum = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (find(e.u) != find(e.v)) {
            Union(e.u, e.v);
            sum += e.cost;
        }
    }
    std::cout << sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}