#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
    auto levelOrder = vector<vector<int> >();
    if (!root)
    {
        return levelOrder;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto level = vector<int>();
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            auto node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        levelOrder.push_back(level);
    }
    reverse(levelOrder.begin(), levelOrder.end());
    return levelOrder;
}

int main()
{
    // 创建二叉树，这里以一个示例二叉树为例，具体实现可以根据实际情况进行修改。
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int> > res = levelOrderBottom(root);
    for (auto &row : res)
    {
        for (auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}