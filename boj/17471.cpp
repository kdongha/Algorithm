//
// Created by kdongha on 2020/02/27.
//

#include <bits/stdc++.h>

using namespace std;

int N, SUM, ans;
int people[11];
vector<int> adj[11];
bool contain[11];
int parent[11];


int find(int u) {
    if (u == parent[u]) {
        return u;
    } else {
        return parent[u] = find(parent[u]);
    }
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u > v) {
        parent[u] = v;
    } else {
        parent[v] = u;
    }

}

bool is2Group() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (auto near:adj[i]) {
            if (contain[i] == contain[near]) {
                merge(i, near);
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    return count == 2;
}

void comb(int index) {
    if (index > N) {
        if (is2Group()) {
            int sum = 0;
            for (int i = 1; i <= N; i++) {
                if (contain[i]) {
                    sum += people[i];
                }
            }
            if (sum != SUM) {
                int diff = abs(2 * sum - SUM);
                if (ans > diff) {
                    ans = diff;
                }
            }
        }
    } else {
        comb(index + 1);
        contain[index] = true;
        comb(index + 1);
        contain[index] = false;
    }
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> people[i];
        SUM += people[i];
    }
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            adj[i].push_back(temp);
        }
    }
    ans = SUM;
    comb(0);
    if (ans != SUM) {
        cout << ans;
    } else {
        cout << -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}