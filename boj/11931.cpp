//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int N;
int arr[1000005];

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + N, std::greater<int>());
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}