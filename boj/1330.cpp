//
// Created by kdongha on 2020/03/02.
//

#include <bits/stdc++.h>

using namespace std;

int A, B;

void solve() {
    cin >> A >> B;
    if (A > B) {
        cout << ">";
    } else if (A < B) {
        cout << "<";
    } else {
        cout << "==";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}