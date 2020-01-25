//
// Created by kdongha on 2020/01/23.
//

#include <bits/stdc++.h>

int m, Q, n, x;
int f[500005][22];

void solve() {
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> f[i][0];
    }
    for (int j = 1; j < 22; j++) {
        for (int i = 1; i <= m; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    std::cin >> Q;
    while (Q--) {
        std::cin >> n >> x;
        for (int i = 0; n > 0; i++) {
            if ((n & 1) > 0) {
                x = f[x][i];
            }
            n >>= 1;
        }
        std::cout << x << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}