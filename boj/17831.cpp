//
// Created by kdongha on 2020/02/14.
//

#include <bits/stdc++.h>

using namespace std;

int N, val[2000001], dp[2][2000001];
vector<int> tree[2000001];

int go(int n, int chk) {
    int &ret = dp[chk][n];
    if (ret != -1) return ret;
    if (chk == 1) {
        ret = 0;
        for (int nn : tree[n]) {
            ret += go(nn, 0);
        }
    } else {
        ret = 0;
        int a = 0, b = 0;
        for (int nn : tree[n]) {
            a += go(nn, 0);
        }
        for (int nn : tree[n]) {
            b = a - go(nn, 0) + go(nn, 1) + (val[n] * val[nn]);
            ret = max(ret, b);
        }
        ret = max(ret, a);
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
        dp[0][i] = dp[1][i] = -1;
    }
    cout << go(1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}