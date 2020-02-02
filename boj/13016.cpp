//
// Created by kdongha on 2020/02/03.
//

#include <bits/stdc++.h>

int N, from, to, length, max, u, v;
std::vector<int> dist;
std::vector<int> res;
std::vector<std::vector<std::pair<int, int>>> cost;

void dfs(int cur, int len) {
    dist[cur] = len;
    if (dist[cur] > max) {
        max = dist[cur];
        u = cur;
    }
    for (auto next:cost[cur]) {
        if (dist[next.first] == -1) {
            dfs(next.first, len + next.second);
        }
    }
}

void solve() {
    std::cin >> N;
    cost.resize(N + 1);
    dist.assign(N + 1, -1);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> from >> to >> length;
        cost[from].push_back({to, length});
        cost[to].push_back({from, length});
    }
    dfs(1, 0);
    v = u;
    max = 0;
    dist.assign(N + 1, -1);
    dfs(v, 0);
    res = dist;
    dist.assign(N + 1, -1);
    dfs(u, 0);
    for (int i = 1; i <= N; i++) {
        std::cout << std::max(res[i], dist[i]) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}