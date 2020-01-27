//
// Created by kdongha on 2020/01/28.
//

#include <bits/stdc++.h>

int N;
int cost[501];
int preCost[501];
int conn[501];
std::vector<int> next[501];
std::queue<int> q;

void solve() {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> cost[i];
        while (true) {
            int pre;
            std::cin >> pre;
            if (pre == -1) {
                break;
            } else {
                next[pre].push_back(i);
                conn[i]++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (conn[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int pre = q.front();
        q.pop();
        cost[pre] += preCost[pre];
        for (auto n:next[pre]) {
            preCost[n] = std::max(preCost[n], cost[pre]);
            conn[n]--;
            if (conn[n] == 0) {
                q.push(n);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        std::cout << cost[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}