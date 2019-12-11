//
// Created by kdongha on 2019/12/11.
//

#include <bits/stdc++.h>

int N, M, ans;
int score[17];
bool alive[17];
int R[17][17];

void play(int day, int people) {
    if (people == 1) {
        return;
    } else if (people % 2 == 1) {
        int select = 0;
        for (int i = 1; i <= N; i++) {
            if (alive[i] && score[select] < score[i]) {
                select = i;
            }
        }
        if (select == M) {
            return;
        } else {
            alive[select] = false;
            play(day, people - 1);
            alive[select] = true;
        }
    } else {
        ans = std::max(ans, day);
        for (int i = 1; i <= N; i++) {
            if (alive[i] && i != M) {
                alive[i] = false;
                for (int j = 1; j <= N; j++) {
                    score[j] += R[i][j];
                }
                play(day + 1, people - 1);
                for (int j = 1; j <= N; j++) {
                    score[j] -= R[i][j];
                }
                alive[i] = true;
            }
        }
    }
}

void solve() {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> score[i];
        alive[i] = true;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> R[i][j];
        }
    }
    std::cin >> M;
    ans = 0;
    score[0] = 0x80000000;
    M++;
    play(1, N);
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}