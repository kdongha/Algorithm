//
// Created by kdongha on 2019/12/01.
//

#include <bits/stdc++.h>

int F, S, G, U, D;
int arr[1000005];
std::queue<int> q;

void solve() {
    std::cin >> F >> S >> G >> U >> D;
    std::fill(arr, arr + F + 1, 0x7fffffff);
    q.push(S);
    arr[S] = 0;
    while (!q.empty()) {
        int u = q.front() + U;
        int d = q.front() - D;
        int count = arr[q.front()] + 1;
        q.pop();
        if (u <= F && arr[u] > count) {
            arr[u] = count;
            q.push(u);
        }
        if (d > 0 && arr[d] > count) {
            arr[d] = count;
            q.push(d);
        }
    }
    if (arr[G] != 0x7fffffff) {
        std::cout << arr[G];
    } else {
        std::cout << "use the stairs";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}