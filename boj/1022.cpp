//
// Created by kdongha on 2019/12/04.
//

#include <bits/stdc++.h>

int r1, c1, r2, c2;
int map[55][55];

void fill() {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (i >= j) {
                int max = std::max(std::abs(i), std::abs(j));
                map[i - r1][j - c1] = (2 * max + 1) * (2 * max + 1) - 2 * max + i + j;
            } else {
                int max = std::max(std::abs(i), std::abs(j));
                map[i - r1][j - c1] = 4 * max * max + 1 - 2 * max - i - j;
            }
        }
    }
}

int find() {
    int max = 0;
    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            int len = 0;
            int num = map[i][j];
            if (num < 0) {
                len++;
                num = -num;
            }
            while (num) {
                len++;
                num /= 10;
            }
            max = std::max(max, len);
        }
    }
    return max;
}

void print(int len) {
    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            std::cout << std::setw(len) << map[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void solve() {
    std::cin >> r1 >> c1 >> r2 >> c2;
    fill();
    int len = find();
    print(len);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}