//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int bingo[7][7];
int cnt;

void find(int val) {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (bingo[i][j] == val) {
                bingo[i][0]++;
                if (bingo[i][0] == 5) {
                    cnt++;
                }
                bingo[0][j]++;
                if (bingo[0][j] == 5) {
                    cnt++;
                }
                if (i == j) {
                    bingo[0][0]++;
                    if (bingo[0][0] == 5) {
                        cnt++;
                    }
                }
                if (i + j == 6) {
                    bingo[0][6]++;
                    if (bingo[0][6] == 5) {
                        cnt++;
                    }
                }
                goto go;
            }
        }
    }
    go:
    return;
}

void solve() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            std::cin >> bingo[i][j];
        }
    }
    for (int i = 1; i <= 25; i++) {
        int tmp;
        std::cin >> tmp;
        find(tmp);
        if (cnt >= 3) {
            std::cout << i;
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}