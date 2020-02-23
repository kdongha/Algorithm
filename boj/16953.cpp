//
// Created by kdongha on 2020/02/23.
//

#include <bits/stdc++.h>

using namespace std;

long long A, B, ans;

void solve() {
    cin >> A >> B;
    queue<pair<long long, int>> q;
    ans = -1;
    q.push({A, 1});
    while (!q.empty()) {
        pair<long long, int> cur = q.front();
        q.pop();
        if (cur.first == B) {
            ans = cur.second;
            break;
        } else {
            if (cur.first * 2 <= B) {
                q.push({cur.first * 2, cur.second + 1});
            }
            if (cur.first * 10 + 1 <= B) {
                q.push({cur.first * 10 + 1, cur.second + 1});
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}