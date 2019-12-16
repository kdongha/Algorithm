//
// Created by kdongha on 2019/12/16.
//

#include <bits/stdc++.h>

char map[5][5];
bool seven[5][5];
int cnt = 0;
bool check[5][5];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int t=0;

void combi(int idx, int S, int Y) {
    if (S + Y == 7) {
        t++;
        int adj = 0;
        int x = -1;
        int y = -1;
        for (int i = 0; i < 5 && x == -1; i++) {
            for (int j = 0; j < 5 && x == -1; j++) {
                if (seven[i][j]) {
                    x = i;
                    y = j;
                }
            }
        }
        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                check[i][j] = false;
            }
        }
        check[x][y] = true;
        adj = 1;
        while (!q.empty()) {
            std::pair<int, int> p = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = p.first + di[d];
                int ny = p.second + dj[d];
                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !check[nx][ny] && seven[nx][ny]) {
                    adj++;
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        if (adj == 7) {
            cnt++;
        }
    } else if (idx >= 25) {
        return;
    } else {
        seven[idx / 5][idx % 5] = true;
        if (map[idx / 5][idx % 5] == 'Y' && Y < 3) {
            combi(idx + 1, S, Y + 1);
        } else if (map[idx / 5][idx % 5] == 'S') {
            combi(idx + 1, S + 1, Y);
        }
        seven[idx / 5][idx % 5] = false;
        combi(idx + 1, S, Y);
    }
}

void solve() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> map[i][j];
        }
    }
    combi(0, 0, 0);
    std::cout << cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}