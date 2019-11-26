//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

int N, M, min = 0x7FFFFFFF;
char board[55][55];

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> board[i];
    }
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int count = 0;
            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    if (x % 2 == 0) {
                        if (y % 2 == 0) {
                            if (board[x + i][y + j] != 'W') {
                                count++;
                            }
                        } else {
                            if (board[x + i][y + j] != 'B') {
                                count++;
                            }
                        }
                    } else {
                        if (y % 2 == 0) {
                            if (board[x + i][y + j] != 'B') {
                                count++;
                            }
                        } else {
                            if (board[x + i][y + j] != 'W') {
                                count++;
                            }
                        }
                    }
                }
            }
            min = std::min(min, std::min(count, 64 - count));
        }
    }
    std::cout << min;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}