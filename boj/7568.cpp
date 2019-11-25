//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

struct Big {
    int x;
    int y;
    int cnt;
};

void solve() {
    int N;
    std::cin >> N;
    Big arr[N];
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        arr[i] = {x, y, 0};
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i].x > arr[j].x && arr[i].y > arr[j].y) {
                arr[j].cnt++;
            } else if (arr[i].x < arr[j].x && arr[i].y < arr[j].y) {
                arr[i].cnt++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << arr[i].cnt + 1 << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}