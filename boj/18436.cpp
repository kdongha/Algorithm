//
// Created by kdongha on 2020/02/24.
//

#include <bits/stdc++.h>

int N, M;
bool arr[1 << 17];
int bit[1 << 17];

using namespace std;

void update(int i, int v) {
    while (i <= N) {
        bit[i] += v;
        i += i & -i;
    }
}

int sum(int i) {
    int ret = 0;
    while (i >= 1) {
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}

void change(int i, int v) {
    if ((arr[i] ^ (v % 2 != 0))) {
        int value = v % 2 == 0 ? -1 : 1;
        arr[i] = v % 2;
        update(i, value);
    }
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        change(i, temp);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1:
                change(b, c);
                break;
            case 2:
                cout << (c - b + 1) - sum(c) + sum(b-1) << "\n";
                break;
            case 3:
                cout << sum(c) - sum(b-1) << "\n";
                break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}