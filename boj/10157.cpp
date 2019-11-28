//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int arr[1000][1000];
int x, y, d, C, R, K;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    std::cin >> C >> R >> K;
    if (K > C * R) {
        std::cout << 0;
    } else {
        x = y = d = 0;
        for (int i = 1; i < C * R; i++) {
            if (i == K) {
                break;
            }
            arr[x][y] = i;
            int nx = x + dx[d];
            int ny = y + dy[d];
            while (nx < 0 || ny < 0 || nx >= R || ny >= C || arr[nx][ny]) {
                d++;
                d %= 4;
                nx = x + dx[d];
                ny = y + dy[d];
            }
            x = nx;
            y = ny;
        }
        std::cout << y + 1 << " " << x + 1;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}