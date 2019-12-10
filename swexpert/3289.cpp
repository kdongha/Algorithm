//
// Created by kdongha on 2019/12/10.
//

#include <bits/stdc++.h>

int Tc, n, m, op, a, b;
int parent[1000005];

void init() {
    for (int i = 1; i <= n; i++) {
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
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> n >> m;
        init();
        std::cout << "#" << tc << " ";
        for (int i = 0; i < m; i++) {
            std::cin >> op >> a >> b;
            if (op == 0) {
                Union(a, b);
            } else {
                std::cout << (find(a) == find(b) ? 1 : 0);
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}