//
// Created by kdongha on 2020/03/03.
//

#include <bits/stdc++.h>

using namespace std;

int y, ret;

void solve() {
    cin >> y;
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        ret = 1;
    }
    cout << ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}