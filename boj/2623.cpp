//
// Created by kdongha on 2020/01/16.
//

#include <bits/stdc++.h>

int N, M;
int count[1001];
int ans[1001];
std::vector<int> list[1001];
std::queue<int> q;

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int num, prev;
        std::cin >> num >> prev;
        for (int j = 1; j < num; j++) {
            int next;
            std::cin >> next;
            list[prev].push_back(next);
            count[next]++;
            prev = next;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (count[i] == 0) {
            q.push(i);
        }
    }
    int order = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans[order++] = cur;
        for (int next:list[cur]) {
            count[next]--;
            if (count[next] == 0) {
                q.push(next);
            }
        }
    }
    if (order != N) {
        std::cout << 0;
    } else {
        for (int i = 0; i < N; i++) {
            std::cout << ans[i] << "\n";
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