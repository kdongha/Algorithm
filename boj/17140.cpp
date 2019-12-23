//
// Created by kdongha on 2019/12/23.
//

#include <bits/stdc++.h>

int r, c, k, size_R, size_C;
int map[105][105];


void R() {
    int max = 0;
    for (int i = 0; i < size_R; i++) {
        std::map<int, int> m;
        for (int j = 0; j < size_C; j++) {
            if (map[i][j] != 0) {
                m[map[i][j]]++;
            }
        }
        std::vector<std::pair<int, int>> v;
        for (auto iter:m) {
            v.push_back({iter.second, iter.first});
        }
        std::sort(v.begin(), v.end());
        for (int j = 0; j < v.size(); j++) {
            map[i][2 * j] = v[j].second;
            map[i][2 * j + 1] = v[j].first;
        }
        for (int j = 2 * v.size(); j < size_R; j++) {
            map[i][j] = 0;
        }
        max = std::max(max, (int) (2 * v.size()));
    }
    size_C = max;
}

void C() {
    int max = 0;
    for (int j = 0; j < size_C; j++) {
        std::map<int, int> m;
        for (int i = 0; i < size_R; i++) {
            if (map[i][j] != 0) {
                m[map[i][j]]++;
            }
        }
        std::vector<std::pair<int, int>> v;
        for (auto iter:m) {
            v.push_back({iter.second, iter.first});
        }
        std::sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            map[2 * i][j] = v[i].second;
            map[2 * i + 1][j] = v[i].first;
        }
        for (int i = 2 * v.size(); i < size_R; i++) {
            map[i][j] = 0;
        }
        max = std::max(max, (int) (2 * v.size()));
    }
    size_R = max;
}

void solve() {
    std::cin >> r >> c >> k;
    --r;
    --c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> map[i][j];
        }
    }
    size_R = 3;
    size_C = 3;
    int time = 0;
    while (time <= 100 && map[r][c] != k) {
        if (size_R >= size_C) {
            R();
        } else {
            C();
        }
        time++;
    }
    if (time > 100) {
        time = -1;
    }
    std::cout << time;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}