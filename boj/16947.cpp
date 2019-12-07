//
// Created by kdongha on 2019/12/07.
//

#include <bits/stdc++.h>

std::list<int> list[3005];
int ans[3005];
int visited[3005];
int N, a, b;

void init() {
    for (int i = 1; i <= N; i++) {
        ans[i] = 10000;
        visited[i] = 0;
    }
}

int findCycle(int i, int p) {
    if (visited[i]) {
        return i;
    }
    visited[i] = 1;
    for (auto next: list[i]) {
        if (next != p) {
            int ret = findCycle(next, i);
            if (ret == -2) {
                return -2;
            }
            if (ret >= 0) {
                visited[i] = 2;
                if (ret == i) {
                    return -2;
                } else {
                    return ret;
                }
            }
        }
    }
    return -1;
}

void setDist() {
    std::queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 2) {
            ans[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (auto to:list[from]) {
            if (ans[to] > ans[from] + 1) {
                ans[to] = ans[from] + 1;
                q.push(to);
            }
        }
    }
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    init();
    findCycle(1, 1);
    setDist();
    for (int i = 1; i <= N; i++) {
        std::cout << ans[i] << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}