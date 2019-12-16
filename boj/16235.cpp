//
// Created by kdongha on 2019/12/16.
//

#include <bits/stdc++.h>

int N, M, K;
struct Land {
    int food = 5;
    int fill;
    int dead = 0;
    std::deque<int> prevTree;
    std::deque<int> nextTree;
};
Land land[11][11];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool inside(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

void solve() {
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> land[i][j].fill;
        }
    }
    for (int i = 0; i < M; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        land[x][y].prevTree.push_back(z);
    }
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            std::sort(land[x][y].prevTree.begin(), land[x][y].prevTree.end());
        }
    }
    for (int k = 0; k < K; k++) {
        for (int x = 1; x <= N; x++) {
            for (int y = 1; y <= N; y++) {
                while (!land[x][y].prevTree.empty()) {
                    int tree = land[x][y].prevTree.front();
                    land[x][y].prevTree.pop_front();
                    if (land[x][y].food >= tree) {
                        land[x][y].food -= tree;
                        land[x][y].nextTree.push_back(tree + 1);
                        if ((tree + 1) % 5 == 0) {
                            for (int d = 0; d < 4; d++) {
                                int nx = x + dx[d];
                                int ny = y + dy[d];
                                if (inside(nx, ny)) {
                                    land[nx][ny].nextTree.push_front(1);
                                }
                            }
                            for (int d = 4; d < 8; d++) {
                                int nx = x + dx[d];
                                int ny = y + dy[d];
                                if (inside(nx, ny)) {
                                    land[nx][ny].prevTree.push_front(1);
                                }
                            }
                        }
                    } else {
                        land[x][y].dead += tree / 2;
                    }
                }
                land[x][y].food += land[x][y].dead;
                land[x][y].dead = 0;
                land[x][y].food += land[x][y].fill;
                land[x][y].prevTree = land[x][y].nextTree;
                land[x][y].nextTree = std::deque<int>();
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cnt += land[i][j].prevTree.size();
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