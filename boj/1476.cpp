//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

void solve() {
    int E, S, M, e, s, m, cnt = 1;
    e = s = m = 0;
    std::cin >> E >> S >> M;
    E--;
    S--;
    M--;
    while (e != E || s != S || m != M) {
        e++;
        e %= 15;
        s++;
        s %= 28;
        m++;
        m %= 19;
        cnt++;
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