//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int T, N, L, mL;
std::string S, mS;

void solve() {
    std::cin >> T;
    while (T--) {
        mL = -1;
        std::cin >> N;
        while (N--) {
            std::cin >> S >> L;
            if (L > mL) {
                mL = L;
                mS = S;
            }
        }
        std::cout << mS << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}