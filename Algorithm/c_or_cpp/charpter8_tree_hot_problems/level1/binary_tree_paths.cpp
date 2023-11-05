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

    void construct_paths(TreeNode* root, string path, vector<string>& paths) {
        if (root != nullptr) {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {  // 当前节点是叶子节点
                paths.push_back(path);                              // 把路径加入到答案中
            } else {
                path += "->";  // 当前节点不是叶子节点，继续递归遍历
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }
//主方法入口
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }

int main() {
    // 创建测试用例的二叉树
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);
  
    
  vector<string> path=binaryTreePaths(root1) ; 
    return 0;
}