//
// Created by kdongha on 2019/12/03.
//

#include <bits/stdc++.h>

int T, current, size;

std::vector<char> v(128000);
std::string str;

void init() {
    current = 0;
}

bool compile() {
    std::getline(std::cin, str);
    size = 0;
    int depth = 0;
    while (str != "end") {
        for (auto c: str) {
            switch (c) {
                case '>':
                case '<':
                case '+':
                case '-':
                case '.':
                case '[':
                case ']':
                    v[size] = c;
                    if (c == '[') {
                        depth++;
                    } else if (c == ']') {
                        if (depth == 0) {
                            return false;
                        }
                        depth--;
                    }
                    size++;
                    break;
                case '%':
                    goto out;
            }
        }
        out:
        std::getline(std::cin, str);
    }
    return depth == 0;
}


void solve() {
    std::cin >> T;
    std::cin.ignore(1024, '\n');
    for (int t = 1; t <= T; t++) {
        unsigned char pointer[32768] = {};
        init();
        std::cout << "PROGRAM #" << t << ":\n";
        if (compile()) {
            int skip = 0;
            std::stack<int> stack;
            for (int i = 0; i < size; i++) {
                switch (v[i]) {
                    case '>':
                        if (!skip) current = (current + 1) % 32768;
                        break;
                    case '<':
                        if (!skip) current = (current > 0 ? current - 1 : 32767);
                        break;
                    case '+':
                        if (!skip) pointer[current]++;
                        break;
                    case '-':
                        if (!skip) pointer[current]--;
                        break;
                    case '.':
                        if (!skip) std::cout << pointer[current];
                        break;
                    case '[':
                        stack.push(i);
                        if (pointer[current] == 0 && !skip) {
                            skip = i;
                        }
                        break;
                    case ']':
                        int find = stack.top();
                        stack.pop();
                        if (pointer[current] != 0) {
                            i = find - 1;
                        }
                        if (skip == find) {
                            skip = 0;
                        }
                        break;
                }
            }
            std::cout << "\n";
        } else {
            std::cout << "COMPILE ERROR\n";
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