#include <iostream>
#include <queue>
using namespace std;

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findBottomLeftValue(TreeNode* root) {
    if (root == nullptr || root->left == nullptr && root->right == nullptr) {
        return root->val;
    }

    queue<TreeNode*> queue;
    queue.push(root);
    TreeNode* temp = new TreeNode(-100);

    while (!queue.empty()) {
        temp = queue.front();
        queue.pop();
        if (temp->right != nullptr) {
            queue.push(temp->right);
        }
        if (temp->left != nullptr) {
            queue.push(temp->left);
        }
    }
    return temp->val;
}

int main() {
    // 创建一个二叉树，并插入一些值
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // 调用函数查找最左下角的值
    int result = findBottomLeftValue(root);
    cout << "The bottom-left value is: " << result << endl;

    return 0;
}