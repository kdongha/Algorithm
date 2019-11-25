//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

void solve() {
    std::string str;
    std::cin >> str;
    std::sort(str.begin(), str.end(), std::greater<char>());
    std::cout << str;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}