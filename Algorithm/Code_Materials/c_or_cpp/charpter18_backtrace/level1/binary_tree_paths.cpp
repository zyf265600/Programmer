#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* cur, string path, vector<string>& result) {
    path += to_string(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中
    if (cur->left == NULL && cur->right == NULL) {
        result.push_back(path);
        return;
    }
    if (cur->left) {
        path += "->";
        traversal(cur->left, path, result); // 左
        path.pop_back(); // 回溯 '>'
        path.pop_back(); // 回溯 '-'
    }
    if (cur->right) {
        path += "->";
        traversal(cur->right, path, result); // 右
        path.pop_back(); // 回溯'>'
        path.pop_back(); // 回溯 '-'
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    string path;
    if (root == NULL) return result;
    traversal(root, path, result);
    return result;
}

int main() {
    // 创建一个二叉树，示例如下：1 -> 2 -> 3 -> 4 -> 5 -> NULL，其中1是根节点，2和4是左子树，3和5是右子树。
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6); // 6不是叶子节点，需要被遍历到。
    root->right->right = new TreeNode(7); // 7不是叶子节点，需要被遍历到。
    // 使用二叉树生成路径，示例如下：1 -> 2 -> 4 -> 5 或 1 -> 2 -> 4 -> 5 -> NULL。这里使用了两种路径。
    vector<string> paths = binaryTreePaths(root);
    // 输出结果：1 -> 2 -> 4 -> 5 或 1 -> 2 -> 4 -> 5 -> NULL。注意结果包含了两种路径。
    for (string path : paths) {
        cout << path << endl;
    }
    return 0;
}