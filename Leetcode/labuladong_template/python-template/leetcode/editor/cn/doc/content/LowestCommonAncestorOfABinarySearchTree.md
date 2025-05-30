<p>给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin" target="_blank">百度百科</a>中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。”</p>

<p>例如，给定如下二叉搜索树:&nbsp; root =&nbsp;[6,2,8,0,4,7,9,null,null,3,5]</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png" style="height: 190px; width: 200px;" /></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>输出:</strong> 6 
<strong>解释: </strong>节点 <span><code>2 </code></span>和节点 <span><code>8 </code></span>的最近公共祖先是 <span><code>6。</code></span>
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>输出:</strong> 2
<strong>解释: </strong>节点 <span><code>2</code></span> 和节点 <span><code>4</code></span> 的最近公共祖先是 <span><code>2</code></span>, 因为根据定义最近公共祖先节点可以为节点本身。</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul> 
 <li>所有节点的值都是唯一的。</li> 
 <li>p、q 为不同节点且均存在于给定的二叉搜索树中。</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 二叉搜索树 | 二叉树</details><br>

<div>👍 1322, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**



<p><strong><a href="https://labuladong.online/algo/practice-in-action/lowest-common-ancestor-summary/" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

比较经典的是 [✨236. 二叉树的最近公共祖先](/problems/lowest-common-ancestor-of-a-binary-tree/)，我在 [这篇文章](https://labuladong.online/algo/practice-in-action/lowest-common-ancestor-summary/) 讲了那道题的解法。

如果在 BST 中寻找最近公共祖先，反而容易很多，主要利用 BST 左小右大（左子树所有节点都比当前节点小，右子树所有节点都比当前节点大）的特点即可。

1、如果 `p` 和 `q` 都比当前节点小，那么显然 `p` 和 `q` 都在左子树，那么 LCA 在左子树。

2、如果 `p` 和 `q` 都比当前节点大，那么显然 `p` 和 `q` 都在右子树，那么 LCA 在右子树。

3、一旦发现 `p` 和 `q` 在当前节点的两侧，说明当前节点就是 LCA。

**详细题解**：
  - [拓展：最近公共祖先系列解题框架](https://labuladong.online/algo/practice-in-action/lowest-common-ancestor-summary/)

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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p->val > q->val) {
            // 保证 p.val <= q.val，便于后续情况讨论
            return lowestCommonAncestor(root, q, p);
        }
        if (root->val >= p->val && root->val <= q->val) {
            // p <= root <= q
            // 即 p 和 q 分别在 root 的左右子树，那么 root 就是 LCA
            return root;
        }
        if (root->val > q->val) {
            // p 和 q 都在 root 的左子树，那么 LCA 在左子树
            return lowestCommonAncestor(root->left, p, q);
        } else {
            // p 和 q 都在 root 的右子树，那么 LCA 在右子树
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if root is None:
            return None
        if p.val > q.val:
            # 保证 p.val <= q.val，便于后续情况讨论
            return self.lowestCommonAncestor(root, q, p)
        if root.val >= p.val and root.val <= q.val:
            # p <= root <= q
            # 即 p 和 q 分别在 root 的左右子树，那么 root 就是 LCA
            return root
        if root.val > q.val:
            # p 和 q 都在 root 的左子树，那么 LCA 在左子树
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            # p 和 q 都在 root 的右子树，那么 LCA 在右子树
            return self.lowestCommonAncestor(root.right, p, q)
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (p.val > q.val) {
            // 保证 p.val <= q.val，便于后续情况讨论
            return lowestCommonAncestor(root, q, p);
        }
        if (root.val >= p.val && root.val <= q.val) {
            // p <= root <= q
            // 即 p 和 q 分别在 root 的左右子树，那么 root 就是 LCA
            return root;
        }
        if (root.val > q.val) {
            // p 和 q 都在 root 的左子树，那么 LCA 在左子树
            return lowestCommonAncestor(root.left, p, q);
        } else {
            // p 和 q 都在 root 的右子树，那么 LCA 在右子树
            return lowestCommonAncestor(root.right, p, q);
        }
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == nil {
        return nil
    }
    if p.Val > q.Val {
        // 保证 p.val <= q.val，便于后续情况讨论
        return lowestCommonAncestor(root, q, p)
    }
    if root.Val >= p.Val && root.Val <= q.Val {
        // p <= root <= q
        // 即 p 和 q 分别在 root 的左右子树，那么 root 就是 LCA
        return root
    }
    if root.Val > q.Val {
        // p 和 q 都在 root 的左子树，那么 LCA 在左子树
        return lowestCommonAncestor(root.Left, p, q)
    } else {
        // p 和 q 都在 root 的右子树，那么 LCA 在右子树
        return lowestCommonAncestor(root.Right, p, q)
    }
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var lowestCommonAncestor = function(root, p, q) {
    if (root === null) return null;
    if (p.val > q.val) {
        // 保证 p.val <= q.val，便于后续情况讨论
        return lowestCommonAncestor(root, q, p);
    }
    if (root.val >= p.val && root.val <= q.val) {
        // p <= root <= q
        // 即 p 和 q 分别在 root 的左右子树，那么 root 就是 LCA
        return root;
    }
    if (root.val > q.val) {
        // p 和 q 都在 root 的左子树，那么 LCA 在左子树
        return lowestCommonAncestor(root.left, p, q);
    } else {
        // p 和 q 都在 root 的右子树，那么 LCA 在右子树
        return lowestCommonAncestor(root.right, p, q);
    }
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🌈🌈 算法可视化 🌈🌈</strong></summary><div id="data_lowest-common-ancestor-of-a-binary-search-tree"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_lowest-common-ancestor-of-a-binary-search-tree"></div></div>
</details><hr /><br />

</div>
</details>
</div>

