//
// Created by kdongha on 2020/02/22.
//

#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int W, H, G, E;
int arr[30][30];
int dist[30][30];
struct Path {
    int fromX;
    int fromY;
    int toX;
    int toY;
    int cost;
};


bool inside(int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H;
}

void solve() {
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) {
            break;
        } else {
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < H; j++) {
                    dist[i][j] = INF;
                    arr[i][j] = 0;
                }
            }
            vector<Path> edge;
            cin >> G;
            for (int i = 0; i < G; i++) {
                int X, Y;
                cin >> X >> Y;
                arr[X][Y] = -1;
            }
            cin >> E;
            for (int i = 0; i < E; i++) {
                int X1, X2, Y1, Y2, T;
                cin >> X1 >> Y1 >> X2 >> Y2 >> T;
                edge.push_back({X1, Y1, X2, Y2, T});
                arr[X1][Y1] = 1;
            }
            for (int i = 0; i < W; i++) {
                for (int j = 0; j < H; j++) {
                    if (i == W - 1 && j == H - 1) {
                        break;
                    }
                    if (arr[i][j] == 0) {
                        for (int d = 0; d < 4; d++) {
                            int ni = di[d] + i;
                            int nj = dj[d] + j;
                            if (inside(ni, nj) && arr[ni][nj] != -1) {
                                edge.push_back({i, j, ni, nj, 1});
                            }
                        }
                    }
                }
            }

            dist[0][0] = 0;
            for (int i = 0; i < W * H; i++) {
                bool update = false;
                for (Path p:edge) {
                    if (dist[p.fromX][p.fromY] != INF) {
                        if (dist[p.fromX][p.fromY] + p.cost < dist[p.toX][p.toY]) {
                            update = true;
                            dist[p.toX][p.toY] = dist[p.fromX][p.fromY] + p.cost;
                        }
                    }
                }
                if (i == W * H - 1) {
                    if (update) {
                        cout << "Never\n";
                    } else if (dist[W - 1][H - 1] == INF) {
                        cout << "Impossible\n";
                    } else {
                        cout << dist[W - 1][H - 1] << "\n";
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}