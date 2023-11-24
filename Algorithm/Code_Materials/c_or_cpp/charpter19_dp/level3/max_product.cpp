#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {
    if (nums.empty() || nums.size() == 0) {
        return 0;
    }
    int res = nums[0];
    int max_product = nums[0];
    int min_product = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int cur_max = max(max(max_product * nums[i], nums[i]), min_product * nums[i]);
        int cur_min = min(min(cur_max * nums[i], nums[i]), min_product * nums[i]);
        if (cur_max > res) {
            res = cur_max;
        }
        max_product = cur_max;
        min_product = cur_min;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << maxProduct(nums) << endl; // 输出 15，即最大乘积为 15 的子数组为 [1, 2, 3, 4, 5] 和 [1, 2, 3, 4]
    return 0;
}