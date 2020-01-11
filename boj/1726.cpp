//
// Created by kdongha on 2020/01/11.
//

#include <bits/stdc++.h>

int M, N, si, sj, sd, ei, ej, ed;
int map[101][101];
int count[101][101][4];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
struct Robot {
    int i;
    int j;
    int d;
    int c;
};
std::queue<Robot> q;

int getDir(int d) {
    switch (d) {
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
    }
}

bool inside(int i, int j) {
    return i > 0 && i <= M && j > 0 && j <= N;
}

void solve() {
    std::cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> map[i][j];
            for (int d = 0; d < 4; d++) {
                count[i][j][d] = -1;
            }
        }
    }
    std::cin >> si >> sj >> sd >> ei >> ej >> ed;
    sd = getDir(sd);
    ed = getDir(ed);
    q.push({si, sj, sd, 0});
    count[si][sj][sd] = 0;
    while (!q.empty()) {
        Robot r = q.front();
        q.pop();
        for (int d = -1; d <= 1; d++) {
            int nd = (r.d + d + 4) % 4;
            if (nd == r.d) {
                for (int k = 1; k <= 3; k++) {
                    int ni = r.i + di[nd] * k;
                    int nj = r.j + dj[nd] * k;
                    int nc = r.c + 1;
                    if (!inside(ni, nj) || map[ni][nj] == 1) {
                        break;
                    }
                    if (count[ni][nj][nd] == -1 || count[ni][nj][nd] > nc) {
                        count[ni][nj][nd] = nc;
                        q.push({ni, nj, nd, nc});
                    }
                }
            } else {
                int ni = r.i;
                int nj = r.j;
                int nc = r.c + 1;
                if (count[ni][nj][nd] == -1 || count[ni][nj][nd] > nc) {
                    count[ni][nj][nd] = nc;
                    q.push({ni, nj, nd, nc});
                }
            }
        }
    }
    std::cout << count[ei][ej][ed];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}