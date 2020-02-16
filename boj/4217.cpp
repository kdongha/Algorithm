//
// Created by kdongha on 2020/02/16.
//

#include <bits/stdc++.h>

using namespace std;

int h, w;
bool decode[210][210];
bool visited[210][210];
int mapping[210][210];
vector<bool> check;
char ans[] = {'W', 'A', 'K', 'J', 'S', 'D'};
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool inside(int i, int j) {
    return i >= 0 && i <= h + 1 && j >= 0 && j <= (w + 1) * 4;
}

void solve() {
    int tc = 1;
    while (true) {
        memset(decode, false, sizeof(decode));
        memset(visited, false, sizeof(visited));
        memset(mapping, 0, sizeof(mapping));
        check.clear();
        cin >> h >> w;
        if (h == 0 && w == 0) {
            return;
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                char c;
                int hex;
                cin >> c;
                if (c >= '0' && c <= '9') {
                    hex = c - '0';
                } else {
                    hex = c - 'a' + 10;
                }
                for (int k = 3; k >= 0; k--) {
                    decode[i][j * 4 + k] = hex % 2;
                    hex /= 2;
                }
            }
        }

        queue<pair<int, int>> q;
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j < (w + 1) * 4; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    mapping[i][j] = check.size();
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int ni = current.first + di[d];
                            int nj = current.second + dj[d];
                            if (inside(ni, nj) && !visited[ni][nj] && decode[i][j] == decode[ni][nj]) {
                                visited[ni][nj] = true;
                                mapping[ni][nj] = check.size();
                                q.push({ni, nj});
                            }
                        }
                    }
                    check.push_back(false);
                }
            }
        }
        cout << "Case " << tc++ << ": ";
        vector<char> v;
        check[0] = true;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= h; i++) {
            for (int j = 4; j < (w + 1) * 4; j++) {
                if (!check[mapping[i][j]]) {
                    check[mapping[i][j]] = true;
                    int count = 0;
                    visited[i][j] = true;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> current = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int ni = current.first + di[d];
                            int nj = current.second + dj[d];
                            if (inside(ni, nj) && !visited[ni][nj]) {
                                if (mapping[i][j] == mapping[ni][nj]) {
                                    visited[ni][nj] = true;
                                    q.push({ni, nj});
                                } else if (!check[mapping[ni][nj]]) {
                                    count++;
                                    check[mapping[ni][nj]] = true;
                                }
                            }
                        }
                    }
                    check[mapping[i][j]] = true;
                    v.push_back(ans[count]);
                }
            }
        }
        sort(v.begin(), v.end());
        for (char c:v) {
            cout << c;
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}