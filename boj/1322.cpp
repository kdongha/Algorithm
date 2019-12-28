//
// Created by kdongha on 2019/12/28.
//

#include <bits/stdc++.h>

long long int X, K, Y;

void solve() {
    std::cin >> X >> K;
    long long int tmp = 1;
    while (K) {
        if (!(X & tmp)) {
            if (K % 2) {
                Y += tmp;
            }
            K /= 2;
        }
        tmp <<= 1;
    }
    std::cout << Y;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}