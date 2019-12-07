//
// Created by kdongha on 2019/12/06.
//

#include <bits/stdc++.h>

int N, input;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

void solve() {
    std::cin >> N;
    while (N--) {
        std::cin >> input;
        if (input > 0) {
            pq.push(input);
        } else {
            if (pq.empty()) {
                std::cout << "0\n";
            } else {
                std::cout << pq.top() << "\n";
                pq.pop();
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