//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

struct Problem {
    int point;
    int idx;
};

Problem arr[8];
int sum;

bool cmpPoint(const Problem &p1, const Problem &p2) {
    return p1.point > p2.point;
}

bool cmpIdx(const Problem &p1, const Problem &p2) {
    return p1.idx < p2.idx;
}

void solve() {
    for (int i = 0; i < 8; i++) {
        int point;
        std::cin >> point;
        arr[i] = {point, i + 1};
    }
    std::sort(arr, arr + 8, cmpPoint);
    for (int i = 0; i < 5; i++) {
        sum += arr[i].point;
    }
    std::sort(arr, arr + 5, cmpIdx);
    std::cout << sum << "\n";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i].idx << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}