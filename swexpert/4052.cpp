//
// Created by kdongha on 2019/12/19.
//

#include <bits/stdc++.h>

int Tc, N, M;
struct Work {
    int s;
    int e;
    int c;
};
Work work[505];
int cost[10005];

bool operator<(const Work &w1, const Work &w2) {
    if (w1.s != w2.s) {
        return w1.s < w2.s;
    } else {
        return w1.e < w2.e;
    }
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> N >> M;
        for (int i = 0; i < N; i++) {
            int s, e, c;
            std::cin >> s >> e >> c;
            work[i] = {s, e, c};
        }
        for (int i = 0; i <= M; i++) {
            cost[i] = 0;
        }
        std::sort(work, work + N);
        int idx = 0;
        for (int i = 1; i <= M; i++) {
            while (work[idx].s == i) {
                int e = work[idx].e;
                if (e <= M) {
                    cost[e] = std::max(cost[e], cost[i - 1] + work[idx].c);
                }
                idx++;
            }
            cost[i] = std::max(cost[i - 1], cost[i]);
        }
        std::cout << "#" << tc << " " << cost[M] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}