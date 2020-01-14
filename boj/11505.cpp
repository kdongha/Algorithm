//
// Created by kdongha on 2020/01/14.
//

#include <bits/stdc++.h>

#define MOD 1000000007
int N, M, K, base;
long long int bit[1 << 21];

void setBase(int n) {
    int i = 2;
    while (i < n) {
        i <<= 1;
    }
    base = i;
}

void update(int i, int n) {
    i += base;
    bit[i] = n;
    while (i > 1) {
        bit[i >> 1] = (bit[i] * bit[i ^ 1]) % MOD;
        i >>= 1;
    }
}

long query(int L, int R, int l, int r, int idx) {
    int mid = L + (R - L) / 2;
    if (L == l && R == r) {
        return bit[idx];
    } else if (r <= mid) {
        return query(L, mid, l, r, idx * 2);
    } else if (mid < l) {
        return query(mid + 1, R, l, r, idx * 2 + 1);
    } else {
        return (query(L, mid, l, mid, idx * 2) * query(mid + 1, R, mid + 1, r, idx * 2 + 1)) % MOD;
    }
}

void solve() {
    std::cin >> N >> M >> K;
    setBase(N);
    for (int i = 0; i < N; i++) {
        int n;
        std::cin >> n;
        update(i, n);
    }
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        b--;
        if (a == 1) {
            update(b, c);
        } else {
            c--;
            std::cout << query(0, base - 1, b, c, 1) << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}