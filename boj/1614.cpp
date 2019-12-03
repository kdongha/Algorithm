//
// Created by kdongha on 2019/12/04.
//

#include <bits/stdc++.h>

int finger, cnt;

void solve() {
    std::cin >> finger >> cnt;
    switch (finger) {
        case 1:
            std::cout << 8L * cnt;
            return;
        case 2:
            if (cnt % 2) {
                std::cout << 8L * (cnt / 2) + 7;
            } else {
                std::cout << 8L * (cnt / 2) + 1;
            }
            return;
        case 3:
            if (cnt % 2) {
                std::cout << 8L * (cnt / 2) + 6;
            } else {
                std::cout << 8L* (cnt / 2) + 2;
            }
            return;
        case 4:
            if (cnt % 2) {
                std::cout << 8L * (cnt / 2) + 5;
            } else {
                std::cout << 8L * (cnt / 2) + 3;
            }
            return;
        case 5:
            std::cout << 8L * cnt + 4;
            return;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}