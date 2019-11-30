//
// Created by kdongha on 2019/11/30.
//

#include <bits/stdc++.h>

char str[105];
std::vector<int> ret;

void solve() {
    std::cin >> str;
    int cnt = 1;
    int sum = 0;
    for (int s = std::strlen(str)-1; s >=0; s--) {
        sum += (str[s] - '0') * cnt;
        cnt *= 2;
        if (cnt == 8) {
            cnt = 1;
            ret.push_back(sum);
            sum = 0;
        }
    }
    if (sum != 0) {
        ret.push_back(sum);
    }
    for (int s = ret.size()-1; s >= 0; s--) {
        std::cout<<ret[s];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}