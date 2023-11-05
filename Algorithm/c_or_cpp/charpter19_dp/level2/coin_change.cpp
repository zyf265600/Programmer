#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int M) {
    int max = M + 1;
    int dp[max];
    fill(dp, dp + max, max);
    dp[0] = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if (dp[M] > M) {
        return -1;
    }
    return dp[M];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl;  // Output: 3
    return 0;
}