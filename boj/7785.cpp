//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

std::set<std::string> s;

int n;

void solve() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string name, state;
        std::cin >> name >> state;
        if (state == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }
    for (auto rit = s.rbegin(); rit != s.rend(); rit++) {
        std::cout << *rit << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}