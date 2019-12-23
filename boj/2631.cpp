//
// Created by kdongha on 2019/12/23.
//

#include <bits/stdc++.h>

int N;
int arr[205];
std::vector<int> v;

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        if (v.size() == 0 || v.back() < arr[i]) {
            v.push_back(arr[i]);
        } else {
            int idx = std::lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[idx] = arr[i];
        }
    }
    std::cout << N - v.size();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}