//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

std::string s;
bool zero = false;
int sum = 0;

void solve() {
    std::cin >> s;
    for (auto c:s) {
        if (!zero && c == '0') {
            zero = true;
        }
        sum += c - '0';
    }
    if (sum % 3 == 0 && zero) {
        std::sort(s.begin(), s.end(), std::greater<char>());
        std::cout << s;
    } else {
        std::cout << -1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}