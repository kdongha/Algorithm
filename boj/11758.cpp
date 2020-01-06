//
// Created by kdongha on 2020/01/06.
//

#include <iostream>

int x1, x2, x3, y1, y2, y3, ans;

void solve() {
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int S = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (S > 0) {
        ans = 1;
    } else if (S < 0) {
        ans = -1;
    } else {
        ans = 0;
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