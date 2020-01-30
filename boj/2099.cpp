//
// Created by kdongha on 2020/01/30.
//

#include <bits/stdc++.h>

int N, K, M, a, b;

struct Matrix {
    long long int arr[201][201];

    Matrix operator*(const Matrix &matrix) {
        Matrix result;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                result.arr[i][j] = 0;
                for (int k = 1; k <= N; k++) {
                    result.arr[i][j] += arr[i][k] * matrix.arr[k][j];
                }
            }
        }
        return result;
    }
};

Matrix matrix;

Matrix pow(Matrix m, int n) {
    if (n == 1) {
        return m;
    } else {
        Matrix ret = pow(m, n / 2);
        ret = ret * ret;
        if (n % 2 == 1) {
            ret = ret * m;
        }
        return ret;
    }
}

void solve() {
    std::cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) {
        std::cin >> a >> b;
        matrix.arr[i][a]=1;
        matrix.arr[i][b]=1;
    }
    Matrix result = pow(matrix, K);
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        if (result.arr[a][b] == 0) {
            std::cout << "life\n";
        } else {
            std::cout << "death\n";
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