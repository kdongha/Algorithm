//
// Created by kdongha on 2019/12/20.
//

#include <bits/stdc++.h>

int N, M;
int aMatch[105];
int bMatch[105];
bool visited[105];
bool map[105][105];

bool dfs(int a) {
    if (visited[a]) {
        return false;
    } else {
        visited[a] = true;
        for (int b = 1; b <= N; b++) {
            if (map[a][b]) {
                if (bMatch[b] == -1 || dfs(bMatch[b])) {
                    aMatch[a] = b;
                    bMatch[b] = a;
                    return true;
                }
            }
        }
        return false;
    }
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        map[a][b] = true;
    }
    for (int i = 1; i <= N; i++) {
        aMatch[i] = -1;
        bMatch[i] = -1;
    }
    int size = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[j] = false;
        }
        if (dfs(i)) {
            size++;
        }
    }
    std::cout << size;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}
