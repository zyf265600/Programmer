#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
     TreeNode* left;
     TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printf("%d ", root->val); // 访问根节点
    preorderTraversal(root->left); // 递归遍历左子树
    preorderTraversal(root->right); // 递归遍历右子树
}

int main() {
    // 创建二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // 前序遍历二叉树并输出结果
    printf("Preorder traversal of binary tree is: ");
    preorderTraversal(root);
    printf("\n");

    // 释放二叉树内存空间
    free(root->left);
    free(root->right->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}