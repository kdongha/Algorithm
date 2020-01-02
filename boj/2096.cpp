//
// Created by kdongha on 2020/01/02.
//

#include <bits/stdc++.h>

int N;
int minDp[2][3];
int maxDp[2][3];

void solve() {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        int cur = i % 2;
        int prev = (i-1)%2;
        std::cin >> a >> b >> c;
        maxDp[cur][0] = std::max(maxDp[prev][0], maxDp[prev][1]) + a;
        maxDp[cur][1] = std::max(maxDp[prev][0], std::max(maxDp[prev][1], maxDp[prev][2])) + b;
        maxDp[cur][2] = std::max(maxDp[prev][1], maxDp[prev][2]) + c;

        minDp[cur][0] = std::min(minDp[prev][0], minDp[prev][1]) + a;
        minDp[cur][1] = std::min(minDp[prev][0], std::min(minDp[prev][1], minDp[prev][2])) + b;
        minDp[cur][2] = std::min(minDp[prev][1], minDp[prev][2]) + c;
    }
    std::cout << std::max(maxDp[N % 2][0], std::max(maxDp[N % 2][1], maxDp[N % 2][2])) << " "
              << std::min(minDp[N % 2][0], std::min(minDp[N % 2][1], minDp[N % 2][2]));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}