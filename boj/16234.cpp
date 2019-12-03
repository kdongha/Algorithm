//
// Created by kdongha on 2019/12/03.
//

#include <bits/stdc++.h>

int N, L, R, ans;
int A[55][55];

bool move() {
    bool flag = false;
    int copy[55][55];
    bool visited[55][55];
    int di[] = {0, 1, 0, -1};
    int dj[] = {1, 0, -1, 0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            copy[i][j] = A[i][j];
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::vector<std::pair<int, int>> v;
            v.push_back({i, j});
            int sum = copy[i][j];
            visited[i][j] = true;
            for (int idx = 0; idx < v.size(); idx++) {
                for (int d = 0; d < 4; d++) {
                    int si = v[idx].first;
                    int sj = v[idx].second;
                    int ni = si + di[d];
                    int nj = sj + dj[d];
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N && !visited[ni][nj] &&
                        std::abs(copy[si][sj] - copy[ni][nj]) >= L && std::abs(copy[si][sj] - copy[ni][nj]) <= R) {
                        visited[ni][nj] = true;
                        sum += copy[ni][nj];
                        v.push_back({ni, nj});
                    }
                }
            }
            if (v.size() > 1) {
                flag = true;
                int avg = sum / v.size();
                for (auto iter = v.begin(); iter != v.end(); iter++) {
                    A[iter->first][iter->second] = avg;
                }
            }
        }
    }
    return flag;
}

void solve() {
    std::cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }
    ans = 0;
    while (move()) {
        ans++;
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}