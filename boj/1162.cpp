//
// Created by kdongha on 2020/01/19.
//

#include <bits/stdc++.h>

#define MAX 10000000005;
int N, M, K;
long long int dist[10001][21];
struct Path {
    int to;
    long long int cost;
    int cnt;
};
std::priority_queue<Path> pq;
std::vector<std::pair<int, int>> list[10001];

bool operator<(const Path &p1, const Path &p2) {
    if (p1.cost != p2.cost) {
        return p1.cost > p2.cost;
    }
    return p1.cnt > p2.cnt;
}

void solve() {
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dist[i][j] = MAX;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        list[a].push_back({b, c});
        list[b].push_back({a, c});
    }
    dist[1][0] = 0;
    pq.push({1, 0, 0});
    while (!pq.empty()) {
        Path path = pq.top();
        pq.pop();
        for (auto next:list[path.to]) {
            int to = next.first;
            long long int cost = next.second + path.cost;
            int cnt = path.cnt;
            if (dist[to][cnt] > cost) {
                dist[to][cnt] = cost;
                pq.push({to, cost, cnt});
            }
            if (cnt < K && dist[to][cnt + 1] > path.cost) {
                dist[to][cnt + 1] = path.cost;
                pq.push({to, path.cost, cnt + 1});
            }
        }
    }
    long long int ans = MAX;
    for (int i = 0; i <= K; i++) {
        ans = std::min(ans, dist[N][i]);
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}