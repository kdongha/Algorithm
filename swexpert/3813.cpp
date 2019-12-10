//
// Created by kdongha on 2019/12/10.
//

#include <bits/stdc++.h>

int Tc, N, K;
int block[200005];
int size[200005];

bool save(int level) {
    int idx = 0;
    int k = 0;
    while (k < K) {
        int con = 0;
        while (idx < N) {
            if (block[idx++] <= level) {
                con++;
                if (con == size[k]) {
                    k++;
                    break;
                }
            } else {
                con = 0;
            }
        }
        if (idx == N && k < K) {
            return false;
        }
    }
    return true;
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        int l = 1;
        int r = 0;
        std::cin >> N >> K;
        for (int i = 0; i < N; i++) {
            std::cin >> block[i];
            r = std::max(r, block[i]);
        }
        for (int i = 0; i < K; i++) {
            std::cin >> size[i];
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (save(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        std::cout << "#" << tc << " " << l << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}