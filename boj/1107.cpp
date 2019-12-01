//
// Created by kdongha on 2019/12/01.
//

#include <bits/stdc++.h>

int N, M, min;
bool broken[10];

void comb(int count, int idx, int value) {
    if (count == idx) {
        min = std::min(min, std::abs(value - N) + idx);
    } else {
        if (idx > 0) {
            min = std::min(min, std::abs(value - N) + idx);
        }
        for (int i = 0; i < 10; i++) {
            if (!broken[i] && idx < min) {
                comb(count, idx + 1, value * 10 + i);
            }
        }
    }
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        std::cin >> tmp;
        broken[tmp] = true;
    }
    min = std::abs(N - 100);
    comb(6, 0, 0);
    std::cout << min;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}