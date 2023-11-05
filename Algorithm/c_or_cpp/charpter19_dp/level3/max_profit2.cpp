#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }
    std::vector<int> dp(n, 0);
    dp[0] = -prices[0];
    for (int i = 1; i < n; ++i) {
        dp[i] = std::max(dp[i - 1], dp[i - 1] + prices[i]);
        dp[i] = std::max(dp[i], dp[i - 1] - prices[i]);
    }
    return dp[n - 1];
}

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int max_profit = maxProfit(prices);
    std::cout << "Max Profit: " << max_profit << std::endl;  // Max Profit: 6
    return 0;
}