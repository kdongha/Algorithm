//
// Created by kdongha on 2019/11/30.
//

#include <bits/stdc++.h>

int K;
int arr[55];

void solve() {
    std::cin >> K;
    for (int x = 0; x < K; x++) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::sort(arr, arr + n, std::greater<int>());
        int gap = 0;
        for (int j = 0; j < n - 1; j++) {
            gap = std::max(gap, arr[j] - arr[j + 1]);
        }
        std::cout << "Class " << x + 1 << "\n";
        std::cout << "Max " << *arr << ", Min " << *(arr + n - 1) << ", Largest gap "<<gap<<"\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}