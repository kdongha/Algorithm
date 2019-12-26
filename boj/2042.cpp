//
// Created by kdongha on 2019/12/26.
//

#include <bits/stdc++.h>

long long int arr[1000005];
long long int bit[1000005];
int N, M, K;

void update(int b, int c) {
    long long diff = c - arr[b];
    arr[b] = c;
    while (b <= N) {
        bit[b] += diff;
        b += b & -b;
    }
}

long long int sum(int b) {
    long long int ret = 0;
    while (b > 0) {
        ret += bit[b];
        b -= b & -b;
    }
    return ret;
}

void solve() {
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        int tmp;
        std::cin >> tmp;
        update(i, tmp);
    }
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        } else {
            std::cout << sum(c) - sum(b - 1) << "\n";
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