//
// Created by kdongha on 2020/01/05.
//

/*
                U
                0   1   2
                3   4   5
                6   7   8
L               F               R
9   10  11      18  19  20      27  28  29
12  13  14      21  22  23      30  31  32
15  16  17      24  25  26      33  34  35
                D
                36  37  38
                39  40  41
                42  43  44
                B
                45  46  47
                48  49  50
                51  52  53
 */
#include <bits/stdc++.h>

int Tc, n;
char cube[54];
std::deque<char> dq;

void init() {
    std::string color = "wgrbyo";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube[9 * i + j] = color[i];
        }
    }
}

void rotateU() {
    int before[] = {6, 3, 0, 1, 2, 5, 8, 7, 11, 10, 9, 51, 52, 53, 29, 28, 27, 20, 19, 18};
    int after[] = {0, 1, 2, 5, 8, 7, 6, 3, 51, 52, 53, 29, 28, 27, 20, 19, 18, 11, 10, 9};
    for (int b:before) {
        dq.push_back(cube[b]);
    }
    for (int a:after) {
        cube[a] = dq.front();
        dq.pop_front();
    }
}

void rotateD() {
    int before[] = {42, 39, 36, 37, 38, 41, 44, 43, 15, 16, 17, 24, 25, 26, 33, 34, 35, 47, 46, 45};
    int after[] = {36, 37, 38, 41, 44, 43, 42, 39, 24, 25, 26, 33, 34, 35, 47, 46, 45, 15, 16, 17};
    for (int b:before) {
        dq.push_back(cube[b]);
    }
    for (int a:after) {
        cube[a] = dq.front();
        dq.pop_front();
    }
}

void rotateF() {
    int before[] = {24, 21, 18, 19, 20, 23, 26, 25, 17, 14, 11, 6, 7, 8, 27, 30, 33, 38, 37, 36};
    int after[] = {18, 19, 20, 23, 26, 25, 24, 21, 6, 7, 8, 27, 30, 33, 38, 37, 36, 17, 14, 11};
    for (int b:before) {
        dq.push_back(cube[b]);
    }
    for (int a:after) {
        cube[a] = dq.front();
        dq.pop_front();
    }
}

void rotateB() {
    int before[] = {51, 48, 45, 46, 47, 50, 53, 52, 9, 12, 15, 42, 43, 44, 35, 32, 29, 2, 1, 0};
    int after[] = {45, 46, 47, 50, 53, 52, 51, 48, 42, 43, 44, 35, 32, 29, 2, 1, 0, 9, 12, 15};
    for (int b:before) {
        dq.push_back(cube[b]);
    }
    for (int a:after) {
        cube[a] = dq.front();
        dq.pop_front();
    }
}

void rotateL() {
    int before[] = {15, 12, 9, 10, 11, 14, 17, 16, 45, 48, 51, 0, 3, 6, 18, 21, 24, 36, 39, 42};
    int after[] = {9, 10, 11, 14, 17, 16, 15, 12, 0, 3, 6, 18, 21, 24, 36, 39, 42, 45, 48, 51};
    for (int b:before) {
        dq.push_back(cube[b]);
    }
    for (int a:after) {
        cube[a] = dq.front();
        dq.pop_front();
    }
}

void rotateR() {
    int before[] = {33, 30, 27, 28, 29, 32, 35, 34, 26, 23, 20, 8, 5, 2, 53, 50, 47, 44, 41, 38};
    int after[] = {27, 28, 29, 32, 35, 34, 33, 30, 8, 5, 2, 53, 50, 47, 44, 41, 38, 26, 23, 20};
    for (int b:before) {
        dq.push_back(cube[b]);
    }
    for (int a:after) {
        cube[a] = dq.front();
        dq.pop_front();
    }
}

void solve() {
    std::cin >> Tc;
    while (Tc--) {
        init();
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::string order;
            std::cin >> order;
            int times = 1;
            if (order[1] == '-') {
                times = 3;
            }
            switch (order[0]) {
                case 'U':
                    for (int t = 0; t < times; t++) {
                        rotateU();
                    }
                    break;
                case 'D':
                    for (int t = 0; t < times; t++) {
                        rotateD();
                    }
                    break;
                case 'L':
                    for (int t = 0; t < times; t++) {
                        rotateL();
                    }
                    break;
                case 'R':
                    for (int t = 0; t < times; t++) {
                        rotateR();
                    }
                    break;
                case 'F':
                    for (int t = 0; t < times; t++) {
                        rotateF();
                    }
                    break;
                case 'B':
                    for (int t = 0; t < times; t++) {
                        rotateB();
                    }
                    break;
            }
        }
        std::cout << cube[0] << cube[1] << cube[2] << "\n";
        std::cout << cube[3] << cube[4] << cube[5] << "\n";
        std::cout << cube[6] << cube[7] << cube[8] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}