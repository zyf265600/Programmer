#include <iostream>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // Backtracking approach
    vector<int> res;
    // Return the preorder traversal result
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
    // Binary tree traversal function
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // Preorder traversal position
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    TreeNode *root = TreeNode::createRoot({1, 22, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9});
    TreeNode::print(root);

    vector<int> result = Solution().preorderTraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
}
