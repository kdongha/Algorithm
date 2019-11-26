//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

int M, n;
bool set[21];
std::string s;

void solve() {
    std::cin >> M;
    while (M--) {
        std::cin >> s;
        if (s == "all") {
            for (int i = 1; i <= 20; i++) {
                set[i] = true;
            }
        } else if (s == "empty") {
            for (int i = 1; i <= 20; i++) {
                set[i] = false;
            }
        } else {
            std::cin >> n;
            if (s == "add") {
                set[n] = true;
            } else if (s == "check") {
                if (set[n]) {
                    std::cout << "1" << "\n";
                } else {
                    std::cout << "0" << "\n";
                }
            } else if (s == "remove") {
                set[n] = false;
            } else if (s == "toggle") {
                set[n] = !set[n];
            }
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