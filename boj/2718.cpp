//
// Created by kdongha on 2020/01/04.
//

#include <bits/stdc++.h>

int T, N;
int dp[1001][5];

int getDp(int n, int state) {
    if (n < 0) return 0;
    if (n == 0) return state == 0;
    if (dp[n][state] == -1) {
        dp[n][state]=0;
        if(state==0){
            dp[n][state]+=getDp(n-1,0);
            dp[n][state]+=getDp(n-1,1);
            dp[n][state]+=getDp(n-1,3);
            dp[n][state]+=getDp(n-1,4);
            dp[n][state]+=getDp(n-2,0);
        }else if(state==1){
            dp[n][state]+=getDp(n-1,0);
            dp[n][state]+=getDp(n-1,4);
        }else if(state==2){
            dp[n][state]+=getDp(n-1,3);
        }else if(state==3){
            dp[n][state]+=getDp(n-1,0);
            dp[n][state]+=getDp(n-1,2);
        }else{
            dp[n][state]+=getDp(n-1,0);
            dp[n][state]+=getDp(n-1,1);
        }
    }
    return dp[n][state];
}

void solve() {
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < 5; j++) {
                dp[i][j] = -1;
            }
        }
        std::cout << getDp(N, 0) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}