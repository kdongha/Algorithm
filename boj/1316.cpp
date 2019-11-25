//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

void solve() {
    int N, ans;
    std::cin >> N;
    ans = N;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        bool c[26];
        std::fill(c, c + 26, false);
        c[str[0]-'a'] = true;
        for (int j = 1; j < str.length(); j++) {
            if (str[j] != str[j - 1]) {
                if (c[str[j]-'a']) {
                    ans--;
                    break;
                } else {
                    c[str[j]-'a'] = true;
                }
            }
        }
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}