//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

long long int S;
int i;

void solve() {
    std::cin >> S;
    while (S > i) {
        S -= ++i;
    }
    std::cout << i;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}