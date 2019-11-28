//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int arr[5];

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void print() {
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void solve() {
    for (int i = 0; i < 5; i++) {
        std::cin >> arr[i];
    }
    while (!(arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5)) {
        for (int i = 0; i < 4; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                print();
            }
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