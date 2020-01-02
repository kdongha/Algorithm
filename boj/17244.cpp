//
// Created by kdongha on 2020/01/03.
//

#include <bits/stdc++.h>

int N, M, ans, cnt, si, sj;
char map[55][55];
bool visited[1 << 5][55][55];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
struct node {
    int i;
    int j;
    int find;
    int move;
};
std::queue<node> q;

bool inside(int i, int j) {
    return i >= 0 && i < M && j >= 0 && j < N;
}

void solve() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> map[i][j];
            if (map[i][j] == 'S') {
                si = i;
                sj = j;
                map[i][j] = '.';
            } else if (map[i][j] == 'X') {
                map[i][j] = cnt + '0';
                cnt++;
            }
        }
    }
    int find = (1 << cnt) - 1;
    q.push({si, sj, 0, 0});
    visited[0][si][sj] = true;
    while (!q.empty()) {
        node n = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ni = n.i + di[d];
            int nj = n.j + dj[d];
            int nf = n.find;
            int nm = n.move + 1;
            if (inside(ni, nj) && map[ni][nj] != '#' && !visited[nf][ni][nj]) {
                if (map[ni][nj] == 'E') {
                    if (find == nf) {
                        ans = nm;
                        goto out;
                    }
                } else if (map[ni][nj] != '.') {
                    nf |= (1 << (map[ni][nj] - '0'));
                    if (!visited[nf][ni][nj]) {
                        q.push({ni, nj, nf, nm});
                    }
                } else {
                    q.push({ni, nj, nf, nm});
                }
                visited[nf][ni][nj] = true;
            }
        }
    }
    out:
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}