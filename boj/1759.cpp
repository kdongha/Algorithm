//
// Created by kdongha on 2019/11/29.
//

#include <bits/stdc++.h>

int L, C;
char arr[15];
char pwd[15];

int findVowel() {
    int cnt = 0;
    for (auto c:pwd) {
        if (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u') {
            cnt++;
        }
    }
    return cnt;
}

void comb(int idx, int count, int push) {
    if (count == push) {
        int vowel = findVowel();
        if (vowel >= 1 && L - vowel >= 2) {
            for (auto c = pwd; c < pwd + count; c++) {
                std::cout << *c;
            }
            std::cout << "\n";
        }
    } else if (idx < C) {
        pwd[push] = arr[idx];
        comb(idx + 1, count, push + 1);
        comb(idx + 1, count, push);
    }
}

void solve() {
    std::cin >> L >> C;
    for (int i = 0; i < C; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + C);
    comb(0, L, 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}