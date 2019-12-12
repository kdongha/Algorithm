//
// Created by kdongha on 2019/12/12.
//

#include <bits/stdc++.h>

int T, N, M, C, X, Y;
int bit[100005];

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void update(int x, int y) {
    while (x <= N) {
        bit[x] += y;
        x += x & -x;
    }
}

void solve() {
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> N >> M;
        for (int i = 0; i <= N; i++) {
            bit[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
            int tmp;
            std::cin >> tmp;
            update(i, tmp);
        }
        std::cout << "#" << t;
        for (int i = 0; i < M; i++) {
            std::cin >> C >> X >> Y;
            if (C == 1) {
                update(X, Y);
            } else {
                std::cout << " " << sum(Y) - sum(X - 1);
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}