#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> largestValues(TreeNode* root) {
       
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            int maxVal = INT_MIN;
            while (len > 0) {
                len--;
                auto t = q.front();
                q.pop();
                maxVal = max(maxVal, t->val);
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
            res.push_back(maxVal);
        }
        return res;
    }

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
 
   vector<int> res= largestValues(root);
       for (auto &row : res)
    {
        cout << row << " ";

        cout << endl;
    }
    return 0;
}