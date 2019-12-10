//
// Created by kdongha on 2019/12/10.
//

#include <bits/stdc++.h>

#define MOD 1000000007

struct rail {
    int a;
    int b;
};

int Tc, n, a, b;
rail arr[200005];
rail tmp[200005];

bool operator<(const rail &r1, const rail &r2) {
    long v1 = 1l * (r1.a + r1.b) * r2.a + r2.b;
    long v2 = 1l * (r2.a + r2.b) * r1.a + r1.b;
    return v1 < v2;
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        int i1 = l;
        int i2 = m + 1;
        int idx = l;
        while (i1 <= m || i2 <= r) {
            if (i1 > m) {
                tmp[idx++] = arr[i2++];
            } else if (i2 > r) {
                tmp[idx++] = arr[i1++];
            } else if (arr[i1] < arr[i2]) {
                tmp[idx++] = arr[i1++];
            } else {
                tmp[idx++] = arr[i2++];
            }
        }
        for (int i = l; i <= r; i++) {
            arr[i] = tmp[i];
        }
    }
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a >> b;
            arr[i] = {a, b};
        }
        mergeSort(0, n - 1);
        long ans = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans * arr[i].a) % MOD + arr[i].b;
            ans %= MOD;
        }
        std::cout << "#" << tc << " " << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}