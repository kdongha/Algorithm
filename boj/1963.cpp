//
// Created by kdongha on 2019/12/04.
//

#include <bits/stdc++.h>

struct Pair {
    int num;
    int cnt;
};

int T, from, to;
bool prime[10000];
bool visited[10000];
std::priority_queue<Pair> pq;

bool operator<(const Pair &p1, const Pair &p2) {
    return p1.cnt > p2.cnt;
}

void init() {
    std::fill(prime, prime + 10000, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < 100; i++) {
        if (prime[i]) {
            for (int j = i + i; j < 10000; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    std::cin >> T;
    init();
    while (T--) {
        std::cin >> from >> to;
        pq = std::priority_queue<Pair>();
        for (int i = 1000; i < 10000; i++) {
            visited[i] = false;
        }
        pq.push({from, 0});
        visited[from] = true;
        while (!pq.empty()) {
            int current = pq.top().num;
            int count = pq.top().cnt;
            if (current == to) {
                break;
            } else {
                for (int i = current - 1; i >= current / 10 * 10; i--) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current + 1; i < (current / 10 + 1) * 10; i++) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current - 10; i >= current / 100 * 100; i -= 10) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current + 10; i < (current / 100 + 1) * 100; i += 10) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current - 100; i >= current / 1000 * 1000; i -= 100) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current + 100; i < (current / 1000 + 1) * 1000; i += 100) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current - 1000; i > 1000; i -= 1000) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                for (int i = current + 1000; i < 10000; i += 1000) {
                    if (prime[i] && !visited[i]) {
                        pq.push({i, count + 1});
                        visited[i] = true;
                    }
                }
                pq.pop();
            }
        }
        if (pq.empty()) {
            std::cout << "Impossible\n";
        } else {
            std::cout << pq.top().cnt << "\n";
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