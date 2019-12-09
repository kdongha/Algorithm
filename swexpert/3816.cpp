//
// Created by kdongha on 2019/12/09.
//

#include <bits/stdc++.h>

int T;

void init(int S1[], int S2[]) {
    for (int i = 0; i < 26; i++) {
        S1[i] = 0;
        S2[i] = 0;
    }
}

int strlen(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void mapping(char str[], int S[], int len) {
    for (int i = 0; i < len; i++) {
        S[str[i] - 'a']++;
    }
}

bool cmp(int S1[], int S2[]) {
    for (int i = 0; i < 26; i++) {
        if (S1[i] != S2[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int ans = 0;
        int S1[26];
        int S2[26];
        init(S1, S2);
        char str1[100005];
        char str2[100005];
        std::cin >> str1 >> str2;
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        mapping(str1, S1, len1);
        mapping(str2, S2, len1);
        if (cmp(S1, S2)) {
            ans++;
        }
        for (int i = len1; i < len2; i++) {
            S2[str2[i] - 'a']++;
            S2[str2[i - len1] - 'a']--;
            if (cmp(S1, S2)) {
                ans++;
            }
        }
        std::cout << "#" << tc << " " << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}