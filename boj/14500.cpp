//
// Created by kdongha on 2019/11/29.
//

#include <bits/stdc++.h>

int N, M, cnt;
int map[505][505];
bool visited[505][505];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Point {
    int x;
    int y;
    int value;
};

bool operator<(const Point &p1, const Point &p2) {
    return p1.value < p2.value;
}

int count(int x, int y) {
    int sum = 0, cnt = 0;
    std::priority_queue<Point> pq;
    std::vector<Point> v;
    v.push_back({x, y, 0});
    visited[x][y] = true;
    pq.push({x, y, map[x][y]});
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        sum += p.value;
        cnt++;
        if (cnt == 4) {
            for (auto p: v) {
                visited[p.x][p.y] = false;
            }
            return sum;
        }
        for (int d = 0; d < 4; d++) {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                visited[nx][ny] = true;
                pq.push({nx, ny, map[nx][ny]});
                v.push_back({nx, ny, 0});
            }
        }
    }
    return 0;
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt = std::max(cnt, count(i, j));
        }
    }
    std::cout << cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}