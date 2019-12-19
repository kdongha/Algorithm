//
// Created by kdongha on 2019/12/19.
//

#include <bits/stdc++.h>

int Tc, N;
int arr[200005];

bool check(int value) {
    int c = N - 1;
    if (arr[c] >= value) {
        if (arr[c - 1] >= value || arr[c + 1] >= value) {
            return true;
        } else {
            int l = c;
            int r = c;
            while (l - 2 >= 0) {
                if (arr[l - 2] >= value && arr[l - 1] < value) {
                    l -= 2;
                } else {
                    break;
                }
            }
            while (r + 2 <= 2 * N - 1) {
                if (arr[r + 2] >= value && r < 2 * N - 1 && arr[r + 1] < value) {
                    r += 2;
                } else {
                    break;
                }
            }
            int mid = l + (r - l) / 2;
            if (mid == c) {
                if (l == 0) {
                    return true;
                } else if (l > 0 && arr[l - 1] >= value) {
                    return true;
                } else if (r < 2 * N - 1 && arr[r + 1] >= value) {
                    return true;
                }
            } else if (mid > c && l > 0 && arr[l - 1] >= value) {
                return true;
            } else if (mid < c && r < 2 * N - 1 && arr[r + 1] >= value) {
                return true;
            }
            return false;
        }
    } else {
        if (arr[c - 1] >= value && arr[c + 1] >= value) {
            int l = c - 1;
            int r = c + 1;
            while (l - 2 >= 0) {
                if (arr[l - 2] >= value && l > 0 && arr[l - 1] < value) {
                    l -= 2;
                } else {
                    break;
                }
            }
            while (r + 2 <= 2 * N - 1) {
                if (arr[r + 2] >= value && r < 2 * N - 1 && arr[r + 1] < value) {
                    r += 2;
                } else {
                    break;
                }
            }
            int mid = l + (r - l) / 2;
            if (mid == c) {
                if (l == 0) {
                    return true;
                } else if (l > 0 && arr[l - 1] >= value) {
                    return true;
                } else if (r < 2 * N - 1 && arr[r + 1] >= value) {
                    return true;
                }
            } else if (mid > c && l > 0 && arr[l - 1] >= value) {
                return true;
            } else if (mid < c && r < 2 * N - 1 && arr[r + 1] >= value) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> N;
        for (int i = 0; i < 2 * N - 1; i++) {
            std::cin >> arr[i];
        }
        int l = 1;
        int r = 2 * N - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        std::cout << "#" << tc << " " << r << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}