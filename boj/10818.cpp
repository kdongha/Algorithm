//
// Created by kdongha on 2020/03/05.
//

#include <bits/stdc++.h>

using namespace std;

int Max, Min, N;

void solve() {
    Max = -1000000;
    Min = 1000000;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        Max = max(Max, temp);
        Min = min(Min, temp);
    }
    cout << Min << " " << Max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}