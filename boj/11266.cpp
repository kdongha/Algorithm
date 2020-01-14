//
// Created by kdongha on 2020/01/14.
//

#include <bits/stdc++.h>

int V, E, ans, count;
int discovered[10005];
bool isCutVertex[10005];
std::vector<int> list[10005];

int dfs(int i, bool isRoot) {
    discovered[i] = ++count;
    int ret = discovered[i];

    int child = 0;
    for (int next:list[i]) {
        if (discovered[next] == 0) {
            child++;
            int low = dfs(next, false);
            if (!isRoot && low >= discovered[i]) {
                isCutVertex[i] = true;
            }
            ret = std::min(ret, low);
        } else {
            ret = std::min(ret, discovered[next]);
        }
    }
    if (isRoot && child >= 2) {
        isCutVertex[i] = true;
    }
    return ret;
}

void solve() {
    std::cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        std::cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) {
        if (discovered[i] == 0) {
            dfs(i, true);
        }
    }

    for (int i = 1; i <= V; i++) {
        if (isCutVertex[i]) {
            ans++;
        }
    }
    std::cout << ans << "\n";
    for (int i = 1; i <= V; i++) {
        if (isCutVertex[i]) {
            std::cout << i << " ";
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