#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }
    stack<TreeNode*> stack;
    TreeNode* node = root;
    while (!stack.empty() || node != nullptr) {
        while (node != nullptr) {
            res.push_back(node->val);
            stack.push(node);
            node = node->right;
        }
        node = stack.top();
        stack.pop();
        node = node->left;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    // 创建测试用例二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(6);
    root->right->right->right->left = new TreeNode(7);
    root->right->right->right->right = new TreeNode(8);
    root->right->right->right->right->left = new TreeNode(9);
    root->right->right->right->right->right = new TreeNode(10);
    // 调用postorderTraversal函数进行中序遍历并输出结果
    vector<int> res = postorderTraversal(root);
    cout << "Postorder traversal: ";
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}