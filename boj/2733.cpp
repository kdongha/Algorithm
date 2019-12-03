//
// Created by kdongha on 2019/12/03.
//

#include <bits/stdc++.h>

#define POINTER_MAX 32768
#define VALUE_MAX 256

int T, current;
char pointer[POINTER_MAX];
std::vector<char> v;
std::string str;
std::map<int, int> m;

void init() {
    current = 0;
    std::fill(pointer, pointer + POINTER_MAX, 0);
    v.clear();
    m.clear();
}

bool compile() {
    std::stack<int> stack;
    std::getline(std::cin, str);
    int idx = 0;
    while (str != "end") {
        for (auto c: str) {
            if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.') {
                v.push_back(c);
                idx++;
            } else if (c == '[') {
                v.push_back(c);
                stack.push(idx++);
            } else if (c == ']') {
                v.push_back(c);
                if (stack.empty()) {
                    return false;
                }
                int pair = stack.top();
                stack.pop();
                m.insert({pair, idx});
                m.insert({idx, pair});
                idx++;
            } else if (c == '%') {
                break;
            }
        }
        std::getline(std::cin, str);
    }
    return stack.empty();
}


void solve() {
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        std::cout << "PROGRAM #" << t << ":\n";
        if (compile()) {
            for (int idx = 0; idx < v.size(); idx++) {
                if (v[idx] == '>') {
                    current += 1;
                    current %= POINTER_MAX;
                } else if (v[idx] == '<') {
                    current -= 1;
                    current += POINTER_MAX;
                    current %= POINTER_MAX;
                } else if (v[idx] == '+') {
                    pointer[current] += 1;
                    pointer[current] %= VALUE_MAX;
                } else if (v[idx] == '-') {
                    pointer[current] -= 1;
                    pointer[current] += VALUE_MAX;
                    pointer[current] %= VALUE_MAX;
                } else if (v[idx] == '.') {
                    std::cout << pointer[current];
                } else if (v[idx] == '[') {
                    if (pointer[current] == 0) {
                        idx = m.find(idx)->second;
                    }
                } else if (v[idx] == ']') {
                    if (pointer[current] != 0) {
                        idx = m.find(idx)->second;
                    }
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