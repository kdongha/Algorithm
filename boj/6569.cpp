//
// Created by kdongha on 2020/02/16.
//

#include <bits/stdc++.h>

using namespace std;

int h, w;
long long dp[12 * 12][1 << 11];

long long go(int num, int state) {
    if (num == h * w && state == 0) {
        return 1;
    } else if (num >= h * w) {
        return 0;
    } else {
        long long &ref = dp[num][state];
        if (ref == -1) {
            if (state & 1) {
                ref = go(num + 1, (state >> 1));
            } else {
                ref = go(num + 1, (state >> 1) | (1 << (w - 1)));
                if (num % w != (w - 1) && (state & 2) == 0) {
                    ref += go(num + 2, (state >> 2));
                }
            }
        }
        return ref;
    }
}

void solve() {
    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        } else {
            memset(dp, -1, sizeof(dp));
            cout << go(0, 0) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}