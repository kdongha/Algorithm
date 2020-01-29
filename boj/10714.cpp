//
// Created by kdongha on 2020/01/29.
//

#include <bits/stdc++.h>

int N;
long long int size[2005];
long long int dp[2005][2005];

long long int joi(int l, int r);

long long int ioi(int l, int r);

int left(int i) {
    return (i + 1) % N;
}

int right(int i) {
    return (i - 1 + N) % N;
}

long long int joi(int l, int r) {
    if (left(l) == r) {
        return 0;
    } else if (dp[l][r] == 0) {
        dp[l][r] = size[left(l)] + ioi(left(l), r);
        dp[l][r] = std::max(dp[l][r], size[right(r)] + ioi(l, right(r)));
    }
    return dp[l][r];
}

long long int ioi(int l, int r) {
    if (left(l) == r) {
        return 0;
    } else if (size[left(l)] > size[right(r)]) {
        return joi(left(l), r);
    } else {
        return joi(l, right(r));
    }
}


void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> size[i];
    }
    long long int result = 0;
    for (int i = 0; i < N; i++) {
        result = std::max(result, size[i] + ioi(i, i));
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}