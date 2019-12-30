//
// Created by kdongha on 2019/12/31.
//

#include <bits/stdc++.h>

int Tc, N, ans;
bool check[10001];

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        for (int i = 0; i <= 10000; i++) {
            check[i] = false;
        }
        ans = 1;
        check[0] = true;
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            int score;
            std::cin >> score;
            for (int s = 10000; s >= 0; s--) {
                if (check[s] && !check[s + score]) {
                    check[s + score] = true;
                    ans++;
                }
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