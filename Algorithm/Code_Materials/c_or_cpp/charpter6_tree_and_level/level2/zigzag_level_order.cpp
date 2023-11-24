#include <iostream>
#include <vector>
#include <queue>

 
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) return ans;
        deque<TreeNode*> que;
        que.push_back(root);
        bool zigzag = true;
        TreeNode* tmp;
        while (!que.empty()) {
            int Size = que.size();
            vector<int> tmp_vec;
            while (Size) { 
                if (zigzag) { // 前取后放
                    tmp = que.front();
                    que.pop_front();
                    if (tmp->left) que.push_back(tmp->left);
                    if (tmp->right) que.push_back(tmp->right);                
                } else { //后取前放
                    tmp = que.back();
                    que.pop_back();
                    if (tmp->right) que.push_front(tmp->right);
                    if (tmp->left) que.push_front(tmp->left);
                }
                tmp_vec.push_back(tmp->val);
                --Size;
            }
            zigzag = !zigzag;
            ans.push_back(tmp_vec);
        }
        return ans;
    }



int main() {
    // 创建二叉树，这里以一个示例二叉树为例，具体实现可以根据实际情况进行修改。
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

     
    vector<vector<int> > res = zigzagLevelOrder(root);
    for (auto& row : res) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}