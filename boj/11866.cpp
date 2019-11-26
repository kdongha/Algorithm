//
// Created by kdongha on 2019/11/26.
//

#include <bits/stdc++.h>

int N, K;

void solve() {
    std::cin >> N >> K;
    std::queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    K--;
    std::cout << '<';
    while (q.size() > 1) {
        int k = K % q.size();
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front() << ", ";
        q.pop();
    }
    std::cout << q.front() << '>';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}