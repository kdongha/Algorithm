//
// Created by kdongha on 2019/12/16.
//

#include <bits/stdc++.h>

int T, N, M;
struct Path {
    int u;
    int v;
    int cost;
};

bool operator<(const Path &p1, const Path &p2) {
    return p1.cost < p2.cost;
}

struct Heap {
    Path heap[200005];
    int size = 0;

    void push(Path p) {
        heap[++size] = p;
        int idx = size;
        while (idx > 1) {
            if (heap[idx] < heap[idx / 2]) {
                Path tmp = heap[idx];
                heap[idx] = heap[idx / 2];
                heap[idx / 2] = tmp;
                idx /= 2;
            } else {
                break;
            }
        }
    }

    Path pop() {
        Path ret = heap[1];
        heap[1] = heap[size--];
        int idx = 1;
        while (idx <= size) {
            int next = idx;
            if (2 * idx <= size && heap[2 * idx] < heap[next]) {
                next = 2 * idx;
            }
            if (2 * idx + 1 <= size && heap[2 * idx + 1] < heap[next]) {
                next = 2 * idx + 1;
            }
            if (next != idx) {
                Path tmp = heap[idx];
                heap[idx] = heap[next];
                heap[next] = tmp;
                idx = next;
            } else {
                break;
            }
        }
        return ret;
    }
};

Heap heap;
int parent[50005];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u < v) {
        parent[v] = u;
    } else {
        parent[u] = v;
    }
}

void solve() {
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        std::cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < M; i++) {
            int u, v, c;
            std::cin >> u >> v >> c;
            heap.push({u, v, c});
        }
        long long int cost = 0;
        while (heap.size != 0) {
            Path p = heap.pop();
            if (find(p.u) != find(p.v)) {
                cost += p.cost;
                merge(p.u, p.v);
            }
        }
        std::cout << "#" << t << " " << cost << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}