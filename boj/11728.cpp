//
// Created by kdongha on 2019/11/27.
//

#include <bits/stdc++.h>

void solve() {

    int N, M;
    std::cin >> N >> M;
    std::vector<int> v(N + M);
    for (int i = 0; i < N + M; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    for (auto i:v) {
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