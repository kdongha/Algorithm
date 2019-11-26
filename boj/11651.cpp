//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

int N;
struct Point {
    int x;
    int y;
};
Point arr[100005];

bool compare(const Point &p1, const Point &p2) {
    if (p1.y == p2.y) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        arr[i] = {x, y};
    }
    std::sort(arr, arr + N, compare);
    for (int i = 0; i < N; i++) {
        std::cout << arr[i].x << " " << arr[i].y << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}