<p>给定一个二叉树的 <strong>根节点</strong> <code>root</code>，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block"> 
 <p><span class="example-io"><b>输入：</b>root = [1,2,3,null,5,null,4]</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">[1,3,4]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/24/tmpd5jn43fs-1.png" style="width: 400px; height: 207px;" /></p>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block"> 
 <p><span class="example-io"><b>输入：</b>root = [1,2,3,4,null,null,null,5]</span></p> 
</div>

<p><span class="example-io"><b>输出：</b>[1,3,4,5]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/24/tmpkpe40xeh-1.png" style="width: 400px; height: 214px;" /></p>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block"> 
 <p><strong>输入：</strong><span class="example-io">root = [1,null,3]</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">[1,3]</span></p>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block"> 
 <p><span class="example-io"><b>输入：</b>root = []</span></p> 
</div>

<p><strong>输出：</strong><span class="example-io">[]</span></p>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul> 
 <li>二叉树的节点个数的范围是 <code>[0,100]</code></li> 
 <li>
  <meta charset="UTF-8" /><code>-100&nbsp;&lt;= Node.val &lt;= 100</code>&nbsp;</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 广度优先搜索 | 二叉树</details><br>

<div>👍 1208, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这题有两个思路：

1、用 BFS 层序遍历算法，每一层的最后一个节点就是二叉树的右侧视图。我们可以把 BFS 反过来，从右往左遍历每一行，进一步提升效率。

2、用 DFS 递归遍历算法，同样需要反过来，先递归 `root.right` 再递归 `root.left`，同时用 `res` 记录每一层的最右侧节点作为右侧视图。

**详细题解**：
  - [【练习】用「遍历」思维解题 I](https://labuladong.online/algo/problem-set/binary-tree-traverse-i/)

</div>





<div id="solution">

## 解法代码



<div class="tab-panel"><div class="tab-nav">
<button data-tab-item="cpp" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">cpp🤖</button>

<button data-tab-item="python" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">python🤖</button>

<button data-tab-item="java" class="tab-nav-button btn active" data-tab-group="default" onclick="switchTab(this)">java🟢</button>

<button data-tab-item="go" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">go🤖</button>

<button data-tab-item="javascript" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">javascript🤖</button>
</div><div class="tab-content">
<div data-tab-item="cpp" class="tab-item " data-tab-group="default"><div class="highlight">

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

#include <vector>
#include <queue>
using namespace std;

class Solution {

public:
    // BFS 层序遍历解法
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        // BFS 层序遍历，计算右侧视图
        queue<TreeNode*> q;
        q.push(root);
        // while 循环控制从上向下一层层遍历
        while (!q.empty()) {
            int sz = q.size();
            // 每一层头部就是最右侧的元素
            TreeNode* last = q.front();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                // 控制每一层从右向左遍历
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
            }
            // 每一层的最后一个节点就是二叉树的右侧视图
            res.push_back(last->val);
        }
        return res;
    }

    // DFS 递归遍历解法
    vector<int> rightSideView_DFS(TreeNode* root) {
        res.clear();
        depth = 0;
        traverse(root);
        return res;
    }

private:
    vector<int> res;
    // 记录递归的层数
    int depth = 0;

    // 二叉树遍历函数
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // 前序遍历位置
        depth++;
        if (res.size() < depth) {
            // 这一层还没有记录值
            // 说明 root 就是右侧视图的第一个节点
            res.push_back(root->val);
        }
        // 注意，这里反过来，先遍历右子树再遍历左子树
        // 这样首先遍历的一定是右侧节点
        traverse(root->right);
        traverse(root->left);
        // 后序遍历位置
        depth--;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

from collections import deque

