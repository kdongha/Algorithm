//
// Created by kdongha on 2019/12/17.
//

#include <bits/stdc++.h>

int T;
char str[1000005];
int pi[1000005];

int strlen() {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void setPi(int len) {
    int j = 0;
    for (int i = 1; i < len; i++) {
        pi[i] = 0;
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j]) {
            pi[i] = ++j;
        }
    }
}

void solve() {
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> str;
        int len = strlen();
        setPi(len);
        int size = len - pi[len - 1];
        if (len % size == 0) {
            std::cout << "#" << t << " " << (len / size) << "\n";
        } else {
            std::cout << "#" << t << " " << 1 << "\n";
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