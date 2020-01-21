//
// Created by kdongha on 2020/01/22.
//

#include <bits/stdc++.h>

int di[] = {1, 1, 2, 2, 2, 1, 0, 0, 0};
int dj[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int ans;
bool map[16][16];

void up(int i, int j, int t) {
    if (ans == 0) {
        if (i >= 8) {
            ans = 1;
            return;
        } else {
            for (int d = 0; d < 9; d++) {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (nj >= 0 && nj < 8 && ni > t && !map[ni - 1][nj] && !map[ni][nj]) {
                    up(ni, nj, t + 1);
                }
            }
        }
    }
}

void solve() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            char c;
            std::cin >> c;
            map[i][j] = (c == '#');
        }
    }
    up(0, 0, 0);
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}