#include <iostream>

int numSquares(int n) {
    int f[n + 1];
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 10000;
        for (int j = 1; j * j <= i; j++) {
            if (f[i - j * j] + 1 < f[i]) {
                f[i] = f[i - j * j] + 1;
            }
        }
    }
    return f[n];
}

int main() {
    int n = 10; // 示例输入
    int result = numSquares(n);
    std::cout << "The number of squares in the range [1, " << n << "] is: " << result << std::endl;
    return 0;
}