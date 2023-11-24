
 #include <stdlib.h>
#include <stdio.h>
 struct TreeNode {
      int val; //代表数据
      struct TreeNode *left; //代表左子树
	 struct TreeNode *right; //代表右子树
    
 };


// 构造如下二叉树
//     3
//    / \
//   9  20
//     /  \
//    15   7

 struct TreeNode *initTree()
{


//      // 1、创建根指针
//      struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//      root->val=3;

//      struct TreeNode *node_9 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//      node_9->val=9;

//      node_9->left=node_9->right=nullptr; 

//      struct TreeNode *node_20 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//      node_20->val=20;

//     root->left=node_9;
//     root->right=node_20;

//      struct TreeNode *node_15 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//      node_15->val=15;
//      node_15->left=node_15->right=nullptr; 

//     struct TreeNode *node_7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//      node_7->val=7;
//      node_7->left=node_7->right=nullptr; 

//     node_20->left=node_15;
//     node_20->right=node_7;

//      return root;

     
}

 
