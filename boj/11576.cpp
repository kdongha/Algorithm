//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int A, B, m;
std::vector<int> v;

void solve() {
    std::cin >> A >> B >> m;
    int mul = 1;
    for (int i = 0; i < m - 1; i++) {
        mul *= A;
    }
    int num = 0;
    for (int i = 0; i < m; i++) {
        int tmp;
        std::cin >> tmp;
        num += tmp * mul;
        mul /= A;
    }
    while (num) {
        v.push_back(num % B);
        num /= B;
    }
    for (auto rit = v.rbegin(); rit != v.rend(); rit++) {
        std::cout << *rit << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}