//
// Created by kdongha on 2019/12/19.
//

#include <bits/stdc++.h>

int N;
struct Tile {
    int left;
    int right;
    int number;
};
Tile map[505][505];
int path[250005];
int oddDi[] = {-1, -1, 0, 1, 1, 0};
int oddDj[] = {0, 1, 1, 1, 0, -1};
int evenDi[] = {-1, -1, 0, 1, 1, 0};
int evenDj[] = {-1, 0, 1, 0, -1, -1};

bool inside(int i, int j) {
    if (i % 2 == 0) {
        return i >= 0 && i < N && j >= 0 && j < N;
    } else {
        return i >= 0 && i < N && j >= 0 && j < N - 1;
    }
}

bool oddConnect(int i, int j, int ni, int nj) {
    if (nj <= j) {
        return map[i][j].left == map[ni][nj].right;
    } else {
        return map[i][j].right == map[ni][nj].left;
    }
}

bool evenConnect(int i, int j, int ni, int nj) {
    if (nj < j) {
        return map[i][j].left == map[ni][nj].right;
    } else {
        return map[i][j].right == map[ni][nj].left;
    }
}

void solve() {
    std::cin >> N;
    int num = 1;
    for (int i = 0; i < N; i++) {
        int diff = i%2;
        for (int j = 0; j < N - diff; j++) {
            int left, right;
            std::cin >> left >> right;
            map[i][j] = {left, right, num++};
        }
    }
    --num;
    int max = 1;
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    path[1] = -1;
    while (!q.empty() && max != num) {
        auto cur = q.front();
        q.pop();
        int i = cur.first;
        int j = cur.second;
        if (i % 2 == 0) {
            for (int d = 0; d < 6; d++) {
                int ni = i + evenDi[d];
                int nj = j + evenDj[d];
                if (inside(ni, nj) && evenConnect(i, j, ni, nj) && path[map[ni][nj].number] == 0) {
                    path[map[ni][nj].number]=map[i][j].number;
                    q.push({ni, nj});
                    max = std::max(max, map[ni][nj].number);
                }
            }
        } else {
            for (int d = 0; d < 6; d++) {
                int ni = i + oddDi[d];
                int nj = j + oddDj[d];
                if (inside(ni, nj) && oddConnect(i, j, ni, nj) && path[map[ni][nj].number] == 0) {
                    path[map[ni][nj].number]=map[i][j].number;
                    q.push({ni, nj});
                    max = std::max(max, map[ni][nj].number);
                }
            }
        }
    }
    std::deque<int> dq;
    int t=max;
    while(t!=1){
        dq.push_front(t);
        t=path[t];
    }
    dq.push_front(1);
    std::cout<<dq.size()<<"\n";
    for(auto p:dq){
        std::cout<<p<<" ";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}