#include <iostream>
#include <vector>
#include <queue>

// 分层打印
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ret;
    if (!root) {
        return ret;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(vector<int>());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ret;
}



int main() {
    // 创建二叉树，这里以一个示例二叉树为例，具体实现可以根据实际情况进行修改。
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 调用levelOrder函数获取并输出二叉树的层序遍历结果。
    vector<vector<int> > res = levelOrder(root);
    for (auto& row : res) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}