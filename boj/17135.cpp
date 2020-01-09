//
// Created by kdongha on 2020/01/09.
//

#include <bits/stdc++.h>

int N, M, D, ans;
int map[16][16];
int die[16][16];
int archer[3];

void initDie() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            die[i][j] = 0;
        }
    }
}

void countDie() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (die[i][j] > 0) {
                count++;
            }
        }
    }
    ans = std::max(ans, count);
}

int getDist(int r1, int c1, int r2, int c2) {
    return std::abs(r1 - r2) + std::abs(c1 - c2);
}

void play(int count, int idx) {
    if (count == 0) {
        initDie();
        for (int i = N; i > 0; i--) {
            for (int j = 0; j < 3; j++) {
                int dr, dc, dist;
                dist = 100;
                for (int c = 0; c < M; c++) {
                    for (int r = i - 1; r >= 0; r--) {
                        if (map[r][c] == 1 && die[r][c] <= i) {
                            int d = getDist(r, c, i, archer[j]);
                            if (dist > d && D>=d) {
                                dist = d;
                                dr = r;
                                dc = c;
                            }
                        }
                    }
                }
                if (dist != 100) {
                    die[dr][dc] = i;
                }
            }
        }
        countDie();
    } else if (idx < M) {
        archer[3 - count] = idx;
        play(count - 1, idx + 1);
        play(count, idx + 1);
    }
}

void solve() {
    std::cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
        }
    }
    play(3, 0);
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}