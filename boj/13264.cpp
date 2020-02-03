//
// Created by kdongha on 2020/02/04.
//

#include <bits/stdc++.h>

std::string str;
int N,d;
int sa[100005], pos[100005];

bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i += d;
    j += d;
    if (i < N && j < N) {
        return pos[i] < pos[j];
    } else {
        return i > j;
    }
}

void solve() {
    std::cin >> str;
    N = str.length();
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        pos[i] = str[i];
    }
    for (d = 1;; d *= 2) {
        std::sort(sa, sa + N, cmp);
        int temp[100005] = {0,};
        for (int i = 0; i < N - 1; i++) {
            temp[i + 1] = temp[i] + cmp(sa[i], sa[i + 1]);
        }
        for (int i = 0; i < N; i++) {
            pos[sa[i]] = temp[i];
        }
        if (temp[N - 1] == N - 1) {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << sa[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}