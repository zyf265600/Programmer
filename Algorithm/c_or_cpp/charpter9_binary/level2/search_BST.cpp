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
// 迭代法
TreeNode *searchBST1(TreeNode *root, int val) {
        while (root) {
            if (val == root->val) {
                return root;
            }
            root = val < root->val ? root->left : root->right;
        }
        return nullptr;
    }

 //递归法
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (val == root->val)
    {
        return root;
    }
    return searchBST(val < root->val ? root->left : root->right, val);
}

int main()
{
    // 创建测试用例的二叉树
    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(8);
    TreeNode *res = searchBST(root1, 5);

    return 0;
}