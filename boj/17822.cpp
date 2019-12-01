//
// Created by kdongha on 2019/12/01.
//

#include <bits/stdc++.h>

int N, M, T, x, d, k;
int circle[55][55];
int copyCircle[55][55];
int pointer[55];

int getPointer(int i, int j) {
    return (pointer[i] + j + M) % M;
}

void check() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            copyCircle[i][j] = circle[i][j];
        }
    }
    int sum = 0, count = 0;
    bool find = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (copyCircle[i][getPointer(i, j)] != 0) {
                sum += copyCircle[i][getPointer(i, j)];
                count++;
                if (copyCircle[i][getPointer(i, j)] == copyCircle[i][getPointer(i, j - 1)]) {
                    circle[i][getPointer(i, j)] = 0;
                    circle[i][getPointer(i, j - 1)] = 0;
                    find = true;
                }
                if (copyCircle[i][getPointer(i, j)] == copyCircle[i][getPointer(i, j + 1)]) {
                    circle[i][getPointer(i, j)] = 0;
                    circle[i][getPointer(i, j + 1)] = 0;
                    find = true;
                }
                if (i > 1 && copyCircle[i][getPointer(i, j)] == copyCircle[i-1][getPointer(i - 1, j)]) {
                    circle[i][getPointer(i, j)] = 0;
                    circle[i-1][getPointer(i - 1, j)] = 0;
                    find = true;
                }
                if (i < N && copyCircle[i][getPointer(i, j)] == copyCircle[i+1][getPointer(i + 1, j)]) {
                    circle[i][getPointer(i, j)] = 0;
                    circle[i+1][getPointer(i + 1, j)] = 0;
                    find = true;
                }
            }
        }
    }
    if (!find) {
        double avr = 1.0*sum / count;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                int score = copyCircle[i][getPointer(i, j)];
                if (score != 0) {
                    if (score > avr) {
                        circle[i][getPointer(i, j)]--;
                    } else if (score < avr) {
                        circle[i][getPointer(i, j)]++;
                    }
                }
            }
        }
    }
}

int sum() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            sum += circle[i][j];
        }
    }
    return sum;
}

void solve() {
    std::cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp;
            std::cin >> tmp;
            circle[i][j] = tmp;
        }
    }
    for (int t = 0; t < T; t++) {
        std::cin >> x >> d >> k;
        for(int i=x;i<=N;i+=x){
            pointer[i] += (d ? 1 : -1) * k + M;
            pointer[i] %= M;
        }
        check();
    }
    std::cout << sum();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}