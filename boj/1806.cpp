//
// Created by kdongha on 2020/01/07.
//

#include <bits/stdc++.h>

int N, S;
int arr[100005];

void solve() {
    std::cin >> N >> S;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int l, r, s, ans;
    l = r = s = 0;
    ans = N + 1;
    while (r < N) {
        while (s >= S) {
            ans = std::min(ans, r - l);
            s -= arr[l++];
        }
        s += arr[r++];
    }
    while(s>=S){
        ans = std::min(ans, r - l);
        s -= arr[l++];
    }
    if(ans>N){
        ans=0;
    }
    std::cout<<ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}