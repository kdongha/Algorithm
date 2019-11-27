//
// Created by kdongha on 2019/11/27.
//

#include <bits/stdc++.h>

void solve() {
    std::set<int> set;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        set.insert(tmp);
    }
    for (auto i:set) {
        std::cout << i << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}