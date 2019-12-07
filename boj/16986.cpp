//
// Created by kdongha on 2019/12/07.
//

#include <bits/stdc++.h>

int N, K, ans;
int A[10][10];
bool check[10];
int pre[2][20];

bool win(int a, int b) {
    return A[a][b] == 2;
}

void game(int p1, int p2, int a, int b, int c, int i1, int i2) {
    if (a == K) {
        ans = 1;
        return;
    } else if (b == K || c == K || ans == 1) {
        return;
    } else {
        if (p1 != 0) {
            if (win(pre[0][i1], pre[1][i2])) {
                game(0, 1, a, b + 1, c, i1 + 1, i2 + 1);
            } else {
                game(0, 2, a, b, c + 1, i1 + 1, i2 + 1);
            }
        } else {
            for (int i = 1; i <= N; i++) {
                if (!check[i]) {
                    check[i] = true;
                    if (p2 == 1) {
                        if (win(i, pre[0][i1])) {
                            game(0, 2, a + 1, b, c, i1 + 1, i2);
                        } else {
                            game(1, 2, a, b + 1, c, i1 + 1, i2);
                        }
                    } else {
                        if (win(i, pre[1][i2])) {
                            game(0, 1, a + 1, b, c, i1, i2 + 1);
                        } else {
                            game(1, 1, a, b, c + 1, i1, i2 + 1);
                        }
                    }
                    check[i] = false;
                }
            }
        }
    }
}

void solve() {
    std::cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> A[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 20; j++) {
            std::cin >> pre[i][j];
        }
    }
    ans = 0;
    game(0, 1, 0, 0, 0, 0, 0);
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}