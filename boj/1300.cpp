//
// Created by kdongha on 2020/03/06.
//

#include <bits/stdc++.h>

using namespace std;

long long N, K;

void solve() {
    cin >> N >> K;
    long long low = 1;
    long long high = N * N;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long cnt = 0;
        for (long long i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }
        if (cnt >= K) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}