//
// Created by kdongha on 2019/12/16.
//

#include <bits/stdc++.h>

int T;
char str[500005];
char pattern[100005];
int pi[100005];

int strlen(char *arr) {
    int len = 0;
    while (*(arr + len) != '\0') {
        len++;
    }
    return len;
}

void setPi() {
    int len = strlen(pattern);
    for (int i = 0; i < len; i++) {
        pi[i] = 0;
    }
    int j = 0;
    for (int i = 1; i < len; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }
}

int kmp() {
    int len1 = strlen(str);
    int len2 = strlen(pattern);
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < len1; i++) {
        while (j > 0 && str[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (str[i] == pattern[j]) {
            if (j == len2 - 1) {
                cnt++;
                j = pi[j];
            } else {
                j++;
            }
        }
    }
    return cnt;
}


void solve() {
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> str;
        std::cin >> pattern;
        setPi();
        std::cout << "#" << t << " " << kmp() << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}