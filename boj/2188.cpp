//
// Created by kdongha on 2019/12/20.
//

#include <bits/stdc++.h>

int N, M;
bool map[205][205];
bool visited[205];
int aMatch[205];
int bMatch[205];

bool dfs(int a) {
    if (visited[a]) {
        return false;
    } else {
        visited[a] = true;
        for (int b = 1; b <= M; b++) {
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
    for (int i = 1; i <= N; i++) {
        int S;
        std::cin >> S;
        for (int s = 0; s < S; s++) {
            int j;
            std::cin >> j;
            map[i][j] = true;
        }
    }
    for (int i = 1; i <= N; i++) {
        aMatch[i] = -1;
    }
    for (int j = 1; j <= M; j++) {
        bMatch[j] = -1;
    }
    int size = 0;
    for (int a = 1; a <= N; a++) {
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
        }
        if (dfs(a)) {
            size++;
        }
    }
    std::cout<<size;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}