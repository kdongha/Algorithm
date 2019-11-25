//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

void solve() {
    int cnt = 0;
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.size(); i++) {
        cnt++;
        if (i + 1 < str.size()) {
            if (str[i] == 'c') {
                if (str[i + 1] == '=' || str[i + 1] == '-') {
                    i++;
                }
            } else if (str[i] == 'd') {
                if (str[i + 1] == 'z') {
                    if (i + 2 < str.size() && str[i + 2] == '=') {
                        i += 2;
                    }
                } else if (str[i + 1] == '-') {
                    i++;
                }
            } else if (str[i] == 'l' && str[i + 1] == 'j') {
                i++;
            } else if (str[i] == 'n' && str[i + 1] == 'j') {
                i++;
            } else if (str[i] == 's' && str[i + 1] == '=') {
                i++;
            } else if (str[i] == 'z' && str[i + 1] == '=') {
                i++;
            }
        }
    }
    std::cout << cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}