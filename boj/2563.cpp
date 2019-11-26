//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

bool area[101][101];
int N, cnt;

void solve() {
    std::cin >> N;
    while (N--) {
        int x, y;
        std::cin >> x >> y;
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                if (!area[i][j]) {
                    area[i][j] = true;
                    cnt++;
                }
            }
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