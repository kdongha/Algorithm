//
// Created by kdongha on 2019/12/12.
//

#include <bits/stdc++.h>

int Tc, N;
int A[100005];
int tmp[100005];

long long int counting(int l, int r) {
    if (l >= r - 1) {
        return 0;
    } else {
        int m = l + (r - l) / 2;
        long long int cnt = 0;
        cnt += counting(l, m);
        cnt += counting(m, r);
        int left = l, right = m, idx = l;
        while (idx < r) {
            if (left >= m) {
                tmp[idx++] = A[right++];
            } else if (right >= r) {
                tmp[idx++] = A[left++];
            } else {
                if (A[left] <= A[right]) {
                    tmp[idx++] = A[left++];
                } else {
                    cnt += m - left;
                    tmp[idx++] = A[right++];
                }
            }
        }
        for (int i = l; i < r; i++) {
            A[i] = tmp[i];
        }
        return cnt;
    }
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        std::cout << "#" << tc << " " << counting(0, N)<<"\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}