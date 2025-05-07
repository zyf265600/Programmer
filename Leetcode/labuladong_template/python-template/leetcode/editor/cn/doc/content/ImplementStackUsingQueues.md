<p>请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（<code>push</code>、<code>top</code>、<code>pop</code> 和 <code>empty</code>）。</p>

<p>实现 <code>MyStack</code> 类：</p>

<ul> 
 <li><code>void push(int x)</code> 将元素 x 压入栈顶。</li> 
 <li><code>int pop()</code> 移除并返回栈顶元素。</li> 
 <li><code>int top()</code> 返回栈顶元素。</li> 
 <li><code>boolean empty()</code> 如果栈是空的，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li> 
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong></p>

<ul> 
 <li>你只能使用队列的标准操作 —— 也就是&nbsp;<code>push to back</code>、<code>peek/pop from front</code>、<code>size</code> 和&nbsp;<code>is empty</code>&nbsp;这些操作。</li> 
 <li>你所使用的语言也许不支持队列。&nbsp;你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列&nbsp;, 只要是标准的队列操作即可。</li> 
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>输出：</strong>
[null, null, null, 2, 2, false]

<strong>解释：</strong>
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>1 &lt;= x &lt;= 9</code></li> 
 <li>最多调用<code>100</code> 次 <code>push</code>、<code>pop</code>、<code>top</code> 和 <code>empty</code></li> 
 <li>每次调用 <code>pop</code> 和 <code>top</code> 都保证栈不为空</li> 
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否仅用一个队列来实现栈。</p>

<details><summary><strong>Related Topics</strong></summary>栈 | 设计 | 队列</details><br>

<div>👍 945, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**



<p><strong><a href="https://labuladong.online/algo/data-structure/stack-queue/" target="_blank">⭐️labuladong 题解</a></strong></p>
<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

底层用队列实现栈就比较简单粗暴了，只需要一个队列作为底层数据结构。

底层队列只能向队尾添加元素，所以栈的 `pop` API 相当于要从队尾取元素：

![](https://labuladong.online/algo/images/stack-queue/5.jpg)

那么最简单的思路就是，把队尾元素前面的所有元素重新塞到队尾，让队尾元素排到队头，这样就可以取出了：

![](https://labuladong.online/algo/images/stack-queue/6.jpg)

**详细题解**：
  - [队列实现栈以及栈实现队列](https://labuladong.online/algo/data-structure/stack-queue/)
  - [【强化练习】栈的经典习题](https://labuladong.online/algo/problem-set/stack/)

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

class MyStack {
    queue<int> q;
    int top_elem = 0;

public:
    /**
     * 添加元素到栈顶
     */
    void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q.push(x);
        top_elem = x;
    }

    /**
     * 返回栈顶元素
     */
    int top() {
        return top_elem;
    }

    /**
     * 删除栈顶的元素并返回
     */
    int pop() {
        int size = q.size();
        // 留下队尾 2 个元素
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size--;
        }
        // 记录新的队尾元素
        top_elem = q.front();
        q.push(q.front());
        q.pop();
        // 删除之前的队尾元素
        int tmp=q.front();
        q.pop();
        return tmp;
    }

    /**
     * 判断栈是否为空
     */
    bool empty() {
        return q.empty();
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

from collections import deque

class MyStack:
    def __init__(self):
        self.q = deque()
        self.top_elem = 0

    """
    添加元素到栈顶
    """
    def push(self, x: int) -> None:
        # x 是队列的队尾，是栈的栈顶
        self.q.append(x)
        self.top_elem = x

    """
    返回栈顶元素
    """
    def top(self) -> int:
        return self.top_elem

    """
    删除栈顶的元素并返回
    """
    def pop(self) -> int:
        size = len(self.q)
        # 留下队尾 2 个元素
        while size > 2:
            self.q.append(self.q.popleft())
            size -= 1
        # 记录新的队尾元素
        self.top_elem = self.q[0]
        self.q.append(self.q.popleft())
        # 删除之前的队尾元素
        return self.q.popleft()

    """
    判断栈是否为空
    """
    def empty(self) -> bool:
        return len(self.q) == 0
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class MyStack {
    Queue<Integer> q = new LinkedList<>();
    int top_elem = 0;

    // 将元素 x 压入栈顶
    public void push(int x) {
        // x 是队列的队尾，是栈的栈顶
        q.offer(x);
        top_elem = x;
    }

    // 返回栈顶元素
    public int top() {
        return top_elem;
    }

    
    // 删除栈顶的元素并返回
    public int pop() {
        int size = q.size();
        // 留下队尾 2 个元素
        while (size > 2) {
            q.offer(q.poll());
            size--;
        }
        // 记录新的队尾元素
        top_elem = q.peek();
        q.offer(q.poll());
        // 删除之前的队尾元素
        return q.poll();
    }

    // 判断栈是否为空
    public boolean empty() {
        return q.isEmpty();
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

type MyStack struct {
    q       []int
    topElem int
}

func Constructor() MyStack {
    return MyStack{
        q:       []int{},
        topElem: 0,
    }
}

/**
 * 添加元素到栈顶
 */
func (this *MyStack) Push(x int) {
    // x 是队列的队尾，是栈的栈顶
    this.q = append(this.q, x)
    this.topElem = x
}

/**
 * 返回栈顶元素
 */
func (this *MyStack) Top() int {
    return this.topElem
}

/**
 * 删除栈顶的元素并返回
 */
func (this *MyStack) Pop() int {
    size := len(this.q)
    // 留下队尾 2 个元素
    for size > 1 {
        this.topElem = this.q[0]
        this.q = append(this.q, this.q[0])
        this.q = this.q[1:]
        size--
    }
    // 记录新的队尾元素
    popElem := this.q[0]
    this.q = this.q[1:]
    // 删除之前的队尾元素
    return popElem
}

/**
 * 判断栈是否为空
 */
func (this *MyStack) Empty() bool {
    return len(this.q) == 0
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var MyStack = function() {
    this.q = [];
    this.top_elem = 0;
};

/**
 * 添加元素到栈顶
 */
MyStack.prototype.push = function(x) {
    // x 是队列的队尾，是栈的栈顶
    this.q.push(x);
    this.top_elem = x;
};

/**
 * 返回栈顶元素
 */
MyStack.prototype.top = function() {
    return this.top_elem;
};

/**
 * 删除栈顶的元素并返回
 */
MyStack.prototype.pop = function() {
    let size = this.q.length;
    // 留下队尾 2 个元素
    while (size > 2) {
        this.q.push(this.q.shift());
        size--;
    }
    // 记录新的队尾元素
    this.top_elem = this.q[0];
    this.q.push(this.q.shift());
    // 删除之前的队尾元素
    return this.q.shift();
};

/**
 * 判断栈是否为空
 */
MyStack.prototype.empty = function() {
    return this.q.length === 0;
};
```

</div></div>
</div></div>

</div>
</details>
</div>

