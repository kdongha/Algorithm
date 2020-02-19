//
// Created by kdongha on 2020/02/20.
//

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101];
bool visited[101][101];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int MIN = 200;
int MAX = 0;

bool inside(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool bfs(int val) {
    for (int low = MIN; low <= MAX; low++) {
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] < low || arr[i][j] > low + val) {
                    visited[i][j] = true;
                }
            }
        }

        queue<pair<int, int>> q;
        if (!visited[0][0]) {
            q.push({0, 0});
            visited[0][0] = true;
            while (!q.empty()) {
                auto current = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int ni = current.first + di[d];
                    int nj = current.second + dj[d];
                    if (inside(ni, nj) && !visited[ni][nj]) {
                        if (ni == n - 1 && nj == n - 1) {
                            return true;
                        }
                        q.push({ni, nj});
                        visited[ni][nj] = true;
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            MIN = min(MIN, arr[i][j]);
            MAX = max(MAX, arr[i][j]);
        }
    }
    int low = 0;
    int high = 200;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (bfs(middle)) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    cout << low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}