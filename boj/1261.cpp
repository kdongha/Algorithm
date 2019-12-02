//
// Created by kdongha on 2019/12/02.
//

#include <bits/stdc++.h>

int N, M;
char map[105][105];
int dist[105][105];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

struct Path {
    int i, j, c;
};
std::priority_queue<Path> pq;

bool operator<(const Path &p1, const Path &p2) {
    return p1.c > p2.c;
}

void solve() {
    std::cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> map[i][j];
            dist[i][j] = 0x7fffffff;
        }
    }
    dist[1][1] = 0;
    if (M > 1) {
        pq.push({1, 2, map[1][2] - '0'});
    }
    if (N > 1) {
        pq.push({2, 1, map[2][1] - '0'});
    }
    while (!pq.empty()) {
        Path p = pq.top();
        pq.pop();
        if (dist[p.i][p.j] > p.c) {
            dist[p.i][p.j] = p.c;
            for (int d = 0; d < 4; d++) {
                int ni = p.i + di[d];
                int nj = p.j + dj[d];
                if (ni >= 1 && ni <= N && nj >= 1 && nj <= M && dist[ni][nj] > (p.c + map[ni][nj] - '0')) {
                    pq.push({ni, nj, p.c + map[ni][nj] - '0'});
                }
            }
        }
    }
    std::cout << dist[N][M];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}