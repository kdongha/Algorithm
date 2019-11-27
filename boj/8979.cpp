//
// Created by kdongha on 2019/11/27.
//

#include <bits/stdc++.h>

struct Country {
    int i;
    int g;
    int s;
    int b;
};

int N, K;
Country arr[1000];

int cmp(const Country &c1, const Country &c2) {
    if (c1.g != c2.g) {
        return c1.g - c2.g;
    } else if (c1.s != c2.s) {
        return c1.s - c2.s;
    } else if (c1.b != c2.b) {
        return c1.b - c2.b;
    } else {
        return 0;
    }
}

void solve() {
    std::cin >> N >> K;
    int k = 0;
    for (int i = 0; i < N; i++) {
        arr[i] = {0, 0, 0, 0};
        std::cin >> arr[i].i >> arr[i].g >> arr[i].s >> arr[i].b;
        if (arr[i].i == K) {
            k = i;
        }
    }
    int rank = 1;
    for (int i = 0; i < N; i++) {
        if (i != k) {
            if (cmp(arr[i], arr[k]) > 0) {
                rank++;
            }
        }
    }
    std::cout << rank;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}