class Solution:
    # BFS 层序遍历解法
    def rightSideView(self, root) -> list:
        res = []
        if root is None:
            return res
        # BFS 层序遍历，计算右侧视图
        q = deque([root])
        # while 循环控制从上向下一层层遍历
        while q:
            sz = len(q)
            # 每一层头部就是最右侧的元素
            last = q[0]
            for i in range(sz):
                cur = q.popleft()
                # 控制每一层从右向左遍历
                if cur.right:
                    q.append(cur.right)
                if cur.left:
                    q.append(cur.left)
            # 每一层的最后一个节点就是二叉树的右侧视图
            res.append(last.val)
        return res

    # DFS 递归遍历解法
    def rightSideView_DFS(self, root) -> list:
        self.res = []
        # 记录递归的层数
        self.depth = 0
        self.traverse(root)
        return self.res

    # 二叉树遍历函数
    def traverse(self, root):
        if root is None:
            return
        # 前序遍历位置
        self.depth += 1
        if len(self.res) < self.depth:
            # 这一层还没有记录值
            # 说明 root 就是右侧视图的第一个节点
            self.res.append(root.val)
        # 注意，这里反过来，先遍历右子树再遍历左子树
        # 这样首先遍历的一定是右侧节点
        self.traverse(root.right)
        self.traverse(root.left)
        # 后序遍历位置
        self.depth -= 1
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {

    // BFS 层序遍历解法
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        // BFS 层序遍历，计算右侧视图
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        // while 循环控制从上向下一层层遍历
        while (!q.isEmpty()) {
            int sz = q.size();
            // 每一层头部就是最右侧的元素
            TreeNode last = q.peek();
            for (int i = 0; i < sz; i++) {
                TreeNode cur = q.poll();
                // 控制每一层从右向左遍历
                if (cur.right != null) {
                    q.offer(cur.right);
                }
                if (cur.left != null) {
                    q.offer(cur.left);
                }
            }
            // 每一层的最后一个节点就是二叉树的右侧视图
            res.add(last.val);
        }
        return res;
    }

    // DFS 递归遍历解法
    List<Integer> res = new ArrayList<>();
    // 记录递归的层数
    int depth = 0;

    public List<Integer> rightSideView_DFS(TreeNode root) {
        traverse(root);
        return res;
    }

    // 二叉树遍历函数
    void traverse(TreeNode root) {
        if (root == null) {
            return;
        }
        // 前序遍历位置
        depth++;
        if (res.size() < depth) {
            // 这一层还没有记录值
            // 说明 root 就是右侧视图的第一个节点
            res.add(root.val);
        }
        // 注意，这里反过来，先遍历右子树再遍历左子树
        // 这样首先遍历的一定是右侧节点
        traverse(root.right);
        traverse(root.left);
        // 后序遍历位置
        depth--;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

// BFS 层序遍历解法
func rightSideView(root *TreeNode) []int {
    if root == nil {
        return []int{}
    }
    // BFS 层序遍历，计算右侧视图
    var res []int
    q := []*TreeNode{root}
    // while 循环控制从上向下一层层遍历
    for len(q) > 0 {
        sz := len(q)
        // 每一层头部就是最右侧的元素
        last := q[0].Val
        for i := 0; i < sz; i++ {
            cur := q[0]
            q = q[1:]
            // 控制每一层从右向左遍历
            if cur.Right != nil {
                q = append(q, cur.Right)
            }
            if cur.Left != nil {
                q = append(q, cur.Left)
            }
        }
        // 每一层的最后一个节点就是二叉树的右侧视图
        res = append(res, last)
    }
    return res
}

// DFS 递归遍历解法
func rightSideViewDFS(root *TreeNode) []int {
    res := []int{}
    // 记录递归的层数
    traverse(root, 0, &res)
    return res
}

// 二叉树遍历函数
func traverse(root *TreeNode, depth int, res *[]int) {
    if root == nil {
        return
    }
    // 前序遍历位置
    if len(*res) == depth {
        // 这一层还没有记录值
        // 说明 root 就是右侧视图的第一个节点
        *res = append(*res, root.Val)
    }
    // 注意，这里反过来，先遍历右子树再遍历左子树
    // 这样首先遍历的一定是右侧节点
    traverse(root.Right, depth+1, res)
    traverse(root.Left, depth+1, res)
    // 后序遍历位置
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

// BFS 层序遍历解法
var rightSideView = function(root) {
    let res = [];
    if (root === null) {
        return res;
    }
    // BFS 层序遍历，计算右侧视图
    let q = [];
    q.push(root);
    // while 循环控制从上向下一层层遍历
    while (q.length > 0) {
        let sz = q.length;
        // 每一层头部就是最右侧的元素
        let last = q[0];
        for (let i = 0; i < sz; i++) {
            let cur = q.shift();
            // 控制每一层从右向左遍历
            if (cur.right !== null) {
                q.push(cur.right);
            }
            if (cur.left !== null) {
                q.push(cur.left);
            }
        }
        // 每一层的最后一个节点就是二叉树的右侧视图
        res.push(last.val);
    }
    return res;
};

// DFS 递归遍历解法
var rightSideView_DFS = function(root) {
    let res = [];
    // 记录递归的层数
    let depth = 0;

    // 二叉树遍历函数
    var traverse = function(root) {
        if (root === null) {
            return;
        }
        // 前序遍历位置
        depth++;
        if (res.length < depth) {
            // 这一层还没有记录值
            // 说明 root 就是右侧视图的第一个节点
            res.push(root.val);
        }
        // 注意，这里反过来，先遍历右子树再遍历左子树
        // 这样首先遍历的一定是右侧节点
        traverse(root.right);
        traverse(root.left);
        // 后序遍历位置
        depth--;
    };

    traverse(root);
    return res;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🥳🥳 算法可视化 🥳🥳</strong></summary><div id="data_binary-tree-right-side-view"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_binary-tree-right-side-view"></div></div>
</details><hr /><br />

</div>
</details>
</div>

