//
// Created by kdongha on 2020/03/01.
//

#include <bits/stdc++.h>

using namespace std;

int N;

void pre(int level, int cur, int n) {
    if (level == 1) {
        cout << cur<<" ";
    } else {
        int start = (1 << n) - (1 << (n - level + 1));
        int lmax = (1 << (n - level));
        cout << lmax - cur + 1 + start << " ";
        pre(level - 1, cur, n);
        pre(level - 1, cur + (1 << (n - level)), n);
    }
}

void solve() {
    cin >> N;
    pre(N, 1, N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}