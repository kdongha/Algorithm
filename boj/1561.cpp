//
// Created by kdongha on 2020/01/29.
//

#include <bits/stdc++.h>

int N, M;
int t[10000];

void solve() {
    std::cin >> N >> M;
    if (N <= M) {
        std::cout << N;
        return;
    }
    for (int i = 0; i < M; i++) {
        std::cin >> t[i];
    }
    long long int left, right, result;
    right = 1L * 30 * N;
    left = 0;
    while (left <= right) {
        long long int mid = (left + right) / 2;
        long long int sum = M;
        for (int i = 0; i < M; i++) {
            sum += mid / t[i];
            if (sum >= N) {
                break;
            }
        }
        if (sum >= N) {
            result=mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    int sum = M;
    for (int i = 0; i < M; i++) {
        sum += (result - 1) / t[i];
    }
    for (int i = 0; i < M; i++) {
        if (left % t[i] == 0) {
            sum++;
        }
        if (sum == N) {
            std::cout << i + 1;
            return;
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