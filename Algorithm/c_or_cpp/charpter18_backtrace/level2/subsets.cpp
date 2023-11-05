#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Subsets {
    vector<vector<int>> result;
    queue<int> path;
    
public:

   void subsetsHelper(vector<int>& nums, int startIndex) {
         result.push_back(path);
        
        if (startIndex >= nums.size()) {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push(nums[i]);
            subsetsHelper(nums, i + 1);
            path.pop();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            result.push_back(vector<int>());
            return result;
        }
        subsetsHelper(nums, 0);
        return result;
    }
    
 
};

int main() {
    int nums[] = {1, 2, 3};
    Subsets subsetter;
    vector<vector<int>> subsets = subsetter.subsets(nums);
    for (auto subset : subsets) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}