//
// Created by kdongha on 2020/01/05.
//

#include <bits/stdc++.h>

int N, M, K, ans;
int A[51][51];
int S[51][51];
bool visited[6];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
std::vector<int> perm;
struct Rotate {
    int r;
    int c;
    int s;
};
Rotate R[6];


void rotate(int r, int c, int s) {
    if (s >= 1) {
        std::deque<int> dq;
        int nr = r-s;
        int nc = c-s;
        for (int d = 0; d < 4; d++) {
            for (int i = 0; i < 2 * s; i++) {
                dq.push_back(A[nr][nc]);
                nr = nr + dr[d];
                nc = nc + dc[d];
            }
        }
        dq.push_front(dq.back());
        dq.pop_back();
        nr = r-s;
        nc = c-s;
        for (int d = 0; d < 4; d++) {
            for (int i = 0; i < 2 * s; i++) {
                A[nr][nc] = dq.front();
                dq.pop_front();
                nr = nr + dr[d];
                nc = nc + dc[d];
            }
        }
        rotate(r, c, s - 1);
    }
}

void solve() {
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> S[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        std::cin >> R[i].r >> R[i].c >> R[i].s;
    }
    ans = 987654321;
    for (int i = 0; i < K; i++) {
        perm.push_back(i);
    }
    do {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                A[i][j] = S[i][j];
            }
        }
        for (int p:perm) {
            rotate(R[p].r, R[p].c, R[p].s);
        }
        for (int i = 1; i <= N; i++) {
            int sum = 0;
            for (int j = 1; j <= M; j++) {
                sum += A[i][j];
            }
            ans = std::min(ans, sum);
        }
    } while (std::next_permutation(perm.begin(), perm.end()));
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}