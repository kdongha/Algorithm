//
// Created by kdongha on 2019/12/19.
//

#include <bits/stdc++.h>

int memory[32];
char input[9];
int adder;

int stoi(){
    int code = 0;
    for (int i = 0; i < 8; i++) {
        code <<= 1;
        code += input[i] - '0';
    }
    return code;
}

void solve() {
    while (std::cin >> input) {
        memory[0]=stoi();
        for (int i = 1; i < 32; i++) {
            std::cin >> input;
            memory[i] = stoi();
        }
        int pc = 0;
        adder = 0;
        while (true) {
            int command = memory[pc] >> 5;
            int operand = memory[pc++] % 32;
            pc %= 32;
            switch (command) {
                case 0:
                    memory[operand] = adder;
                    break;
                case 1:
                    adder = memory[operand];
                    break;
                case 2:
                    if (adder == 0) {
                        pc = operand;
                    }
                    break;
                case 3:
                    break;
                case 4:
                    adder += 256;
                    adder--;
                    adder %= 256;
                    break;
                case 5:
                    adder++;
                    adder %= 256;
                    break;
                case 6:
                    pc = operand;
                    break;
                case 7:
                    goto out;
            }
        }
        out:
        for (int div = 128; div > 0; div /= 2) {
            std::cout << adder / div;
            adder %= div;
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    solve();
    return 0;
}