#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }

    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (!stk.empty() || node != nullptr) {
        while (node != nullptr) {
            res.push_back(node->val);
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
    return res;
}

int main() {
    // 创建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(6);

    // 输出中序遍历结果为 [1, 3, 2, 6, 4, 5]
    vector<int> res = preorderTraversal(root);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}