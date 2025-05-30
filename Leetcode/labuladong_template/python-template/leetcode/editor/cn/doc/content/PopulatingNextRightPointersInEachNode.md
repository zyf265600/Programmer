<p>给定一个&nbsp;<strong>完美二叉树&nbsp;</strong>，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：</p>

<pre>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}</pre>

<p>填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 <code>NULL</code>。</p>

<p>初始状态下，所有&nbsp;next 指针都被设置为 <code>NULL</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="height: 171px; width: 500px;" /></p>

<pre>
<b>输入：</b>root = [1,2,3,4,5,6,7]
<b>输出：</b>[1,#,2,3,#,4,5,6,7,#]
<b>解释：</b>给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
</pre>

<p>
 <meta charset="UTF-8" /></p>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>root = []
<b>输出：</b>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li>树中节点的数量在
  <meta charset="UTF-8" />&nbsp;<code>[0, 2<sup>12</sup>&nbsp;- 1]</code>&nbsp;范围内</li> 
 <li><code>-1000 &lt;= node.val &lt;= 1000</code></li> 
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul> 
 <li>你只能使用常量级额外空间。</li> 
 <li>使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。</li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>树 | 深度优先搜索 | 广度优先搜索 | 链表 | 二叉树</details><br>

<div>👍 1187, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**



<p><strong><a href="https://labuladong.online/algo/data-structure/binary-tree-part1/" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

前文 [手把手刷二叉树总结篇](https://labuladong.online/algo/essential-technique/binary-tree-summary/) 说过二叉树的递归分为「遍历」和「分解问题」两种思维模式，这道题需要用到「遍历」的思维。

你可以把二叉树的相邻节点抽象成一个「三叉树节点」，这样二叉树就变成了一棵「三叉树」，然后你去遍历这棵三叉树，把每个「三叉树节点」中的两个节点连接就行了：

![](https://labuladong.online/algo/images/binary-tree-i/3.png)

**详细题解**：
  - [二叉树心法（思路篇）](https://labuladong.online/algo/data-structure/binary-tree-part1/)

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
    // 主函数
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        // 遍历「三叉树」，连接相邻节点
        traverse(root->left, root->right);
        return root;
    }

    // 三叉树遍历框架
    void traverse(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return;
        }
        // *** 前序位置 ***
        // 将传入的两个节点穿起来
        node1->next = node2;
        
        // 连接相同父节点的两个子节点
        traverse(node1->left, node1->right);
        traverse(node2->left, node2->right);
        // 连接跨越父节点的两个子节点
        traverse(node1->right, node2->left);
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    # 主函数
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        # 遍历「三叉树」，连接相邻节点
        self.traverse(root.left, root.right)
        return root

    # 三叉树遍历框架
    def traverse(self, node1: 'Node', node2: 'Node') -> None:
        if node1 is None or node2 is None:
            return
        # *** 前序位置 ***
        # 将传入的两个节点穿起来
        node1.next = node2
        
        # 连接相同父节点的两个子节点
        self.traverse(node1.left, node1.right)
        self.traverse(node2.left, node2.right)
        # 连接跨越父节点的两个子节点
        self.traverse(node1.right, node2.left)
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    // 主函数
    public Node connect(Node root) {
        if (root == null) return null;
        // 遍历「三叉树」，连接相邻节点
        traverse(root.left, root.right);
        return root;
    }

    // 三叉树遍历框架
    void traverse(Node node1, Node node2) {
        if (node1 == null || node2 == null) {
            return;
        }
        // *** 前序位置 ***
        // 将传入的两个节点穿起来
        node1.next = node2;
        
        // 连接相同父节点的两个子节点
        traverse(node1.left, node1.right);
        traverse(node2.left, node2.right);
        // 连接跨越父节点的两个子节点
        traverse(node1.right, node2.left);
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func connect(root *Node) *Node {
    // 主函数
    if root == nil {
        return nil
    }
    // 遍历「三叉树」，连接相邻节点
    traverse(root.Left, root.Right)
    return root
}

// 三叉树遍历框架
func traverse(node1, node2 *Node) {
    if node1 == nil || node2 == nil {
        return
    }
    // *** 前序位置 ***
    // 将传入的两个节点穿起来
    node1.Next = node2

    // 连接相同父节点的两个子节点
    traverse(node1.Left, node1.Right)
    traverse(node2.Left, node2.Right)
    // 连接跨越父节点的两个子节点
    traverse(node1.Right, node2.Left)
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

function Node(val, left, right, next) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
    this.next = next === undefined ? null : next;
}

// 主函数
var connect = function(root) {
    if (root === null) return null;
    // 遍历「三叉树」，连接相邻节点
    traverse(root.left, root.right);
    return root;
};

// 三叉树遍历框架
function traverse(node1, node2) {
    if (node1 === null || node2 === null) {
        return;
    }
    // *** 前序位置 ***
    // 将传入的两个节点穿起来
    node1.next = node2;
    
    // 连接相同父节点的两个子节点
    traverse(node1.left, node1.right);
    traverse(node2.left, node2.right);
    // 连接跨越父节点的两个子节点
    traverse(node1.right, node2.left);
}
```

</div></div>
</div></div>

</div>
</details>
</div>

