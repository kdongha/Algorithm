//
// Created by kdongha on 2020/01/03.
//

#include <bits/stdc++.h>

int Tc, M, A, ans;

struct BC {
    int i;
    int j;
    int c;
    int p;

};

bool operator<(const BC &bc1, const BC &bc2) {
    return bc1.p > bc2.p;
}

BC bc[8];
int di[] = {0, 0, 1, 0, -1};
int dj[] = {0, -1, 0, 1, 0};
int Ai, Aj, Bi, Bj;
int Ad[101];
int Bd[101];

bool inside(const BC &bc, int i, int j) {
    int d = std::abs(i - bc.i) + std::abs(j - bc.j);
    return d <= bc.c;
}

bool compare(const BC &bc1, const BC &bc2) {
    return bc1.i == bc2.i && bc1.j == bc2.j;
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        ans = 0;
        Ai = Aj = 1;
        Bi = Bj = 10;
        std::cin >> M >> A;
        for (int i = 0; i < M; i++) {
            std::cin >> Ad[i];
        }
        for (int i = 0; i < M; i++) {
            std::cin >> Bd[i];
        }
        for (int i = 0; i < A; i++) {
            std::cin >> bc[i].i >> bc[i].j >> bc[i].c >> bc[i].p;
        }
        for (int t = 0; t <= M; t++) {
            std::vector<BC> Av, Bv;
            for (int i = 0; i < A; i++) {
                if (inside(bc[i], Ai, Aj)) {
                    Av.push_back(bc[i]);
                }
                if (inside(bc[i], Bi, Bj)) {
                    Bv.push_back(bc[i]);
                }
            }
            std::sort(Av.begin(), Av.end());
            std::sort(Bv.begin(), Bv.end());
            if (Av.size() > 0 && Bv.size() > 0) {
                if (compare(Av[0], Bv[0])) {
                    ans += Av[0].p;
                    if (Av.size() > 1 && Bv.size() > 1) {
                        if (Av[1].p > Bv[1].p) {
                            ans += Av[1].p;
                        } else {
                            ans += Bv[1].p;
                        }
                    } else if (Av.size() > 1) {
                        ans += Av[1].p;
                    } else if (Bv.size() > 1) {
                        ans += Bv[1].p;
                    }
                } else {
                    ans += Av[0].p;
                    ans += Bv[0].p;
                }
            } else if (Av.size() > 0) {
                ans += Av[0].p;
            } else if (Bv.size() > 0) {
                ans += Bv[0].p;
            }
            Ai += di[Ad[t]];
            Aj += dj[Ad[t]];
            Bi += di[Bd[t]];
            Bj += dj[Bd[t]];
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