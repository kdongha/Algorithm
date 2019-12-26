//
// Created by kdongha on 2019/12/26.
//

#include <bits/stdc++.h>

int N, R, Q;
std::vector<int> list[100005];
int size[100005];

int makeTree(int cur, int parent) {
    size[cur] = 1;
    for (auto child:list[cur]) {
        if (child != parent) {
            size[cur] += makeTree(child, cur);
        }
    }
    return size[cur];
}

void solve() {
    std::cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    makeTree(R, -1);
    for (int i = 0; i < Q; i++) {
        int q;
        std::cin >> q;
        std::cout << size[q] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}