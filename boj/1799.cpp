//
// Created by kdongha on 2020/01/13.
//

#include <bits/stdc++.h>

int N;
int map[20][20];
bool d[30];

int put(int idx) {
    if (idx < 2 * N - 1) {
        int max = -1;
        int i = idx < N ? idx : N - 1;
        int j = idx < N ? 0 : idx - (N - 1);
        while (i >= 0 && j < N) {
            if (map[i][j] == 1 && !d[N - i + j]) {
                d[N - i + j] = true;
                int m = put(idx + 2) + 1;
                max = std::max(max, m);
                d[N - i + j] = false;
            }
            i--;
            j++;
        }
        if (max < 0) {
            max = put(idx + 2);
        }
        return max;
    }
    return 0;
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }
    std::cout << put(0) + put(1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}