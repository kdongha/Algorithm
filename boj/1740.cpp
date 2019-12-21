//
// Created by kdongha on 2019/12/22.
//

#include <bits/stdc++.h>

long long int N, ans, mul;

void solve() {
    std::cin >> N;
    ans = 0;
    mul = 1;
    while (N) {
        ans += (N % 2) * mul;
        mul *= 3;
        N >>= 1;
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}