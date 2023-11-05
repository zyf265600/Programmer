#include <iostream>
#include <vector>
using namespace std;

int minCut(string ss) {
    char s[100];
    int n = ss.length();
    if (n == 0) {
        return 0;
    }

    bool isPalin[n][n];
    int f[n + 1];
    int i, j, t;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            isPalin[i][j] = false;
        }
    }
    // 生成回文串
    for (t = 0; t < n; t++) {
        // 奇数长度
        i = j = t;
        while (i >= 0 && j < n && s[i] == s[j]) {
            isPalin[i][j] = true;
            i--;
            j++;
        }
        // 偶数长度
        i = t;
        j = t + 1;
        while (i >= 0 && j < n && s[i] == s[j]) {
            isPalin[i][j] = true;
            i--;
            j++;
        }
    }
    f[0] = 0;
    for (i = 1; i <= n; i++) {
        f[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (isPalin[j][i - 1]) {
                f[i] = min(f[i], f[j] + 1);
            }
        }
    }
    return f[n];
}

int main() {
    string ss = "aba"; // 这里使用了一个例子字符串作为输入，可以根据实际情况进行修改和测试。
    cout << minCut(ss) << endl; // 输出最小割的大小，根据输入的字符串可能为0或正整数。
    return 0;
}