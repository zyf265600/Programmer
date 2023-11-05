#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
  
    // 首先对数组进行升序排列
    sort(nums.begin(), nums.end());
  
    // 固定一个元素，然后使用双指针求解
    for (int i = 0; i < nums.size() - 2; ++i) {
        // 跳过重复的元素
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                // 跳过重复的元素
                while (left < right && nums[left] == nums[left+1])
                    ++left;
                while (left < right && nums[right] == nums[right-1])
                    --right;
                ++left;
                --right;
            }
            else if (sum < 0) {
                ++left;
            }
            else {
                --right;
            }
        }
    }

    return result;
}

 
int main() {
    
    return 0;
}
