//
// Created by kdongha on 2020/01/17.
//

#include <bits/stdc++.h>

#define MAX 1000000000
int N, M, K;
long long int comb[201][201];

void solve() {
    std::cin >> N >> M >> K;
    comb[0][0] = 1;
    for (int i = 1; i <= 200; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if(comb[i][j]>MAX){
                comb[i][j]=MAX;
            }
        }
    }
    int cnt = 0;
    int len = N + M;
    if (comb[len][M] < K) {
        std::cout << -1;
    } else {
        while (cnt < len) {
            if (K <= comb[N + M - 1][M]) {
                std::cout << "a";
                N--;
            } else {
                K -= comb[N + M - 1][M];
                std::cout << "z";
                M--;
            }
            cnt++;
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