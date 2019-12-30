//
// Created by kdongha on 2019/12/31.
//

#include <bits/stdc++.h>

int N;
int cnt[10];

void count(int num, int mul) {
    while (num) {
        cnt[num % 10] += mul;
        num /= 10;
    }
}

void calc(int a, int b) {
    int mul = 1;
    while (a <= b) {
        while (b % 10 != 9 && a <= b) {
            count(b, mul);
            --b;
        }
        while (a % 10 != 0 && a <= b) {
            count(a, mul);
            ++a;
        }
        if (a <= b) {
            a /= 10;
            b /= 10;
            for (int i = 0; i < 10; i++) {
                cnt[i] += (b - a + 1) * mul;
            }
            mul *= 10;
        }
    }
}

void solve() {
    std::cin >> N;
    calc(1, N);
    for (int i:cnt) {
        std::cout << i << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}