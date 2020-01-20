//
// Created by kdongha on 2020/01/21.
//

#include <bits/stdc++.h>

int n, m, ans;
struct Bus {
    int t;
    int p;
};
Bus bus[101];
struct Stop {
    int t;
    int order;
};
std::deque<Stop> q;

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> bus[i].t >> bus[i].p;
    }
    int idx = 1;
    int t = 0;
    while (++t) {
        while (!q.empty()) {
            if (q.front().t <= t) {
                q.pop_front();
            } else {
                break;
            }
        }
        while (q.empty() || q.back().order < n) {
            if (bus[idx].t <= t) {
                if (idx == m) {
                    if (q.empty()) {
                        ans = 1;
                    } else {
                        ans = q.back().order + 1;
                    }
                    t=-1;
                    break;
                }
                if (q.empty()) {
                    q.push_back({t + bus[idx].p, 1});
                } else {
                    q.push_back({t + bus[idx].p, q.back().order + 1});
                }
                idx++;
            } else {
                break;
            }
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