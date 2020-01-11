//
// Created by kdongha on 2020/01/12.
//

#include <bits/stdc++.h>

int Tc, R, C;
char map[21][21];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
bool visited[25][25][20][5];
struct Point {
    int r;
    int c;
    int m;
    int d;
};
std::stack<Point> s;

bool run(int r, int c, int m, int d) {
    if (visited[r][c][m][d]) {
        return false;
    } else {
        visited[r][c][m][d] = true;
        int nr = r;
        int nc = c;
        int nm = m;
        int nd = d;
        if (map[r][c] == '?') {
            bool exit = false;
            for (d = 0; d < 4 && !exit; d++) {
                nr = r + dr[d];
                nc = c + dc[d];
                nr += R;
                nr %= R;
                nc += C;
                nc %= C;
                nd = d;
                exit = run(nr, nc, nm, nd);
            }
            return exit;
        } else {
            switch (map[r][c]) {
                case '<':
                    nd = 2;
                    break;
                case '>':
                    nd = 0;
                    break;
                case '^':
                    nd = 3;
                    break;
                case 'v':
                    nd = 1;
                    break;
                case '_':
                    nd = m == 0 ? 0 : 2;
                    break;
                case '|':
                    nd = m == 0 ? 1 : 3;
                    break;
                case '.':
                    break;
                case '@':
                    return true;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    nm = map[r][c] - '0';
                    break;
                case '+':
                    nm++;
                    nm %= 16;
                    break;
                case '-':
                    nm--;
                    nm += 16;
                    nm %= 16;
                    break;
            }
            nr += dr[nd];
            nc += dc[nd];
            nr += R;
            nr %= R;
            nc += C;
            nc %= C;
            return run(nr, nc, nm, nd);
        }
    }
}

void solve() {
    std::cin >> Tc;
    for (int tc = 1; tc <= Tc; tc++) {
        std::cin >> R >> C;
        bool exitFlag = false;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                std::cin >> map[i][j];
                if (map[i][j] == '@') {
                    exitFlag = true;
                }
            }
        }
        if (exitFlag) {
            while (!s.empty()) {
                s.pop();
            }
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    for (int m = 0; m < 16; m++) {
                        for (int d = 0; d < 4; d++) {
                            visited[i][j][m][d] = false;
                        }
                    }
                }
            }
            s.push({0, 0, 0, 0});
            bool exit = false;
            while (!s.empty() && !exit) {
                Point p = s.top();
                s.pop();
                if (!visited[p.r][p.c][p.m][p.d]) {
                    visited[p.r][p.c][p.m][p.d] = true;
                    int nr = p.r;
                    int nc = p.c;
                    int nm = p.m;
                    int nd = p.d;
                    if (map[p.r][p.c] == '?') {
                        for (int d = 0; d < 4; d++) {
                            nr = p.r + dr[d];
                            nc = p.c + dc[d];
                            nr += R;
                            nr %= R;
                            nc += C;
                            nc %= C;
                            nd = d;
                            s.push({nr, nc, nm, nd});
                        }
                    } else {
                        switch (map[p.r][p.c]) {
                            case '<':
                                nd = 2;
                                break;
                            case '>':
                                nd = 0;
                                break;
                            case '^':
                                nd = 3;
                                break;
                            case 'v':
                                nd = 1;
                                break;
                            case '_':
                                nd = p.m == 0 ? 0 : 2;
                                break;
                            case '|':
                                nd = p.m == 0 ? 1 : 3;
                                break;
                            case '.':
                                break;
                            case '@':
                                exit = true;
                                break;
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9':
                                nm = map[p.r][p.c] - '0';
                                break;
                            case '+':
                                nm++;
                                nm %= 16;
                                break;
                            case '-':
                                nm--;
                                nm += 16;
                                nm %= 16;
                                break;
                        }
                        nr += dr[nd];
                        nc += dc[nd];
                        nr += R;
                        nr %= R;
                        nc += C;
                        nc %= C;
                        s.push({nr, nc, nm, nd});
                    }
                }
            }
            if (exit) {
                std::cout << "#" << tc << " YES\n";
            } else {
                std::cout << "#" << tc << " NO\n";
            }
        } else {
            std::cout << "#" << tc << " NO\n";
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