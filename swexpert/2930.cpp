//
// Created by kdongha on 2019/12/10.
//

#include <bits/stdc++.h>

int Tc, N, op, val;
int size;
int heap[100005];

void init() {
    size = 0;
}

int push(int val) {
    heap[++size] = val;
    int i = size;
    while (i > 1) {
        if (heap[i >> 1] < heap[i]) {
            int tmp = heap[i >> 1];
            heap[i >> 1] = heap[i];
            heap[i] = tmp;
            i >>= 1;
        } else {
            break;
        }
    }
}

int pop() {
    if (size == 0) {
        return -1;
    } else {
        int res = heap[1];
        heap[1] = heap[size--];
        int p = 1;
        while ((p << 1) + 1 <= size) {
            int next = p;
            if (heap[p << 1] > heap[next]) {
                next = p << 1;
            }
            if (heap[(p << 1) + 1] > heap[next]) {
                next = (p << 1) + 1;
            }
            if (next == p) {
                break;
            } else {
                int tmp = heap[p];
                heap[p] = heap[next];
                heap[next] = tmp;
                p = next;
            }
        }
        return res;
    }
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        init();
        std::cin >> N;
        std::cout << "#" << tc;
        for (int i = 0; i < N; i++) {
            std::cin >> op;
            if (op == 1) {
                std::cin >> val;
                push(val);
            } else {
                std::cout << " " << pop();
            }
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}