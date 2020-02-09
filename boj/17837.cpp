//
// Created by kdongha on 2020/02/10.
//

#include <bits/stdc++.h>

using namespace std;

int N, K;
int color[12][12];
int board[12][12];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
struct Piece {
    int x;
    int y;
    int d;
    int up;
    int down;
};
Piece piece[10];

int reverse(int cur) {
    int next = piece[cur].up;
    piece[cur].up = piece[cur].down;
    piece[cur].down = next;
    if (next == -1) {
        return cur;
    }
    return reverse(next);
}

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool isBlueZone(int x, int y) {
    return !inside(x, y) || color[x][y] == 2;
}

bool isRedZone(int x, int y) {
    return inside(x, y) && color[x][y] == 1;
}

int propagation(int cur) {
    while (piece[cur].up != -1) {
        int up = piece[cur].up;
        piece[up].x = piece[cur].x;
        piece[up].y = piece[cur].y;
        cur = up;
    }
    return cur;
}

void move(int cur, bool twice) {
    int nx = piece[cur].x + dx[piece[cur].d];
    int ny = piece[cur].y + dy[piece[cur].d];
    if (isBlueZone(nx, ny)) {
        if (!twice) {
            piece[cur].d ^= 1;
            move(cur, true);
        }
    } else {
        board[piece[cur].x][piece[cur].y] = piece[cur].down;
        if (piece[cur].down != -1) {
            piece[piece[cur].down].up = -1;
        }
        piece[cur].down = -1;
        piece[cur].x = nx;
        piece[cur].y = ny;
        int top = propagation(cur);
        if (isRedZone(nx, ny)) {
            top = cur;
            cur = reverse(cur);
        }
        piece[cur].down = board[nx][ny];
        if (board[nx][ny] != -1) {
            piece[board[nx][ny]].up = cur;
        }
        board[nx][ny] = top;
    }
}

bool isFinish() {
    for (int i = 0; i < K; i++) {
        int count = 0;
        if (piece[i].down == -1) {
            count++;
            int cur = i;
            while (piece[cur].up != -1) {
                count++;
                cur = piece[cur].up;
            }
            if (count >= 4) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> color[i][j];
            board[i][j] = -1;
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        d--;
        piece[i] = {x, y, d, -1, -1};
        board[x][y] = i;
    }
    int ans = -1;
    for (int t = 1; t <= 1000 && ans == -1; t++) {
        for (int turn = 0; turn < K; turn++) {
            move(turn, false);
            if (isFinish()) {
                ans = t;
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}