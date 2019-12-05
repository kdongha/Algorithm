//
// Created by kdongha on 2019/12/06.
//

#include <bits/stdc++.h>

struct Point {
    int x;
    int y;
};


int T, h, w, ans;
bool key['z' - 'a' + 1];
std::queue<Point> q;
std::queue<Point> path['z' - 'a' + 1];
char map[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
std::string s;

void init() {
    ans = 0;
    q = std::queue<Point>();
    for (int i = 0; i <= 'z' - 'a'; i++) {
        path[i] = std::queue<Point>();
        key[i] = false;
    }
    for (int i = 0; i <= h + 1; i++) {
        map[i][0] = '.';
        map[i][w + 1] = '.';
    }
    for (int j = 0; j <= w + 1; j++) {
        map[0][j] = '.';
        map[h + 1][j] = '.';
    }
}

bool inside(int x, int y) {
    return x >= 0 && x <= h+1 && y >= 0 && y <= w+1;
}

void enter(int i, int j) {
    map[i][j] = '*';
    q.push({i, j});
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = p.x + dx[d];
            int ny = p.y + dy[d];
            if (inside(nx, ny)) {
                if (map[nx][ny] == '*') {
                    continue;
                } else if (map[nx][ny] == '$') {
                    ans++;
                } else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z') {
                    int k = map[nx][ny] - 'a';
                    if (!key[k]) {
                        key[k] = true;
                        while (!path[k].empty()) {
                            q.push(path[k].front());
                            path[k].pop();
                        }
                    }
                } else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z') {
                    int k = map[nx][ny] - 'A';
                    if (!key[k]) {
                        map[nx][ny] = '*';
                        path[k].push({nx, ny});
                        continue;
                    }
                }
                map[nx][ny] = '*';
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    std::cin >> T;
    while (T--) {
        std::cin >> h >> w;
        init();
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                std::cin >> map[i][j];
            }
        }
        std::cin >> s;
        if (s != "0") {
            for (auto c:s) {
                key[c - 'a'] = true;
            }
        }
        enter(0, 0);
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}