//
// Created by kdongha on 2019/12/18.
//

#include <bits/stdc++.h>

std::string T, P;
int n, m;
int pi[1000005];
std::vector<int> ans;

void setPi() {
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            j = pi[j - 1];
        }
        if (P[i] == P[j]) {
            pi[i] = ++j;
        }
    }
}

void kmp() {
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) {
            j = pi[j - 1];
        }
        if (T[i] == P[j]) {
            ++j;
            if (j == m) {
                j = pi[j - 1];
                ans.push_back(i - m + 2);
            }
        }
    }
}

void solve() {
    std::getline(std::cin, T);
    std::getline(std::cin, P);
    n = T.size();
    m = P.size();
    setPi();
    kmp();
    std::cout << ans.size() << "\n";
    for (auto i:ans) {
        std::cout << i << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}