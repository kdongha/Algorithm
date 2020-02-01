//
// Created by kdongha on 2020/02/02.
//

#include <bits/stdc++.h>

int R, C, M, ans;
int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 1, -1};

struct Shark {
    int r;
    int c;
    int s;
    int d;
    int z;
    bool dead;

    void move() {
        r += dr[d] * s;
        c += dc[d] * s;
        while (r <= 0 || r > R || c <= 0 || c > C) {
            if (r <= 0) {
                r = 2 - r;
                d = 2;
            } else if (r > R) {
                r = 2 * R - r;
                d = 1;
            } else if (c <= 0) {
                c = 2 - c;
                d = 3;
            } else {
                c = 2 * C - c;
                d = 4;
            }
        }
    }
};

int map[101][101];
Shark shark[10001];

bool operator>(const Shark &s1, const Shark &s2) {
    return s1.z > s2.z;
}

void solve() {
    std::cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        int r, c, s, d, z;
        std::cin >> r >> c >> s >> d >> z;
        map[r][c] = i;
        if (d < 3) {
            s = s % (2 * (R - 1));
        } else {
            s = s % (2 * (C - 1));
        }
        shark[i] = {r, c, s, d, z, false};
    }
    for (int j = 1; j <= C; j++) {
        for (int i = 1; i <= R; i++) {
            if (map[i][j] != 0) {
                int get = map[i][j];
                shark[get].dead = true;
                map[i][j] = 0;
                ans += shark[get].z;
                break;
            }
        }
        for (int a = 1; a <= R; a++) {
            for (int b = 1; b <= C; b++) {
                map[a][b]=0;
            }
        }
        for (int k = 1; k <= M; k++) {
            if (!shark[k].dead) {
                int r, c;
                shark[k].move();
                r = shark[k].r;
                c = shark[k].c;
                if (map[r][c] == 0) {
                    map[r][c] = k;
                } else {
                    int pre = map[r][c];
                    if (shark[k] > shark[pre]) {
                        shark[pre].dead = true;
                        map[r][c] = k;
                    } else {
                        shark[k].dead = true;
                    }
                }
            }
        }
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