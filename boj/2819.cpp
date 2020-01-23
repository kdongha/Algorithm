//
// Created by kdongha on 2020/01/24.
//

#include <bits/stdc++.h>

int N, M, x, y, px, py;
long long int sum;
char order;
int pinX[100005];
int pinY[100005];

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> pinX[i] >> pinY[i];
        sum += std::abs(pinX[i]) + std::abs(pinY[i]);
    }
    std::sort(pinX, pinX + N);
    std::sort(pinY, pinY + N);
    while (M--) {
        std::cin >> order;
        px = x;
        py = y;
        if (order == 'S') {
            y++;
        } else if (order == 'J') {
            y--;
        } else if (order == 'I') {
            x++;
        } else {
            x--;
        }
        if (px < x) {
            int index = std::lower_bound(pinX, pinX + N, x) - pinX;
            sum += index + index - N;
        } else if (x < px) {
            int index = std::upper_bound(pinX, pinX + N, x) - pinX;
            sum += N - index - index;
        }

        if (py < y) {
            int index = std::lower_bound(pinY, pinY + N, y) - pinY;
            sum += index + index - N;
        } else if (y < py) {
            int index = std::upper_bound(pinY, pinY + N, y) - pinY;
            sum += N - index - index;
        }

        std::cout << sum << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}