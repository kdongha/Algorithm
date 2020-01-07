//
// Created by kdongha on 2020/01/07.
//

#include <bits/stdc++.h>

int N, M, ans;
bool person[51];
int party[51][51];
bool check[51];
std::queue<int> q;

void solve() {
    std::cin >> N >> M;
    int p;
    std::cin >> p;
    for (int i = 0; i < p; i++) {
        int temp;
        std::cin >> temp;
        person[temp] = true;
        q.push(temp);
    }
    for (int i = 0; i < M; i++) {
        std::cin >> party[i][0];
        for (int j = 1; j <= party[i][0]; j++) {
            std::cin >> party[i][j];
        }
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < M; i++) {
            if (!check[i]) {
                for (int j = 1; j <= party[i][0]; j++) {
                    if (person[party[i][j]]) {
                        check[i] = true;
                        flag = true;
                        break;
                    }
                }
                if (check[i]) {
                    for (int j = 1; j <= party[i][0]; j++) {
                        person[party[i][j]] = true;
                    }
                }
            }
        }
    }
    ans=0;
    for(int i=0;i<M;i++){
        if(!check[i]){
            ans++;
        }
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}