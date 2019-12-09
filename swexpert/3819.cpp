//
// Created by kdongha on 2019/12/09.
//

#include <bits/stdc++.h>

int T, N;
int A[200005];

void solve() {
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int ans = -1000;
        std::cin >> N;
        std::cin >> A[0];
        for (int i = 1; i < N; i++) {
            int tmp;
            std::cin >> tmp;
            A[i] = A[i - 1] + tmp > tmp ? A[i - 1] + tmp : tmp;
            ans = ans > A[i] ? ans : A[i];
        }
        ans = ans > A[N - 1] ? ans : A[N - 1];
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