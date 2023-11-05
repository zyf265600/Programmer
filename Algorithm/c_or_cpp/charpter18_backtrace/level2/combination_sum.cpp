#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& c, int u, int target, vector<vector<int>>& res, vector<int>& path) {
    if (target < 0) {
        return;
    }
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = u; i < c.size(); i++) {
        if (c[i] <= target) {
            path.push_back(c[i]);
            dfs(c, i, target - c[i], res, path);
            path.pop_back(); // 回溯，弹出当前节点
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(candidates, 0, target, res, path);
    return res;
}



int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target);
    for (auto& path : res) {
        for (auto& num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}