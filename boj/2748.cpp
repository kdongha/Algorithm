//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

long long int pibo[100];

void solve() {
    pibo[1] = 1;
    pibo[2] = 1;
    int n;
    std::cin >> n;
    for (int i = 3; i <= n; i++) {
        pibo[i] = pibo[i - 1] + pibo[i - 2];
    }
    std::cout << pibo[n];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}