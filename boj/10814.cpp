//
// Created by kdongha on 2019/11/25.
//

#include <bits/stdc++.h>

struct Person {
    int years;
    std::string name;
};

bool compare(const Person &p1, const Person &p2) {
    if (p1.years != p2.years) {
        return p1.years < p2.years;
    } else {
        return false;
    }
}

void solve() {
    int N;
    std::cin >> N;
    Person arr[N];
    for (int i = 0; i < N; i++) {
        int years;
        std::string name;
        std::cin >> years >> name;
        arr[i] = {years, name};
    }
    std::stable_sort(arr, arr + N, compare);
    for (int i = 0; i < N; i++) {
        std::cout << arr[i].years << " " + arr[i].name + "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}