//
// Created by kdongha on 2019/12/20.
//

#include <bits/stdc++.h>

int N, M;
int aMatch[1005];
int bMatch[1005];
bool visited[1005];
bool map[1005][1005];

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
    for (int a = 1; a <= N; a++) {
        int num;
        std::cin >> num;
        for (int i = 0; i < num; i++) {
            int b;
            std::cin >> b;
            map[a][b] = true;
        }
    }
    for (int a = 1; a <= N; a++) {
        aMatch[a] = -1;
    }
    for (int b = 1; b <= M; b++) {
        bMatch[b] = -1;
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
    std::cout << size;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}