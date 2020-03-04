//
// Created by kdongha on 2020/03/04.
//

#include <bits/stdc++.h>

using namespace std;

int h, m;

void solve() {
    cin >> h >> m;
    m -= 45;
    if (m < 0) {
        m += 60;
        h -= 1;
    }
    if (h < 0) {
        h += 24;
    }
    cout << h << " " << m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}