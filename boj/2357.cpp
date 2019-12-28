//
// Created by kdongha on 2019/12/27.
//

#include <bits/stdc++.h>

int N, M;

struct Bit {
    int minBit[1 << 18];
    int maxBit[1 << 18];
    int size;
    int idx;

    void init() {
        idx = 1;
        while (idx < N) {
            idx <<= 1;
        }
        size = idx * 2;

        for (int i = 1; i <= size; i++) {
            minBit[i] = 1000000001;
            maxBit[i] = 0;
        }
    }

    void update(int i, int value) {
        i += idx;
        minBit[i]=value;
        maxBit[i]=value;
        while (i > 1) {
            minBit[i / 2] = std::min(minBit[i], minBit[i ^ 1]);
            maxBit[i / 2] = std::max(maxBit[i], maxBit[i ^ 1]);
            i >>= 1;
        }
    }

    int minQuery(int L, int R, int l, int r, int i) {
        int m = 1000000001;
        int mid = L + (R - L) / 2;
        if (L == l && R == r) {
            return minBit[i];
        } else if (r <= mid) {
            m = std::min(m, minQuery(L, mid, l, r, 2 * i));
        } else if (l > mid) {
            m = std::min(m, minQuery(mid + 1, R, l, r, 2 * i + 1));
        } else {
            m = std::min(m, minQuery(L, mid, l, mid, 2 * i));
            m = std::min(m, minQuery(mid + 1, R, mid + 1, r, 2 * i + 1));
        }
        return m;
    }

    int maxQuery(int L, int R, int l, int r, int i) {
        int m = 1;
        int mid = L + (R - L) / 2;
        if (L == l && R == r) {
            return maxBit[i];
        } else if (r <= mid) {
            m = std::max(m, maxQuery(L, mid, l, r, 2 * i));
        } else if (l > mid) {
            m = std::max(m, maxQuery(mid + 1, R, l, r, 2 * i + 1));
        } else {
            m = std::max(m, maxQuery(L, mid, l, mid, 2 * i));
            m = std::max(m, maxQuery(mid + 1, R, mid + 1, r, 2 * i + 1));
        }
        return m;
    }
};

Bit bit;

void solve() {
    std::cin >> N >> M;
    bit.init();
    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        bit.update(i, tmp);
    }
    for (int i = 0; i < M; i++) {
        int l, r;
        std::cin >> l >> r;
        --l;
        --r;
        std::cout << bit.minQuery(0, bit.idx - 1, l, r, 1) << " " << bit.maxQuery(0, bit.idx - 1, l, r, 1) << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}