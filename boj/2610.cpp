//
// Created by kdongha on 2019/12/12.
//

#include <bits/stdc++.h>

int N, M;
int dist[105][105];
int parent[105];
int max[105];
int seven[105];
std::vector<int> vec;

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
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
        Union(u, v);
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (i != k) {
                for (int j = 1; j <= N; j++) {
                    if (i != j && k != j) {
                        if (dist[i][k] != 0 && dist[k][j] != 0) {
                            int d = dist[i][k] + dist[k][j];
                            if (dist[i][j] == 0) {
                                dist[i][j] = d;
                            } else {
                                dist[i][j] = std::min(dist[i][j], d);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        max[i] = dist[i][1];
        for (int j = 2; j <= N; j++) {
            max[i] = std::max(max[i], dist[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        int p = find(i);
        if (seven[p] == 0) {
            seven[p] = i;
        } else {
            if (max[seven[p]] > max[i]) {
                seven[p] = i;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (seven[i] != 0) {
            vec.push_back(seven[i]);
        }
    }

    std::sort(vec.begin(), vec.end());
    std::cout << vec.size() << "\n";
    for (auto i:vec) {
        std::cout << i << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}