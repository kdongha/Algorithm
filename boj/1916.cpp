//
// Created by kdongha on 2019/11/30.
//

#include <bits/stdc++.h>

int N, M, S, E;
int dist[1005];
int map[1005][1005];

struct Path {
    int s;
    int e;
    int v;
};

bool operator<(const Path &p1, const Path &p2) {
    return p1.v > p2.v;
}

void solve() {
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = 100000;
        }
    }
    for (int i = 0; i < M; i++) {
        int s, e, c;
        std::cin >> s >> e >> c;
        if (c < map[s][e]) {
            map[s][e] = c;
        }
    }
    std::fill(dist, dist + N + 1, 1000000000);
    std::cin >> S >> E;
    std::priority_queue<Path> pq;
    dist[S] = 0;
    for (int i = 1; i <= N; i++) {
        if (map[S][i] != 100000) {
            pq.push({S, i, map[S][i]});
        }
    }
    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();
        if (dist[p.e] > p.v) {
            dist[p.e] = p.v;
            for (int i = 1; i <= N; i++) {
                if (dist[i] > dist[p.e] + map[p.e][i] && map[p.e][i] != 100000) {
                    pq.push({p.e, i, dist[p.e] + map[p.e][i]});
                }
            }
        }
    }
    std::cout << dist[E];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}