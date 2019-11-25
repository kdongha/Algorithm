//
// Created by 김동하 on 2019/11/25.
//
#include <bits/stdc++.h>

int arr[1000005];

void solve() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << "\n";
    }
}

int main() {
    solve();
    return 0;
}