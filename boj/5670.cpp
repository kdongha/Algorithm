//
// Created by kdongha on 2019/12/18.
//

#include <bits/stdc++.h>

struct Trie {
    int cnt;
    bool end;
    Trie *next[26];
};

struct TriePool {
    int idx;
    Trie pool[800005];

    void init() {
        idx = 0;
    }

    Trie *allow() {
        pool[idx].cnt = 0;
        pool[idx].end = false;
        for (int i = 0; i < 26; i++) {
            pool[idx].next[i] = nullptr;
        }
        return &pool[idx++];
    }
};

int N;
Trie *root;
TriePool pool;
std::string str[100005];

void solve() {
    while (std::cin >> N) {
        pool.init();
        root = pool.allow();
        for (int i = 0; i < N; i++) {
            std::cin >> str[i];
            Trie *cur = root;
            for (auto c:str[i]) {
                if (cur->next[c - 'a'] == nullptr) {
                    cur->next[c - 'a'] = pool.allow();
                    cur->cnt++;
                }
                cur = cur->next[c - 'a'];
            }
            cur->end = true;
        }
        double avg = 0;
        for (int i = 0; i < N; i++) {
            Trie *cur = root;
            if (cur->cnt == 1) {
                avg++;
            }
            for (auto c:str[i]) {
                if (cur->cnt == 1 && !cur->end) {
                    cur = cur->next[c - 'a'];
                } else {
                    avg++;
                    cur = cur->next[c - 'a'];
                }
            }
        }
        std::cout << std::fixed << std::setprecision(2) <<avg / N << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}