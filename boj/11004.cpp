//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

int N, K;
int arr[5000005];

void solve() {
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + N);
    std::cout << arr[K-1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}