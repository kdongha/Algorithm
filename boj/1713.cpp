//
// Created by kdongha on 2019/12/30.
//

#include <bits/stdc++.h>

int N, C;
int rec[101];
std::deque<int> dq;

void solve() {
    std::cin >> N >> C;
    for (int i = 0; i < C; i++) {
        int tmp;
        std::cin >> tmp;
        if (rec[tmp] == 0) {
            if (dq.size() == N) {
                auto er = dq.begin();
                for (auto iter = dq.begin(); iter != dq.end(); iter++) {
                    if (rec[*er] > rec[*iter]) {
                        er = iter;
                    }
                }
                rec[*er] = 0;
                dq.erase(er);
            }
            dq.push_back(tmp);
        }
        rec[tmp]++;
    }
    std::sort(dq.begin(), dq.end());
    for (int i:dq) {
        std::cout << i << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}