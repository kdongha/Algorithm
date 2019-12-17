//
// Created by kdongha on 2019/12/17.
//

#include <bits/stdc++.h>

int t, n;
int x[105];
int y[105];
bool visited[105];
bool map[105][105];

void init() {
    for (int i = 0; i < n + 2; i++) {
        visited[i] = false;
        for (int j = 0; j < n + 2; j++) {
            map[i][j] = false;
        }
    }
}

void solve() {
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        init();
        for (int i = 0; i < n + 2; i++) {
            std::cin >> x[i] >> y[i];
        }
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                if (i != j && std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) <= 1000) {
                    map[i][j] = true;
                    map[j][i] = true;
                }
            }
        }
        std::queue<int> q;
        visited[0] = true;
        q.push(0);
        bool flag = false;
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            if (s == n + 1) {
                flag = true;
                break;
            }
            for (int i = 0; i < n + 2; i++) {
                if (map[s][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        if (flag) {
            std::cout << "happy\n";
        } else {
            std::cout << "sad\n";
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