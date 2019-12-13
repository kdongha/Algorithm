//
// Created by kdongha on 2019/12/13.
//

//main code
#include <stdio.h>
#include <iostream>

using namespace std;

extern void init(void);

extern void insert(int buffer_size, char *buf);

extern int query(int buffer_size, char *buf);

int main(void) {
    //freopen("input.txt", "r", stdin);
    int TestCase;
    for (scanf("%d", &TestCase); TestCase--;) {
        int Query_N;
        scanf("%d", &Query_N);

        init();

        static int tc = 0;
        printf("#%d", ++tc);

        for (int i = 1; i <= Query_N; i++) {
            int type;
            scanf("%d", &type);

            if (type == 1) {
                char buf[15] = {0,};
                scanf("%s", buf);

                int buffer_size = 0;
                while (buf[buffer_size]) buffer_size++;

                insert(buffer_size, buf);
            } else {
                char buf[15] = {0,};
                scanf("%s", buf);

                int buffer_size = 0;
                while (buf[buffer_size]) buffer_size++;

                printf(" %d", query(buffer_size, buf));
            }
        }
        printf("\n");
        fflush(stdout);
    }
}

//user code

struct Trie {
    int count;
    Trie *next[26];
};

struct TriePool {
    int index;
    Trie tries[1000005];

    void clear() {
        index = 0;
    }

    Trie *allow() {
        tries[index].count = 0;
        for (int i = 0; i < 26; i++) {
            tries[index].next[i] = nullptr;
        }
        return &tries[index++];
    }
};

Trie *root;
TriePool pool;

void init(void) {
    pool.clear();
    root = pool.allow();
}

void insert(int buffer_size, char *buf) {
    Trie *cur = root;
    cur->count++;
    for (int i = 0; i < buffer_size; i++) {
        int c = *(buf + i) - 'a';
        if (cur->next[c] == nullptr) {
            cur->next[c] = pool.allow();
        }
        cur = cur->next[c];
        cur->count++;
    }
}

int query(int buffer_size, char *buf) {
    Trie *cur = root;
    for (int i = 0; i < buffer_size; i++) {
        int c = *(buf + i)-'a';
        if (cur->next[c] == nullptr) {
            return 0;
        } else {
            cur = cur->next[c];
        }
    }
    return cur->count;
}