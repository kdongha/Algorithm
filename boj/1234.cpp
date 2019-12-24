//
// Created by kdongha on 2019/12/24.
//

#include <bits/stdc++.h>

int N, R, G, B;
long long int dp[11][101][101][101];
long long int ans;
long long int fac[11];
int perm[3];

int maxNum(int i) {
    return i * (i + 1) / 2;
}

void solve() {
    std::cin >> N >> R >> G >> B;
    fac[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = fac[i - 1] * i;
    }
    dp[1][1][0][0] = R > 0 ? 1 : 0;
    dp[1][0][1][0] = G > 0 ? 1 : 0;
    dp[1][0][0][1] = B > 0 ? 1 : 0;
    ans = dp[1][0][0][1] + dp[1][0][1][0] + dp[1][1][0][0];
    for (int i = 2; i <= N; i++) {
        ans = 0;
        int len = maxNum(i);
        perm[0] = 0;
        perm[1] = 0;
        perm[2] = i;
        do {
            for (int r = perm[0]; r <= R; r++) {
                for (int g = perm[1]; g <= G; g++) {
                    if (r + g > len) {
                        break;
                    }
                    for (int b = perm[2]; b <= B; b++) {
                        if (r + g + b > len) {
                            break;
                        }
                        dp[i][r][g][b] += dp[i - 1][r - perm[0]][g - perm[1]][b - perm[2]];
                        ans += dp[i - 1][r - perm[0]][g - perm[1]][b - perm[2]];
                    }
                }
            }
        } while (std::next_permutation(perm, perm + 3));
        if (i % 2 == 0) {
            perm[0] = 0;
            perm[1] = i / 2;
            perm[2] = i / 2;
            do {
                for (int r = perm[0]; r <= R; r++) {
                    for (int g = perm[1]; g <= G; g++) {
                        if (r + g > len) {
                            break;
                        }
                        for (int b = perm[2]; b <= B; b++) {
                            if (r + g + b > len) {
                                break;
                            }
                            long long int cnt =
                                    fac[i] / fac[i / 2] / fac[i / 2] * dp[i - 1][r - perm[0]][g - perm[1]][b - perm[2]];
                            dp[i][r][g][b] += cnt;
                            ans += cnt;
                        }
                    }
                }
            } while (std::next_permutation(perm, perm + 3));
        }
        if (i % 3 == 0) {
            perm[0] = i / 3;
            perm[1] = i / 3;
            perm[2] = i / 3;
            for (int r = perm[0]; r <= R; r++) {
                for (int g = perm[1]; g <= G; g++) {
                    if (r + g > len) {
                        break;
                    }
                    for (int b = perm[2]; b <= B; b++) {
                        if (r + g + b > len) {
                            break;
                        }
                        long long int cnt =
                                fac[i] / fac[i / 3] / fac[i / 3] / fac[i / 3] *
                                dp[i - 1][r - perm[0]][g - perm[1]][b - perm[2]];
                        dp[i][r][g][b] += cnt;
                        ans += cnt;
                    }
                }
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