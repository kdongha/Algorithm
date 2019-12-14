//
// Created by kdongha on 2019/12/15.
//

#include <bits/stdc++.h>

int N, L;
int map[105][105];

void solve() {
    std::cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 1;
        int prev = map[i][0];
        bool flag = true;
        for (int j = 1; j < N; j++) {
            if (map[i][j] == prev) {
                cnt++;
            } else if (map[i][j] == prev + 1) {
                if (cnt < L) {
                    flag = false;
                    break;
                } else {
                    cnt = 1;
                    prev = map[i][j];
                }
            } else if (map[i][j] == prev - 1) {
                if (cnt < 0) {
                    flag = false;
                    break;
                } else {
                    cnt = 1 - L;
                    prev = map[i][j];
                }
            } else {
                flag = false;
                break;
            }
        }
        if (flag && cnt >= 0) {
            ans++;
        }
    }
    for (int j = 0; j < N; j++) {
        int cnt = 1;
        int prev = map[0][j];
        bool flag = true;
        for (int i = 1; i < N; i++) {
            if (map[i][j] == prev) {
                cnt++;
            } else if (map[i][j] == prev + 1) {
                if (cnt < L) {
                    flag = false;
                    break;
                } else {
                    cnt = 1;
                    prev = map[i][j];
                }
            } else if (map[i][j] == prev - 1) {
                if (cnt < 0) {
                    flag = false;
                    break;
                } else {
                    cnt = 1 - L;
                    prev = map[i][j];
                }
            } else {
                flag = false;
                break;
            }
        }
        if (flag && cnt >= 0) {
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