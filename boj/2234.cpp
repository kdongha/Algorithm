//
// Created by kdongha on 2020/01/22.
//

#include <bits/stdc++.h>

int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};

int n, m, count, maxArea;
int map[51][51];
bool visited[51][51];

void initVisited() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = false;
        }
    }
}

bool insideWall(int i, int j, int wall) {
    if (i == 0 && wall == 1) {
        return false;
    }
    if (i == n - 1 && wall == 3) {
        return false;
    }
    if (j == 0 && wall == 0) {
        return false;
    }
    if (j == m - 1 && wall == 2) {
        return false;
    }
    return true;
}

void solve() {
    std::cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                count++;
                int area = 1;
                std::queue<std::pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto current = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ni = current.first + di[d];
                        int nj = current.second + dj[d];
                        if ((map[current.first][current.second] & (1 << d)) == 0 && !visited[ni][nj]) {
                            visited[ni][nj] = true;
                            area++;
                            q.push({ni, nj});
                        }
                    }
                }
                maxArea = std::max(maxArea, area);
            }
        }
    }
    std::cout << count << "\n" << maxArea << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 4; d++) {
                if (insideWall(i, j, d) && (map[i][j] & (1 << d)) != 0) {
                    initVisited();
                    map[i][j] -= (1 << d);
                    int area = 1;
                    std::queue<std::pair<int, int>> q;
                    visited[i][j] = true;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto current = q.front();
                        q.pop();
                        for (int dd = 0; dd < 4; dd++) {
                            int ni = current.first + di[dd];
                            int nj = current.second + dj[dd];
                            if ((map[current.first][current.second] & (1 << dd)) == 0 && !visited[ni][nj]) {
                                visited[ni][nj] = true;
                                area++;
                                q.push({ni, nj});
                            }
                        }
                    }
                    maxArea = std::max(maxArea, area);
                    map[i][j] += (1 << d);
                }
            }
        }
    }
    std::cout << maxArea;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}