//
// Created by kdongha on 2020/01/13.
//

#include <bits/stdc++.h>

int N, ans;
bool map[15][15];
int di[] = {-1, -1, -1};
int dj[] = {-1, 0, 1};

bool inside(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

bool check(int i, int j) {
    for (int d = 0; d < 3; d++) {
        int ni = i + di[d];
        int nj = j + dj[d];
        while (inside(ni, nj)) {
            if (map[ni][nj]) {
                return false;
            }
            ni += di[d];
            nj += dj[d];
        }
    }
    return true;
}

void put(int i) {
    if (i == N) {
        ans++;
    } else {
        for (int j = 0; j < N; j++) {
            if (check(i, j)) {
                map[i][j] = true;
                put(i + 1);
                map[i][j] = false;
            }
        }
    }
}

void solve() {
    std::cin >> N;
    put(0);
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}