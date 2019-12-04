//
// Created by kdongha on 2019/12/05.
//

#include <bits/stdc++.h>

std::string s;
bool isPalindrome[2505][2505];
int dp[2505];

void init() {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            int l = i, r = j;
            while (s[l++] == s[r--]) {
                if (l >= r) {
                    isPalindrome[i][j] = true;
                    break;
                }
            }
        }
    }
}

void solve() {
    std::cin >> s;
    init();
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < s.size(); i++) {
        dp[i+1] = 0x7fffffff;
        for (int j = 0; j <= i; j++) {
            if (isPalindrome[j][i]) {
                dp[i+1] = std::min(dp[i+1], dp[j] + 1);
            }
        }
    }
    std::cout << dp[s.size()];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}