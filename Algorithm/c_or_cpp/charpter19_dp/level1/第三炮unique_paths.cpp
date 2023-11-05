#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int main() {
    int m = 3, n = 4;
    cout << uniquePaths(m, n) << endl; // 输出 12
    return 0;
}