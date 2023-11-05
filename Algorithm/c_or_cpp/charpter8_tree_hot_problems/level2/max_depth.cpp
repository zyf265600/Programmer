#include <vector>
#include <stack>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int maxDepth2(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    queue<TreeNode *> Q;
    Q.push(root);
    int ans = 0;
    while (!Q.empty())
    {
        int sz = Q.size();
        while (sz > 0)
        {
            TreeNode *node = Q.front();
            Q.pop();
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
            sz -= 1;
        }
        ans += 1;
    }
    return ans;
}

int main()
{
    // 创建测试用例的二叉树
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    cout << maxDepth2(root1) << endl;
    return 0;
}