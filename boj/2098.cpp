//
// Created by kdongha on 2020/01/01.
//

#include <bits/stdc++.h>

#define INF 987654321
int N, done;
int W[16][16];
int dp[16][1 << 16];


int getDp(int current, int visit) {
    if (visit == done) {
        if (W[current][0] == 0) {
            return INF;
        } else {
            return W[current][0];
        }
    } else if (dp[current][visit] == -1) {
        dp[current][visit] = INF;
        for (int i = 1; i < N; i++) {
            if ((visit & (1 << i)) == 0 && W[current][i] != 0) {
                dp[current][visit] = std::min(dp[current][visit], getDp(i, visit + (1 << i)) + W[current][i]);
            }
        }
    }
    return dp[current][visit];
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> W[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        int tmp = 1 << N;
        for (int j = 0; j<tmp; j++) {
            dp[i][j] = -1;
        }
    }
    done = (1 << N) - 1;
    std::cout << getDp(0, 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}