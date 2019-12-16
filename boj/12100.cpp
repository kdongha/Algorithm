//
// Created by kdongha on 2019/12/16.
//

#include <bits/stdc++.h>

int N, max;
int map[20][20];
int cMap[20][20];
int state[5];

void copyMap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cMap[i][j] = map[i][j];
        }
    }
}

void up() {
    bool merge = false;
    std::deque<int> dq;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            if (cMap[i][j] != 0) {
                if (!dq.empty() && dq.back() == cMap[i][j] && !merge) {
                    merge = true;
                    dq.pop_back();
                    dq.push_back(cMap[i][j] * 2);
                } else {
                    merge = false;
                    dq.push_back(cMap[i][j]);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (!dq.empty()) {
                cMap[i][j] = dq.front();
                dq.pop_front();
            } else {
                cMap[i][j]=0;
            }
        }
    }
}

void down() {
    bool merge = false;
    std::deque<int> dq;
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (cMap[i][j] != 0) {
                if (!dq.empty() && dq.back() == cMap[i][j] && !merge) {
                    merge = true;
                    dq.pop_back();
                    dq.push_back(cMap[i][j] * 2);
                } else {
                    merge = false;
                    dq.push_back(cMap[i][j]);
                }
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            if (!dq.empty()) {
                cMap[i][j] = dq.front();
                dq.pop_front();
            } else {
                cMap[i][j]=0;
            }
        }
    }
}

void left() {
    bool merge = false;
    std::deque<int> dq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cMap[i][j] != 0) {
                if (!dq.empty() && dq.back() == cMap[i][j] && !merge) {
                    merge = true;
                    dq.pop_back();
                    dq.push_back(cMap[i][j] * 2);
                } else {
                    merge = false;
                    dq.push_back(cMap[i][j]);
                }
            }
        }
        for (int j = 0; j < N; j++) {
            if (!dq.empty()) {
                cMap[i][j] = dq.front();
                dq.pop_front();
            } else {
                cMap[i][j]=0;
            }
        }
    }
}

void right() {
    bool merge = false;
    std::deque<int> dq;
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (cMap[i][j] != 0) {
                if (!dq.empty() && dq.back() == cMap[i][j] && !merge) {
                    merge = true;
                    dq.pop_back();
                    dq.push_back(cMap[i][j] * 2);
                } else {
                    merge = false;
                    dq.push_back(cMap[i][j]);
                }
            }
        }
        for (int j = N - 1; j >= 0; j--) {
            if (!dq.empty()) {
                cMap[i][j] = dq.front();
                dq.pop_front();
            } else {
                cMap[i][j]=0;
            }
        }
    }
}

void cal() {
    copyMap();
    for (int i = 0; i < 5; i++) {
        switch (state[i]) {
            case 0:
                up();
                break;
            case 1:
                right();
                break;
            case 2:
                down();
                break;
            case 3:
                left();
                break;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            max = std::max(max, cMap[i][j]);
        }
    }
}

void permu(int idx) {
    if (idx == 5) {
        cal();
    } else {
        for (int i = 0; i < 4; i++) {
            state[idx] = i;
            permu(idx + 1);
        }
    }
}

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
        }
    }
    permu(0);
    std::cout << max;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}