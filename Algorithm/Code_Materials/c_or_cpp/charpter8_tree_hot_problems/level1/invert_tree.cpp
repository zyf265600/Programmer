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
// 前序
 TreeNode* invertTree1( TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
     TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree1(root->left);
    invertTree1(root->right);
    return root;
}


// 后序法
TreeNode *invertTree2(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *left = invertTree2(root->left);
    TreeNode *right = invertTree2(root->right);
    root->left = right;
    root->right = left;
    return root;
}

// 层次遍历
TreeNode* invertTree3(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                swap(node->left, node->right); // 节点处理
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
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

    TreeNode * tree = invertTree2(root1);
 
    return 0;
}