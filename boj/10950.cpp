//
// Created by kdongha on 2020/03/07.
//

#include <bits/stdc++.h>

using namespace std;

int T, A, B;

void solve() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        cout << A + B << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}