//
// Created by kdongha on 2020/02/08.
//

#include <bits/stdc++.h>

#define MAX 65536

int N, K;
long long int ans;
int temp[250001];
int bit[MAX << 1];

int find() {
    int i = 1;
    int mid = (K + 1) / 2;
    while (i < MAX) {
        if (bit[i * 2] >= mid) {
            i *= 2;
        } else {
            mid = mid - bit[i * 2];
            i = i * 2 + 1;
        }
    }
    return i - MAX;
}

void set(int i, int val) {
    i += MAX;
    while (i >= 1) {
        bit[i] += val;
        i >>= 1;
    }
}

void solve() {
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> temp[i];
    }
    for (int i = 0; i < K; i++) {
        set(temp[i], 1);
    }
    ans += find();
    for (int i = K; i < N; i++) {
        set(temp[i - K], -1);
        set(temp[i], 1);
        ans += find();
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}