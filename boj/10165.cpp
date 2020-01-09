//
// Created by kdongha on 2020/01/09.
//

#include <bits/stdc++.h>

struct Line {
    int i;
    int s;
    int e;
};

bool operator<(const Line &l1, const Line &l2) {
    if (l1.s != l2.s) {
        return l1.s < l2.s;
    } else {
        return l1.e > l2.e;
    }
}

int N, M, a, b, irra, irrb;
Line line[500005];

void solve() {
    std::cin >> N >> M;
    irra = N;
    irrb = 0;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        if (a > b) {
            irra = std::min(irra, a);
            irrb = std::max(irrb, b);
            b += N;
        }
        line[i] = {i + 1, a, b};
    }
    std::sort(line, line + M);
    int last = -1;
    std::vector<int> v;
    for (int i = 0; i < M; i++) {
        if (last < line[i].e && (line[i].e >= N || (irrb < line[i].e && irra > line[i].s))) {
            v.push_back(line[i].i);
            last = line[i].e;
        }
    }
    std::sort(v.begin(), v.end());
    for (int n:v) {
        std::cout << n << " ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}