<p>给定一个二叉树，判断它是否是 <span data-keyword="height-balanced">平衡二叉树</span> &nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg" style="width: 342px; height: 221px;" /> 
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p> 
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg" style="width: 452px; height: 301px;" /> 
<pre>
<strong>输入：</strong>root = [1,2,2,3,3,null,null,4,4]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li>树中的节点数在范围 <code>[0, 5000]</code> 内</li> 
 <li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 二叉树</details><br>

<div>👍 1607, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

这里要用到前文 [手把手刷二叉树总结篇](https://labuladong.online/algo/essential-technique/binary-tree-summary/) 说过的后序位置的妙用。

一般的拍脑袋思路是，遍历二叉树，然后对每一个节点计算左右的最大高度。

但是计算一棵二叉树的最大深度也需要递归遍历这棵树的所有节点，如果对每个节点都算一遍最大深度，时间复杂度是比较高的。

所以最好的解法是反过来思考，只计算一次最大深度，计算的过程中在后序遍历位置顺便判断二叉树是否平衡：

对于每个节点，先算出来左右子树的最大高度，然后在后序遍历的位置根据左右子树的最大高度判断平衡性。

**详细题解**：
  - [【练习】利用后序位置解题 I](https://labuladong.online/algo/problem-set/binary-tree-post-order-i/)

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
    bool isBalanced(TreeNode* root) {
        checkBalanced(root);
        return balanced;
    }

private:
    // 记录二叉树是否平衡
    bool balanced = true;

    // 输入一个节点，返回以该节点为根的二叉树的最大深度
    int checkBalanced(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // if (!balanced) {
        // 随便返回一个值即可，旨在结束递归
        //     return -666;
        // }

        int leftMaxDepth = checkBalanced(root->left);
        int rightMaxDepth = checkBalanced(root->right);

        // 后序遍历位置
        // 如果左右最大深度大于 1，就不是平衡二叉树
        if (abs(rightMaxDepth - leftMaxDepth) > 1) {
            balanced = false;
        }

        return 1 + max(leftMaxDepth, rightMaxDepth);
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def __init__(self):
        # 记录二叉树是否平衡
        self.balanced = True

    def isBalanced(self, root: TreeNode) -> bool:
        self.maxDepth(root)
        return self.balanced

    # 输入一个节点，返回以该节点为根的二叉树的最大深度
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        # if not self.balanced:
        # 随便返回一个值即可，旨在结束递归
        #     return -666

        leftMaxDepth = self.maxDepth(root.left)
        rightMaxDepth = self.maxDepth(root.right)

        # 后序遍历位置
        # 如果左右最大深度大于 1，就不是平衡二叉树
        if abs(rightMaxDepth - leftMaxDepth) > 1:
            self.balanced = False

        return 1 + max(leftMaxDepth, rightMaxDepth)
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public boolean isBalanced(TreeNode root) {
        maxDepth(root);
        return isBalanced;
    }

    // 记录二叉树是否平衡
    boolean isBalanced = true;

    // 输入一个节点，返回以该节点为根的二叉树的最大深度
    int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // if (!isBalanced) {
        // 随便返回一个值即可，旨在结束递归
        //     return -666;
        // }

        int leftMaxDepth = maxDepth(root.left);
        int rightMaxDepth = maxDepth(root.right);

        // 后序遍历位置
        // 如果左右最大深度大于 1，就不是平衡二叉树
        if (Math.abs(rightMaxDepth - leftMaxDepth) > 1) {
            isBalanced = false;
        }

        return 1 + Math.max(leftMaxDepth, rightMaxDepth);
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func isBalanced(root *TreeNode) bool {
    // 记录二叉树是否平衡
    isBalanced := true
    maxDepth(root, &isBalanced)
    return isBalanced
}

// 输入一个节点，返回以该节点为根的二叉树的最大深度
func maxDepth(root *TreeNode, isBalanced *bool) int {
    if root == nil {
        return 0
    }

    // if !*isBalanced {
    // 随便返回一个值即可，旨在结束递归
    //     return -666
    // }

    leftMaxDepth := maxDepth(root.Left, isBalanced)
    rightMaxDepth := maxDepth(root.Right, isBalanced)

    // 后序遍历位置
    // 如果左右最大深度大于 1，就不是平衡二叉树
    if abs(leftMaxDepth-rightMaxDepth) > 1 {
        *isBalanced = false
    }

    return 1 + max(leftMaxDepth, rightMaxDepth)
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var isBalanced = function(root) {
    // 记录二叉树是否平衡
    let isBalanced = true;

    // 输入一个节点，返回以该节点为根的二叉树的最大深度
    var maxDepth = function(root) {
        if (root === null) {
            return 0;
        }
        // if (!isBalanced) {
        // 随便返回一个值即可，旨在结束递归
        //     return -666;
        // }

        let leftMaxDepth = maxDepth(root.left);
        let rightMaxDepth = maxDepth(root.right);

        // 后序遍历位置
        // 如果左右最大深度大于 1，就不是平衡二叉树
        if (Math.abs(rightMaxDepth - leftMaxDepth) > 1) {
            isBalanced = false;
        }

        return 1 + Math.max(leftMaxDepth, rightMaxDepth);
    };

    maxDepth(root);
    return isBalanced;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🥳🥳 算法可视化 🥳🥳</strong></summary><div id="data_balanced-binary-tree"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_balanced-binary-tree"></div></div>
</details><hr /><br />

</div>
</details>
</div>

