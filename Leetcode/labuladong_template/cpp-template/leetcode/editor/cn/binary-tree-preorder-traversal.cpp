#include <iostream>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> res;

    // 返回前序遍历结果
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }

    // 二叉树遍历函数
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // 前序遍历位置
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    // your test code here
    Solution solution;
    TreeNode *root = TreeNode::createRoot({1, 22, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9});
    vector<int> result = solution.preorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
}
