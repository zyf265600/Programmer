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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL && right == NULL)
    {
        return NULL; // 1.
    }
    if (left == NULL)
    {
        return right; // 3.
    }
    if (right == NULL)
    {
        return left; // 4.
    }
    return root; // 2. if(left != null and right != null)
}

int main()
{
    // 创建测试用例的二叉树
    // 创建树根节点
    TreeNode *root = new TreeNode(1);

    // 创建节点p和q
    TreeNode *p = new TreeNode(3);
    TreeNode *q = new TreeNode(2);
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(4);
    TreeNode *q1 = new TreeNode(6);

    // 创建节点p和q的子节点
    p->left = p1;
    p->right = p2;
    q->left = q1;

    // 将节点p和q插入到树中
    root->left = p;
    root->right = q;

   TreeNode *tree =lowestCommonAncestor(root, p, q)  ;
    return 0;
}