//
// Created by kdongha on 2020/02/18.
//

#include <bits/stdc++.h>

using namespace std;

int N, M, K, base;
long long bit[1 << 22];
long long lazy[1 << 22];

void setBase() {
    base = 2;
    while (base < N) {
        base <<= 1;
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        cin >> bit[base + i];
    }
    for (int i = base - 1; i >= 1; i--) {
        bit[i] = bit[i * 2] + bit[i * 2 + 1];
    }
}

long long query(int L, int R, int l, int r, int index) {
    if (lazy[index] != 0) {
        bit[index] += lazy[index] * (R - L + 1);
        if (L < R) {
            lazy[index * 2] += lazy[index];
            lazy[index * 2 + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
    int mid = (L + R) / 2;
    if (L == l && R == r) {
        return bit[index];
    } else if (r <= mid) {
        return query(L, mid, l, r, index * 2);
    } else if (l > mid) {
        return query(mid + 1, R, l, r, index * 2 + 1);
    } else {
        return query(L, mid, l, mid, index * 2) + query(mid + 1, R, mid + 1, r, index * 2 + 1);
    }
}

void update(int L, int R, int l, int r, long long value, int index) {
    int mid = (L + R) / 2;
    if (L == l && R == r) {
        lazy[index] += value;
    } else if (r <= mid) {
        bit[index] += value * (r - l + 1);
        update(L, mid, l, r, value, index * 2);
    } else if (l > mid) {
        bit[index] += value * (r - l + 1);
        update(mid + 1, R, l, r, value, index * 2 + 1);
    } else {
        bit[index] += value * (r - l + 1);
        update(L, mid, l, mid, value, index * 2);
        update(mid + 1, R, mid + 1, r, value, index * 2 + 1);
    }
}

void solve() {
    cin >> N >> M >> K;
    setBase();
    init();
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        c--;
        if (a == 1) {
            int d;
            cin >> d;
            update(0, base - 1, b, c, d, 1);
        } else {
            cout << query(0, base - 1, b, c, 1);
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}