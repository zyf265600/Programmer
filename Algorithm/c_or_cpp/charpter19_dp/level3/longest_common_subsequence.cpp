#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string A, string B) {
    int m = A.length();
    int n = B.length();
    int i, j;
    int[][] f = new int[2][n + 1];
    int old, now = 0;
    for (i = 0; i <= n; i++) {
        f[now][i] = 0;
    }
    for (i = 1; i <= m; i++) {
        old = now;
        now = 1 - now;
        for (j = 0; j <= n; j++) {
            f[now][j] = f[old][j];
            if (j > 0) {
                f[now][j] = max(f[now][j], f[now][j - 1]);
            }
            if (j > 0 && A[i - 1] == B[j - 1]) {
                f[now][j] = max(f[now][j], f[old][j - 1] + 1);
            }
        }
    }
    return f[now][n];
}

int main() {
    string A = "abcbac";
    string B = "acbbec";
    cout << longestCommonSubsequence(A, B) << endl; // Output: 3, Longest common subsequence of "abc" and "ace" is "abc" in the original order.
    return 0;
}