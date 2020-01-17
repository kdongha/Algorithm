//
// Created by kdongha on 2020/01/17.
//

#include <bits/stdc++.h>

std::string card[10][3];
int n, ans, cnt;
bool hap[10][10][10];
int check[3];

bool combination(std::string a, std::string b, std::string c) {
    if (a == b && b == c) {
        return true;
    } else if (a != b && b != c && c != a) {
        return true;
    } else {
        return false;
    }
}

void initHap(int count, int index) {
    if (count == 3) {
        for (int i = 0; i < 3; i++) {
            if (!combination(card[check[0]][i], card[check[1]][i], card[check[2]][i])) {
                return;
            }
        }
        if (!hap[check[0]][check[1]][check[2]]) {
            cnt++;
            hap[check[0]][check[1]][check[2]] = true;
        }
    } else if (index <= 9) {
        check[count] = index;
        initHap(count + 1, index + 1);
        initHap(count, index + 1);
    }
}

int checkHap(int a, int b, int c) {
    std::vector<int> v = {a, b, c};
    std::sort(v.begin(), v.end());
    if (hap[v[0]][v[1]][v[2]]) {
        hap[v[0]][v[1]][v[2]] = false;
        cnt--;
        return 1;
    } else {
        return -1;
    }
}

void solve() {
    for (int i = 1; i <= 9; i++) {
        std::cin >> card[i][0] >> card[i][1] >> card[i][2];
    }
    initHap(0, 1);
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char order;
        std::cin >> order;
        if (order == 'H') {
            int a, b, c;
            std::cin >> a >> b >> c;
            ans += checkHap(a, b, c);
        } else {
            if (cnt == 0) {
                ans += 3;
                cnt = -1;
            } else {
                ans -= 1;
            }
        }
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}