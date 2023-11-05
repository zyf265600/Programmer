#include <iostream>
#include <algorithm>

using namespace std;

int maxProfit(int A[], int n) {
    if (n == 0) {
        return 0;
    }
    int f[n+1][6];
    int i, j, k;
    f[0][1] = 0;
    f[0][2] = f[0][3] = f[0][4] = f[0][5] = INT_MIN;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 5; j += 2) {
            f[i][j] = f[i-1][j];
            if (j > 1 && i > 1 && f[i-1][j-1] != INT_MIN) {
                f[i][j] = max(f[i][j], f[i-1][j-1] + A[i-1] - A[i-2]);
            }
        }
        for (j = 2; j <= 5; j += 2) {
            f[i][j] = f[i-1][j-1];
            if (i > 1 && i > 1 && f[i-1][j-1] != INT_MIN) {
                f[i][j] = max(f[i][j], f[i-1][j] + A[i-1] - A[i-2]);
            }
            if (j > 2 && i > 1 && f[i-1][j-2] != INT_MIN) {
                f[i][j] = max(f[i][j], f[i-1][j-2] + A[i-1] - A[i-2]);
            }
        }
    }
    return max(max(f[n][1], f[n][3]), f[n][5]);
}

int main() {
    int A[] = {2, 7, 3, 6, 4};
    int n = sizeof(A) / sizeof(A[0]);
    cout << maxProfit(A, n) << endl; // Output: 7
    return 0;
}