//
// Created by kdongha on 2019/12/03.
//

#include <bits/stdc++.h>

int N;
std::vector<std::string> v;

bool cmp(const std::string &s1, const std::string &s2) {
    auto iter1 = s1.begin();
    auto iter2 = s2.begin();
    while (*iter1 == *iter2) {
        iter1++;
        iter2++;
        if (iter1 == s1.end() && iter2 == s2.end()) {
            return s1.size() < s2.size();
        }
        if (iter1 == s1.end()) {
            iter1--;
        } else if (iter2 == s2.end()) {
            iter2--;
        }
    }
    return *iter1 > *iter2;
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