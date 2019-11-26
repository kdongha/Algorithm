//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

int N, M;
std::set<std::string> s1, s2;

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        s1.insert(s);
    }
    for (int i = 0; i < M; i++) {
        std::string s;
        std::cin >> s;
        if (s1.find(s) != s1.end()) {
            s2.insert(s);
        }
    }
    std::cout<<s2.size()<<"\n";
    for (auto s:s2) {
        std::cout << s << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}