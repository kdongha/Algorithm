//
// Created by kdongha on 2020/01/28.
//

#include <bits/stdc++.h>

int N, M, K, ans;
int parent[10001];
int cost[10001];

int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void merge(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) {
        if (cost[i] < cost[j]) {
            parent[j] = i;
        } else {
            parent[i] = j;
        }
    }
}

void solve() {
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        std::cin >> cost[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        merge(a, b);
    }
    for (int i = 1; i <= N; i++) {
        if (find(i) == i) {
            ans += cost[i];
            if (K < ans) {
                break;
            }
        }
    }
    if (K >= ans) {
        std::cout << ans;
    } else {
        std::cout << "Oh no";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}