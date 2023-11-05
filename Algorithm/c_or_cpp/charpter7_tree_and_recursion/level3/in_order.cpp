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

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

int main() {
    // 测试代码
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = inorderTraversal(root);
    cout << "Inorder traversal: ";
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}