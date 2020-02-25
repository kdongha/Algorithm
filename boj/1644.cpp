//
// Created by kdongha on 2020/02/25.
//

#include <bits/stdc++.h>

bool prime[4000005];
std::vector<int> p;
int N;

void initPrime() {
    for (int i = 2; i <= 4000000; i++) {
        prime[i] = true;
    }
    for (int i = 2; i <= 4000000; i++) {
        if (prime[i]) {
            p.push_back(i);
            for (int j = 2 * i; j <= 4000000; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    std::cin >> N;
    initPrime();
    int ans = 0;
    int sum = 0;
    auto left = p.begin();
    auto right = p.begin();
    sum += *right;
    ++right;
    while (left <= right && right != p.end()) {
        if (sum == N) {
            ans++;
        }
        if (sum > N) {
            sum -= *left;
            ++left;
        } else {
            sum += *right;
            ++right;
        }
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}