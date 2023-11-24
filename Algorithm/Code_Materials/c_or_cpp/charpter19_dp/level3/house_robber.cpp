#include <iostream>
#include <vector>

using namespace std;

long houseRobber(vector<int>& A) {
    int n = A.size();
    if (n == 0) return 0;
    vector<long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = A[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + A[i - 1]);
    }
    return dp[n];
}

int main() {
    vector<int> A = {1, 1, 2, 3, 1};
    cout << houseRobber(A) << endl; // Output: 7
    return 0;
}