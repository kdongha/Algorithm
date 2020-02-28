//
// Created by kdongha on 2020/02/28.
//

#include <bits/stdc++.h>

using namespace std;

int sum, input;

void solve() {
    for (int i = 0; i < 5; i++) {
        cin >> input;
        sum += input * input;
    }
    cout << sum % 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}