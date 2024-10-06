#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int curSum = 0;
    int totalSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++) {
        curSum += gas[i] - cost[i];
        totalSum += gas[i] - cost[i];
        if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
            start = i + 1;  // 起始位置更新为i+1
            curSum = 0;     // curSum从0开始
        }
    }
    if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
    return start;
}

int main() {
    std::vector<int> gas = {1, 2, 3, 4, 5};
    std::vector<int> cost = {1, 2, 3, 4, 5};
    int start = canCompleteCircuit(gas, cost);
    std::cout << "Start position: " << start << std::endl;
    return 0;
}