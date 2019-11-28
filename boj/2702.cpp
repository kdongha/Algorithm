//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int T, a, b;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int getGcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (b) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

void solve() {
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b;
        int gcd = getGcd(a, b);
        int lcm = a * b / gcd;
        std::cout << lcm << " " << gcd << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}