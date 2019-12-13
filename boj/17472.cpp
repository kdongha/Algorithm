//
// Created by kdongha on 2019/12/13.
//

#include <bits/stdc++.h>

int N, M;
int map[11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int parent[100];

struct Bridge {
    int x;
    int y;
    int d;
    int label;
    int len;
};

void init() {
    for (int i = 2; i < 100; i++) {
        parent[i] = i;
    }
}

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void setLabel(int x, int y, int label) {
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    map[x][y] = label;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inside(nx, ny) && map[nx][ny] == 1) {
                map[nx][ny] = label;
                q.push({nx, ny});
            }
        }
    }
}

int naming() {
    int team = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                setLabel(i, j, team++);
            }
        }
    }
    return team - 2;
}

int find(int u) {
    if (parent[u] == u) {
        return u;
    } else {
        return parent[u] = find(parent[u]);
    }
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u > v) {
        parent[u] = v;
    } else {
        parent[v] = u;
    }
}

int crafting(int count) {
    std::queue<Bridge> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] > 1) {
                for (int d = 0; d < 4; d++) {
                    q.push({i, j, d, map[i][j], 0});
                }
            }
        }
    }
    int res = 0;
    int cnt = 0;
    while (!q.empty()) {
        Bridge b = q.front();
        q.pop();
        int nx = b.x + dx[b.d];
        int ny = b.y + dy[b.d];
        if (inside(nx, ny)) {
            if (map[nx][ny] == 0) {
                q.push({nx, ny, b.d, b.label, b.len + 1});
            } else {
                if (map[nx][ny] != b.label && b.len >= 2) {
                    if (find(b.label) != find(map[nx][ny])) {
                        cnt++;
                        res += b.len;
                        merge(b.label, map[nx][ny]);
                    }
                }
            }
        }
    }
    if (cnt != count) {
        return -1;
    } else {
        return res;
    }
}

void solve() {
    std::cin >> N >> M;
    init();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    int count = naming();
    int res = crafting(count - 1);
    std::cout << res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}