<p>给定两个整数数组，<code>preorder</code>&nbsp;和 <code>postorder</code> ，其中 <code>preorder</code> 是一个具有 <strong>无重复</strong> 值的二叉树的前序遍历，<code>postorder</code> 是同一棵树的后序遍历，重构并返回二叉树。</p>

<p>如果存在多个答案，您可以返回其中 <strong>任何</strong> 一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/07/24/lc-prepost.jpg" style="height: 265px; width: 304px;" /></p>

<pre>
<strong>输入：</strong>preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
<strong>输出：</strong>[1,2,3,4,5,6,7]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> preorder = [1], postorder = [1]
<strong>输出:</strong> [1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>1 &lt;= preorder.length &lt;= 30</code></li> 
 <li><code>1 &lt;= preorder[i] &lt;= preorder.length</code></li> 
 <li><code>preorder</code>&nbsp;中所有值都 <strong>不同</strong></li> 
 <li><code>postorder.length == preorder.length</code></li> 
 <li><code>1 &lt;= postorder[i] &lt;= postorder.length</code></li> 
 <li><code>postorder</code>&nbsp;中所有值都 <strong>不同</strong></li> 
 <li>保证 <code>preorder</code>&nbsp;和 <code>postorder</code>&nbsp;是同一棵二叉树的前序遍历和后序遍历</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 数组 | 哈希表 | 分治 | 二叉树</details><br>

<div>👍 413, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**



<p><strong><a href="https://labuladong.online/algo/data-structure/binary-tree-part2/" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

做这道题之前，建议你先看一下 [二叉树心法（构造篇）](https://labuladong.online/algo/data-structure/binary-tree-part2/)，做一下 [✨105. 从前序与中序遍历序列构造二叉树（中等）](/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 和 [✨106. 从中序与后序遍历序列构造二叉树（中等）](/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 这两道题。

这道题让用后序遍历和前序遍历结果还原二叉树，和前两道题有一个本质的区别：

**通过前序中序，或者后序中序遍历结果可以确定一棵原始二叉树，但是通过前序后序遍历结果无法确定原始二叉树**。题目也说了，如果有多种结果，你可以返回任意一种。

为什么呢？我们说过，构建二叉树的套路很简单，先找到根节点，然后找到并递归构造左右子树即可。

前两道题，可以通过前序或者后序遍历结果找到根节点，然后根据中序遍历结果确定左右子树。

这道题，你可以确定根节点，但是无法确切的知道左右子树有哪些节点。

举个例子，下面这两棵树结构不同，但是它们的前序遍历和后序遍历结果是相同的：

![](https://labuladong.online/algo/images/binary-tree-ii/7.png)

不过话说回来，用后序遍历和前序遍历结果还原二叉树，解法逻辑上和前两道题差别不大，也是通过控制左右子树的索引来构建：

**1、首先把前序遍历结果的第一个元素或者后序遍历结果的最后一个元素确定为根节点的值**。

**2、然后把前序遍历结果的第二个元素作为左子树的根节点的值**。

**3、在后序遍历结果中寻找左子树根节点的值，从而确定了左子树的索引边界，进而确定右子树的索引边界，递归构造左右子树即可**。

![](https://labuladong.online/algo/images/binary-tree-ii/8.jpeg)

**详细题解**：
  - [二叉树心法（构造篇）](https://labuladong.online/algo/data-structure/binary-tree-part2/)
  - [【练习】用「分解问题」思维解题 I](https://labuladong.online/algo/problem-set/binary-tree-divide-i/)

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
    // 存储 postorder 中值到索引的映射
    unordered_map<int, int> valToIndex;

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            valToIndex[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }

    // 定义：根据 preorder[preStart..preEnd] 和 postorder[postStart..postEnd]
    // 构建二叉树，并返回根节点。
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // root 节点对应的值就是前序遍历数组的第一个元素
        int rootVal = preorder[preStart];
        // root.left 的值是前序遍历第二个元素
        // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
        // 确定 preorder 和 postorder 中左右子树的元素区间
        int leftRootVal = preorder[preStart + 1];
        // leftRootVal 在后序遍历数组中的索引
        int index = valToIndex[leftRootVal];
        // 左子树的元素个数
        int leftSize = index - postStart + 1;

        // 先构造出当前根节点
        TreeNode* root = new TreeNode(rootVal);

        // 递归构造左右子树
        // 根据左子树的根节点索引和元素个数推导左右子树的索引边界
        root->left = build(preorder, preStart + 1, preStart + leftSize,
                           postorder, postStart, index);
        root->right = build(preorder, preStart + leftSize + 1, preEnd,
                            postorder, index + 1, postEnd - 1);

        return root;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    # 存储 postorder 中值到索引的映射
    def __init__(self):
        self.valToIndex = {}

    def constructFromPrePost(self, preorder, postorder):
        for i in range(len(postorder)):
            self.valToIndex[postorder[i]] = i
        return self.build(preorder, 0, len(preorder) - 1,
                          postorder, 0, len(postorder) - 1)

    # 定义：根据 preorder[preStart..preEnd] 和 postorder[postStart..postEnd]
    # 构建二叉树，并返回根节点。
    def build(self, preorder, preStart, preEnd, postorder, postStart, postEnd):
        if preStart > preEnd:
            return None
        if preStart == preEnd:
            return TreeNode(preorder[preStart])

        # root 节点对应的值就是前序遍历数组的第一个元素
        rootVal = preorder[preStart]
        # root.left 的值是前序遍历第二个元素
        # 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
        # 确定 preorder 和 postorder 中左右子树的元素区间
        leftRootVal = preorder[preStart + 1]
        # leftRootVal 在后序遍历数组中的索引
        index = self.valToIndex[leftRootVal]
        # 左子树的元素个数
        leftSize = index - postStart + 1

        # 先构造出当前根节点
        root = TreeNode(rootVal)
        # 递归构造左右子树
        # 根据左子树的根节点索引和元素个数推导左右子树的索引边界
        root.left = self.build(preorder, preStart + 1, preStart + leftSize,
                               postorder, postStart, index)
        root.right = self.build(preorder, preStart + leftSize + 1, preEnd,
                                postorder, index + 1, postEnd - 1)

        return root
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    // 存储 postorder 中值到索引的映射
    HashMap<Integer, Integer> valToIndex = new HashMap<>();

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        for (int i = 0; i < postorder.length; i++) {
            valToIndex.put(postorder[i], i);
        }
        return build(preorder, 0, preorder.length - 1,
                    postorder, 0, postorder.length - 1);
    }

    // 定义：根据 preorder[preStart..preEnd] 和 postorder[postStart..postEnd]
    // 构建二叉树，并返回根节点。
    TreeNode build(int[] preorder, int preStart, int preEnd,
                   int[] postorder, int postStart, int postEnd) {
        if (preStart > preEnd) {
            return null;
        }
        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // root 节点对应的值就是前序遍历数组的第一个元素
        int rootVal = preorder[preStart];
        // root.left 的值是前序遍历第二个元素
        // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
        // 确定 preorder 和 postorder 中左右子树的元素区间
        int leftRootVal = preorder[preStart + 1];
        // leftRootVal 在后序遍历数组中的索引
        int index = valToIndex.get(leftRootVal);
        // 左子树的元素个数
        int leftSize = index - postStart + 1;

        // 先构造出当前根节点
        TreeNode root = new TreeNode(rootVal);/**<extend up -200>![](https://labuladong.online/algo/images/binary-tree-ii/8.jpeg) */
        // 递归构造左右子树
        // 根据左子树的根节点索引和元素个数推导左右子树的索引边界
        root.left = build(preorder, preStart + 1, preStart + leftSize,
                postorder, postStart, index);
        root.right = build(preorder, preStart + leftSize + 1, preEnd,
                postorder, index + 1, postEnd - 1);

        return root;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
    // 存储 postorder 中值到索引的映射
    valToIndex := make(map[int]int)
    for i, val := range postorder {
        valToIndex[val] = i
    }
    return build(preorder, 0, len(preorder)-1, postorder, 0, len(postorder)-1, valToIndex)
}

// 定义：根据 preorder[preStart..preEnd] 和 postorder[postStart..postEnd]
// 构建二叉树，并返回根节点。
func build(preorder []int, preStart int, preEnd int, postorder []int, postStart int, postEnd int, valToIndex map[int]int) *TreeNode {
    if preStart > preEnd {
        return nil
    }
    if preStart == preEnd {
        return &TreeNode{Val: preorder[preStart]}
    }

    // root 节点对应的值就是前序遍历数组的第一个元素
    rootVal := preorder[preStart]
    // root.left 的值是前序遍历第二个元素
    // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
    // 确定 preorder 和 postorder 中左右子树的元素区间
    leftRootVal := preorder[preStart+1]
    // leftRootVal 在后序遍历数组中的索引
    index := valToIndex[leftRootVal]
    // 左子树的元素个数
    leftSize := index - postStart + 1

    // 先构造出当前根节点
    root := &TreeNode{Val: rootVal}
    // 递归构造左右子树
    // 根据左子树的根节点索引和元素个数推导左右子树的索引边界
    root.Left = build(preorder, preStart+1, preStart+leftSize, postorder, postStart, index, valToIndex)
    root.Right = build(preorder, preStart+leftSize+1, preEnd, postorder, index+1, postEnd-1, valToIndex)

    return root
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var constructFromPrePost = function(preorder, postorder) {
    // 存储 postorder 中值到索引的映射
    const valToIndex = new Map();
    for (let i = 0; i < postorder.length; i++) {
        valToIndex.set(postorder[i], i);
    }
    function build(preorder, preStart, preEnd, postorder, postStart, postEnd) {
        // 定义：根据 preorder[preStart..preEnd] 和 postorder[postStart..postEnd]
        // 构建二叉树，并返回根节点。
        if (preStart > preEnd) {
            return null;
        }
        if (preStart === preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        // root 节点对应的值就是前序遍历数组的第一个元素
        const rootVal = preorder[preStart];
        // root.left 的值是前序遍历第二个元素
        // 通过前序和后序遍历构造二叉树的关键在于通过左子树的根节点
        // 确定 preorder 和 postorder 中左右子树的元素区间
        const leftRootVal = preorder[preStart + 1];
        // leftRootVal 在后序遍历数组中的索引
        const index = valToIndex.get(leftRootVal);
        // 左子树的元素个数
        const leftSize = index - postStart + 1;

        // 先构造出当前根节点
        const root = new TreeNode(rootVal);
        // 递归构造左右子树
        // 根据左子树的根节点索引和元素个数推导左右子树的索引边界
        root.left = build(preorder, preStart + 1, preStart + leftSize, postorder, postStart, index);
        root.right = build(preorder, preStart + leftSize + 1, preEnd, postorder, index + 1, postEnd - 1);

        return root;
    }
    return build(preorder, 0, preorder.length - 1, postorder, 0, postorder.length - 1);
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🎃🎃 算法可视化 🎃🎃</strong></summary><div id="data_construct-binary-tree-from-preorder-and-postorder-traversal"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_construct-binary-tree-from-preorder-and-postorder-traversal"></div></div>
</details><hr /><br />

</div>
</details>
</div>

