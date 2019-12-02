//
// Created by kdongha on 2019/12/02.
//

#include <bits/stdc++.h>

std::string s1, s2, ans;
int dp[1005][1005];

void solve() {
    std::cin >> s1 >> s2;
    int len1 = s1.size();
    int len2 = s2.size();
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            dp[i + 1][j + 1] = std::max(std::max(dp[i + 1][j], dp[i][j + 1]), dp[i][j] + (s1[i] == s2[j] ? 1 : 0));
        }
    }
    std::cout << dp[len1][len2] << "\n";
    ans.resize(dp[len1][len2]);
    int len = dp[len1][len2] - 1;
    while (len1 != 0 || len2 != 0 || len >= 0) {
        if (len1 > 0 && dp[len1][len2] == dp[len1 - 1][len2]) {
            len1--;
        } else if (len2 > 0 && dp[len1][len2] == dp[len1][len2 - 1]) {
            len2--;
        } else if (len1 > 0 && len2 > 0 && dp[len1][len2] - 1 == dp[len1 - 1][len2 - 1]) {
            ans[len--] = s1[len1 - 1];
            len1--;
            len2--;
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