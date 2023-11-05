#include <iostream>
#include <vector>
#include <queue>

//  N叉树的层次遍历
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

 vector<vector<int> > levelOrder(Node* root) {
       
        vector<vector<int> > ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; ++i) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (Node* child: cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(move(level));
        }

        return ans;
    }

int main() {
    // 创建二叉树，这里以一个示例二叉树为例，具体实现可以根据实际情况进行修改。
     Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    root->children.push_back(node2);
    root->children.push_back(node3);
    node2->children.push_back(node4);
    node2->children.push_back(node5);
    node3->children.push_back(node6);
    node3->children.push_back(node7);
    node4->children.push_back(node8);
 
    vector<vector<int> > res = levelOrder(root);
    for (auto& row : res) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}