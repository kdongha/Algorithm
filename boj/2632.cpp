//
// Created by kdongha on 2020/01/08.
//

#include <bits/stdc++.h>

int S, m, n, ans;
int cntA[2000005];
int cntB[2000005];
int A[1005];
int B[1005];

void solve() {
    std::cin >> S >> m >> n;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        std::cin >> A[i];
        sum += A[i];
    }
    cntA[sum] = 1;
    sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
        sum += B[i];
    }
    cntB[sum] = 1;
    for (int i = 0; i < m; i++) {
        sum = A[i];
        cntA[sum]++;
        for (int j = 1; j < m - 1; j++) {
            sum += A[(i + j) % m];
            if (sum > S) {
                break;
            } else {
                cntA[sum]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sum = B[i];
        cntB[sum]++;
        for (int j = 1; j < n - 1; j++) {
            sum += B[(i + j) % n];
            if (sum > S) {
                break;
            } else {
                cntB[sum]++;
            }
        }
    }
    ans = cntA[S] + cntB[S];
    for (int i = 1; i < S; i++) {
        ans += cntA[i] * cntB[S - i];
    }
    std::cout<<ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}