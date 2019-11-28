//
// Created by kdongha on 2019/11/28.
//

#include <bits/stdc++.h>

struct Query {
    int num;
    int s;
    int b;
};

bool check(int i) {
    bool arr[10];
    std::fill(arr, arr + 10, false);
    while (i) {
        if (arr[i % 10]) {
            return false;
        } else if (i % 10 == 0) {
            return false;
        }
        arr[i % 10] = true;
        i /= 10;
    }
    return true;
}

int strike(int i, int j) {
    int s = 0;
    while (i && j) {
        if (i % 10 == j % 10) {
            s++;
        }
        i /= 10;
        j /= 10;
    }
    return s;
}

int ball(int i, int j) {
    int b = 0;
    int x = 0;
    while (i) {
        int tmp = j;
        int y = 0;
        while (tmp) {
            if (x != y) {
                if (i % 10 == tmp % 10) {
                    b++;
                    break;
                }
            }
            tmp /= 10;
            y++;
        }
        i /= 10;
        x++;
    }
    return b;
}

int cnt, N;
Query query[105];

void solve() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        query[i] = {0, 0, 0};
        std::cin >> query[i].num >> query[i].s >> query[i].b;
    }
    for (int i = 111; i <= 999; i++) {
        if (check(i)) {
            bool flag = true;
            for (int j = 0; j < N; j++) {
                if (query[j].s != strike(i, query[j].num) || query[j].b != ball(i, query[j].num)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
    }
    std::cout << cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}