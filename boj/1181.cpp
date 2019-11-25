//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

bool compare(std::string a, std::string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    } else {
        return a < b;
    }
}

void solve() {
    int N;
    std::cin >> N;
    std::string arr[N];
    std::set<std::string> s;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + N, compare);

    for (int i = 0; i < N; i++) {
        if (i == 0 || arr[i - 1] != arr[i]) {
            std::cout << arr[i] << "\n";
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