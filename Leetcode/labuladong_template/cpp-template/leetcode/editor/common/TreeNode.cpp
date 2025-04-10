#include <vector>
#include <iostream>
#include <queue>
#include <optional>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }

    static TreeNode *createRoot(const std::vector<std::optional<int> > &values) {
        if (values.empty() || !values[0].has_value()) return nullptr;
        TreeNode *root = new TreeNode(values[0].value());
        std::queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        size_t i = 1;
        while (i < values.size()) {
            TreeNode *current = nodeQueue.front();
            nodeQueue.pop();
            if (i < values.size() && values[i].has_value()) {
                current->left = new TreeNode(values[i].value());
                nodeQueue.push(current->left);
            }
            i++;
            if (i < values.size() && values[i].has_value()) {
                current->right = new TreeNode(values[i].value());
                nodeQueue.push(current->right);
            }
            i++;
        }
        return root;
    }

    static void freeTree(TreeNode *root) {
        if (!root) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }

    // 打印整棵二叉树
    static void print(TreeNode *root) {
        int h = getHeight(root);
        int rows = h * 2 - 1;
        int cols = (1 << h) - 1; // 2^h - 1
        vector<vector<char>> mat(rows, vector<char>(cols, ' '));

        fillTree(root, 0, 0, cols - 1, h, mat);

        for (const auto &row : mat) {
            for (char ch : row) {
                cout << ch;
            }
            cout << endl;
        }
    }

private:
    // 计算树的高度，改为静态方法
    static int getHeight(TreeNode *node) {
        if (!node) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // 递归填充字符矩阵
    // level: 当前节点所在的层（根层为 0）
    // left, right: 当前区域左右边界
    // totalHeight: 树的总高度
    static void fillTree(TreeNode *node, int level, int left, int right, int totalHeight, vector<vector<char> > &mat) {
        if (!node) return;
        int mid = (left + right) / 2;
        string valStr = to_string(node->val);
        int offset = (valStr.size() - 1) / 2;  // 计算偏移量，使数字居中
        for (int i = 0; i < valStr.size() && (mid - offset + i) < mat[level * 2].size(); i++) {
            mat[level * 2][mid - offset + i] = valStr[i];
        }
        // 若已经到达叶子层，则无需绘制分支
        if (level == totalHeight - 1) return;
        // 绘制左分支
        if (node->left) {
            int branchPos = (left + mid) / 2;
            mat[level * 2 + 1][branchPos] = '/';
            fillTree(node->left, level + 1, left, mid - 1, totalHeight, mat);
        }
        // 绘制右分支
        if (node->right) {
            int branchPos = (mid + 1 + right) / 2;
            mat[level * 2 + 1][branchPos] = '\\';
            fillTree(node->right, level + 1, mid + 1, right, totalHeight, mat);
        }
    }
};
