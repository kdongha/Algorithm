//
// Created by kdongha on 2019/12/03.
//

#include <bits/stdc++.h>

int N;
std::vector<std::string> v;

bool cmp(const std::string &s1, const std::string &s2) {
    std::string cs1(s1);
    std::string cs2(s2);
    while (cs1.size() != cs2.size()) {
        if (cs1.size() < cs2.size()) {
            cs1.append(s1);
        } else {
            cs2.append(s2);
        }
    }
    return cs1 > cs2;
}

void solve() {
    std::cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end(), cmp);
    if (v[0] == "0") {
        std::cout << 0;
    } else {
        for (auto s:v) {
            std::cout << s;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}