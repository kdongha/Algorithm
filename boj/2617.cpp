//
// Created by kdongha on 2020/01/20.
//

#include <bits/stdc++.h>

int N, M;
std::set<int> l[100];
std::set<int> h[100];

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        l[a].insert(b);
        h[b].insert(a);
        for (auto hh:h[a]) {
            l[hh].insert(b);
            for (auto ll:l[b]) {
                l[hh].insert(ll);
            }
            h[b].insert(hh);
        }
        for (auto ll:l[b]) {
            h[ll].insert(a);
            for (auto hh:h[a]) {
                h[ll].insert(hh);
            }
            l[a].insert(ll);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (l[i].size() > (N / 2) || h[i].size() > (N / 2)) {
            ans++;
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