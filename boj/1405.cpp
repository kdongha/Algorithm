//
// Created by kdongha on 2020/02/26.
//

#include <bits/stdc++.h>

using namespace std;

int N;
long double ans;
int dir[4];
bool visited[29][29];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void go(int n, int x, int y, long double p) {
    if (n > N) {
        return;
    } else if (visited[x][y]) {
        ans -= p;
        return;
    } else {
        visited[x][y] = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            long double np = p * dir[d] / 100;
            go(n + 1, nx, ny, np);
        }
        visited[x][y] = false;
    }
}

void solve() {
    cin >> N;
    for (int d = 0; d < 4; d++) {
        cin >> dir[d];
    }
    ans = 1;
    go(0, N, N, 1);
    cout.precision(11);
    cout.fixed;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}