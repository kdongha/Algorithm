//
// Created by kdongha on 2020/02/20.
//

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[5000];

bool divide(int val) {
    int low = arr[0];
    int high = arr[0];
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (low + val < arr[i] || high - val > arr[i]) {
            count++;
            low = arr[i];
            high = arr[i];
        } else {
            low = min(low, arr[i]);
            high = max(high, arr[i]);
        }
    }
    return count <= M;
}

void solve() {
    cin >> N >> M;
    int low = 0, high = 10000;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (divide(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << low;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}