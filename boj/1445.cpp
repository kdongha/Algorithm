//
// Created by kdongha on 2020/02/06.
//

#include <bits/stdc++.h>

int N, M, sx, sy, fx, fy;
char map[51][51];
struct Node {
    int trash;
    int near;
};
Node dp[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool operator<(const Node &n1, const Node &n2) {
    if (n1.trash == n2.trash) {
        return n1.near < n2.near;
    }
    return n1.trash < n2.trash;
}

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool near(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (inside(nx, ny) && map[nx][ny] == 'g') {
            return true;
        }
    }
    return false;
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = {3000, 3000};
            std::cin >> map[i][j];
            if (map[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (map[i][j] == 'F') {
                fx = i;
                fy = j;
            }
        }
    }
    dp[sx][sy] = {0, 0};
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = current.first + dx[d];
            int ny = current.second + dy[d];
            if (inside(nx, ny)) {
                Node node = dp[current.first][current.second];
                if (map[nx][ny] == 'g') {
                    node.trash++;
                }
                else if (near(nx, ny)) {
                    node.near++;
                }
                if (node < dp[nx][ny]) {
                    dp[nx][ny] = node;
                    q.push({nx, ny});
                }
            }
        }
    }
    if(near(fx,fy)){
        dp[fx][fy].near--;
    }
    std::cout << dp[fx][fy].trash << " " << dp[fx][fy].near;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}