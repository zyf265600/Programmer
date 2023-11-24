#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<int> nums = {3, 1, 4, 8, 2, 7};
    bool result = canJump(nums);
    cout << "Can the player jump from " << nums.back() << " to " << nums.back() + 7 << "? " << (result ? "Yes" : "No") << endl;
    return 0;
}