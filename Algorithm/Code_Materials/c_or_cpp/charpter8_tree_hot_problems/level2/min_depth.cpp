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

int minDepth( TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int min_depth = INT_MAX;
    if (root->left != NULL) {
        min_depth = fmin(minDepth(root->left), min_depth);
    }
    if (root->right != NULL) {
        min_depth = fmin(minDepth(root->right), min_depth);
    }

    return min_depth + 1;
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

    cout << minDepth(root1) << endl;
    return 0;
}