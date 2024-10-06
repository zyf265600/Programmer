#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int minprice = prices[0];
    int maxprofit = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minprice) {
            minprice = prices[i];
        } else if (prices[i] - minprice > maxprofit) {
            maxprofit = prices[i] - minprice;
        }
    }
    return maxprofit;
}

int main() {
    std::vector<int> prices = {7,1,5,3,6,4};
    int max_profit = maxProfit(prices);
    std::cout << "Max Profit: " << max_profit << std::endl;
    return 0;
}