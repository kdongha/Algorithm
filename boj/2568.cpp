//
// Created by kdongha on 2019/12/21.
//

#include <bits/stdc++.h>

int N;
struct Cord {
    int s;
    int e;
};

bool operator<(const Cord &c1, const Cord &c2) {
    return c1.e < c2.e;
}

bool comp(const Cord &c1, const Cord &c2) {
    return c1.s < c2.s;
}

std::vector<Cord> vec;
std::vector<int> ans;
int trace[100005];
bool used[100005];

void solve() {
    std::cin >> N;
    std::vector<Cord> input(N);
    for (int i = 0; i < N; i++) {
        int s, e;
        std::cin >> s >> e;
        input[i] = {s, e};
    }
    std::sort(input.begin(), input.end(), comp);
    for (int i = 0; i < N; i++) {
        if (vec.size() == 0 || vec.back().e < input[i].e) {
            vec.push_back(input[i]);
            trace[i] = vec.size();
        } else {
            auto idx = std::lower_bound(vec.begin(), vec.end(), input[i]);
            *idx = input[i];
            trace[i] = idx - vec.begin() + 1;
        }
    }
    std::cout << N - vec.size() << "\n";
    int i = vec.size();
    int j = N - 1;
    while (i > 0) {
        if (trace[j] == i) {
            used[j] = true;
            --i;
        }
        --j;
    }
    for (i = 0; i < N; i++) {
        if (!used[i]) {
            std::cout << input[i].s << "\n";
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