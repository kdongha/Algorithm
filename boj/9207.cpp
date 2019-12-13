//
// Created by kdongha on 2019/12/14.
//

#include <bits/stdc++.h>

int N, cnt, minPin, minMove;
char map[6][10];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

bool inside(int i, int j) {
    return i >= 0 && i < 5 && j >= 0 && j < 9;
}

void jump(int pin, int move) {
    if (pin < minPin) {
        minPin = pin;
        minMove = move;
    } else if (pin == minPin) {
        minMove = minMove < move ? minMove : move;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == 'o') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    int nni = ni + di[d];
                    int nnj = nj + dj[d];
                    if (inside(ni, nj) && map[ni][nj] == 'o' && inside(nni, nnj) && map[nni][nnj] == '.') {
                        map[i][j] = '.';
                        map[ni][nj] = '.';
                        map[nni][nnj] = 'o';
                        jump(pin - 1, move + 1);
                        map[nni][nnj] = '.';
                        map[ni][nj] = 'o';
                        map[i][j] = 'o';
                    }
                }
            }
        }
    }
}

void solve() {
    std::cin >> N;
    while (N--) {
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                std::cin >> map[i][j];
                if (map[i][j] == 'o') {
                    cnt++;
                }
            }
        }
        minPin = cnt;
        minMove = 0;
        jump(cnt, 0);
        std::cout << minPin << " " << minMove << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}