//
// Created by kdongha on 2020/03/09.
//

#include <bits/stdc++.h>

std::string input, output;
std::stack<char> opStack;

int getPriority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return 4;
    }
}

bool canPush(char op) {
    if (opStack.empty()) {
        return true;
    } else {
        return getPriority(opStack.top()) < getPriority(op);
    }
}

void solve() {
    std::cin >> input;
    for (char c:input) {
        if (c >= 'A' && c <= 'Z') {
            std::cout << c;
        } else {
            if (c == '(') {
                opStack.push(c);
            } else if (c == ')') {
                while (opStack.top() != '(') {
                    std::cout << opStack.top();
                    opStack.pop();
                }
                opStack.pop();
            } else {
                while (!canPush(c)) {
                    std::cout << opStack.top();
                    opStack.pop();
                }
                opStack.push(c);
            }
        }
    }
    while (!opStack.empty()) {
        std::cout << opStack.top();
        opStack.pop();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}