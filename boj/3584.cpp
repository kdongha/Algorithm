//
// Created by kdongha on 2020/01/22.
//

#include <bits/stdc++.h>

int T, N, A, B;
std::vector<int> child[10001];
int parent[10001];
int depth[10001];

void setDepth(int p, int d) {
    depth[p] = d;
    for (auto c:child[p]) {
        setDepth(c, d + 1);
    }
}

void solve() {
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        for (int i = 1; i <= N; i++) {
            parent[i] = 0;
            child[i].clear();
        }
        for (int i = 1; i < N; i++) {
            std::cin >> A >> B;
            parent[B] = A;
            child[A].push_back(B);
        }
        int root=1;
        for (int i = 1; i <= N; i++) {
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }
        setDepth(root, 0);
        std::cin >> A >> B;
        while (A != B) {
            if (depth[A] == depth[B]) {
                A = parent[A];
                B = parent[B];
            } else if (depth[A] > depth[B]) {
                A = parent[A];
            } else {
                B = parent[B];
            }
        }
        std::cout << A << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}