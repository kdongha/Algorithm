//
// Created by kdongha on 2020/02/07.
//

#include <bits/stdc++.h>

long long int min, max;
int ans;
bool powNum[1000005];

void solve() {
    std::cin >> min >> max;
    for (long long int i = 2; i * i <= max; i++) {
        long long int ii = i * i;
        long long int j = (ii - min % ii) % ii;
        for (long long int k = j; k <= max - min; k += ii) {
            powNum[k] = true;
        }
    }
    for (int i = 0; i <= (max - min); i++) {
        if (!powNum[i]) {
            ans++;
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