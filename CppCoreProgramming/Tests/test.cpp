#include <iostream>
#include <vector>
// 矩阵乘法
std::vector<std::vector<unsigned long long>> matrixMultiply(
    const std::vector<std::vector<unsigned long long>>& A,
    const std::vector<std::vector<unsigned long long>>& B) {
    std::vector<std::vector<unsigned long long>> C(2, std::vector<unsigned long long>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// 矩阵快速幂
std::vector<std::vector<unsigned long long>> matrixPower(
    std::vector<std::vector<unsigned long long>> base, int exp) {
    std::vector<std::vector<unsigned long long>> result = {{1, 0}, {0, 1}};
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = matrixMultiply(result, base);
        }
        base = matrixMultiply(base, base);
        exp /= 2;
    }
    return result;
}

// 使用矩阵快速幂计算斐波那契数列的第 n 个数
unsigned long long FibonacciMatrix(int n) {
    if (n <= 1) {
        return n;
    }
    std::vector<std::vector<unsigned long long>> base = {{1, 1}, {1, 0}};
    std::vector<std::vector<unsigned long long>> result = matrixPower(base, n - 1);
    return result[0][0];
}

int main() {
    int n = 100; // 计算第 100 个斐波那契数
    unsigned long long result = FibonacciMatrix(n);
    std::cout << "Fibonacci number " << n << " is " << result << std::endl;
    return 0;
}