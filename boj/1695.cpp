//
// Created by kdongha on 2019/12/10.
//

#include <bits/stdc++.h>

int N;
int arr[5005];
int dp[5005][5005];

int getDp(int i, int j) {
    if (dp[i][j] < 0) {
        if (i >= j) {
            dp[i][j] = 0;
        } else {
            if (arr[i] == arr[j]) {
                dp[i][j] = getDp(i + 1,j - 1);
            } else {
                dp[i][j] = std::min(getDp(i + 1, j), getDp(i, j - 1)) + 1;
            }
        }
    }
    return dp[i][j];
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    std::cout << getDp(0, N - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}