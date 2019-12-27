//
// Created by kdongha on 2019/12/27.
//

#include <bits/stdc++.h>

struct Trie {
    Trie *next[10];
    bool end;
};

struct TriePool {
    Trie pool[1000005];
    int idx;

    void init() {
        int idx = 0;
    }

    Trie *allow() {
        for (int i = 0; i < 10; i++) {
            pool[idx].next[i] = nullptr;
        }
        pool[idx].end = false;
        return &pool[idx++];
    }
};

int t, n;
TriePool pool;
Trie *head;

void solve() {
    std::cin >> t;
    while (t--) {
        pool.init();
        head = pool.allow();
        std::cin >> n;
        bool flag = true;
        while (n--) {
            std::string s;
            std::cin >> s;
            if (flag) {
                Trie *cur = head;
                for (auto c:s) {
                    if (cur->next[c - '0'] == nullptr) {
                        cur->next[c - '0'] = pool.allow();
                    } else {
                        if (cur->next[c - '0']->end) {
                            flag = false;
                            break;
                        }
                    }
                    cur = cur->next[c - '0'];
                }
                cur->end = true;
                for (int i = 0; i < 10; i++) {
                    if (cur->next[i] != nullptr) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        std::cout << (flag ? "YES" : "NO") << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}