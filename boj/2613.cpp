//
// Created by kdongha on 2019/12/20.
//

#include <bits/stdc++.h>

int N, M;
int arr[305];

int group(int value) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (sum + arr[i] <= value) {
            sum += arr[i];
        } else if (arr[i] <= value) {
            sum = arr[i];
            ++cnt;
        } else {
            return 301;
        }
    }
    return cnt;
}

void solve() {
    std::cin >> N >> M;
    int l = 1;
    int r = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        r += arr[i];
    }
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (group(mid) <= M) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << "\n";
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < N && M != N - i + 1; i++) {
        if (sum + arr[i] <= l) {
            sum += arr[i];
            cnt += 1;
        } else {
            std::cout << cnt << " ";
            --M;
            cnt = 1;
            sum = arr[i];
        }
    }
    std::cout << cnt << " ";
    for (int i = 1; i < M; i++) {
        std::cout << "1 ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}