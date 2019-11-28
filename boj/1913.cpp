//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

int N, K, d;
int arr[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
    std::cin >> N >> K;
    d = 0;
    int x = 0, y = 0, a = 0, b = 0;
    for (int i = N * N; i > 1; i--) {
        arr[x][y] = i;
        if (i == K) {
            a = x;
            b = y;
        }
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (nx < 0 || ny < 0 || nx >= N || ny >= N || arr[nx][ny] != 0) {
            d++;
            d %= 4;
            nx = x + dx[d];
            ny = y + dy[d];
        }
        x = nx;
        y = ny;
    }
    arr[x][y] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << a + 1 << " " << b + 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}