//
// Created by kdongha on 2019/12/12.
//

#include <bits/stdc++.h>

int tc, n, d, c, cnt, t;
struct spread {
    int target;
    int time;
};
std::vector<spread> vec[10005];
bool check[10005];
std::priority_queue<spread> pq;

bool operator<(const spread &s1, const spread &s2) {
    return s1.time > s2.time;
}

void solve() {
    std::cin >> tc;
    while (tc--) {
        std::cin >> n >> d >> c;
        for (int i = 1; i <= n; i++) {
            vec[i].clear();
            check[i] = false;
        }
        for (int i = 0; i < d; i++) {
            int a, b, s;
            std::cin >> a >> b >> s;
            vec[b].push_back({a, s});
        }
        cnt = 1;
        t = 0;
        check[c] = true;
        for (auto s:vec[c]) {
            pq.push(s);
        }
        while (!pq.empty()) {
            spread s = pq.top();
            pq.pop();
            if (!check[s.target]) {
                cnt++;
                t = s.time;
                check[s.target] = true;
                for (auto next:vec[s.target]) {
                    pq.push({next.target, next.time + s.time});
                }
            }
        }
        std::cout << cnt << " " << t << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}