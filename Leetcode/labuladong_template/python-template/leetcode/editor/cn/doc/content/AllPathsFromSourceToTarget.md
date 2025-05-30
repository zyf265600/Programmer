<p>给你一个有&nbsp;<code>n</code>&nbsp;个节点的 <strong>有向无环图（DAG）</strong>，请你找出所有从节点 <code>0</code>&nbsp;到节点 <code>n-1</code>&nbsp;的路径并输出（<strong>不要求按特定顺序</strong>）</p>

<p>
 <meta charset="UTF-8" />&nbsp;<code>graph[i]</code>&nbsp;是一个从节点 <code>i</code> 可以访问的所有节点的列表（即从节点 <code>i</code> 到节点&nbsp;<code>graph[i][j]</code>存在一条有向边）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg" /></p>

<pre>
<strong>输入：</strong>graph = [[1,2],[3],[3],[]]
<strong>输出：</strong>[[0,1,3],[0,2,3]]
<strong>解释：</strong>有两条路径 0 -&gt; 1 -&gt; 3 和 0 -&gt; 2 -&gt; 3
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg" /></p>

<pre>
<strong>输入：</strong>graph = [[4,3,1],[3,2,4],[3],[4],[]]
<strong>输出：</strong>[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>n == graph.length</code></li> 
 <li><code>2 &lt;= n &lt;= 15</code></li> 
 <li><code>0 &lt;= graph[i][j] &lt; n</code></li> 
 <li><code>graph[i][j] != i</code>（即不存在自环）</li> 
 <li><code>graph[i]</code> 中的所有元素 <strong>互不相同</strong></li> 
 <li>保证输入为 <strong>有向无环图（DAG）</strong></li> 
</ul>

<p>&nbsp;</p>

<details><summary><strong>Related Topics</strong></summary>深度优先搜索 | 广度优先搜索 | 图 | 回溯</details><br>

<div>👍 534, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**Note: English content is improving...**

<details><summary><strong>Brief Thoughts</strong></summary>





<div id="labuladong_solution_en">

## Thoughts

The solution is quite simple: traverse the graph starting from `0`, while recording the traversed path. When reaching the endpoint, record the path.

Since the input graph is acyclic, we don't need a `visited` array for assistance. We can directly apply the [graph traversal framework](https://labuladong.online/algo/en/data-structure-basic/graph-basic/).

**Detailed solution: [Graph Theory Basics and Traversal Algorithms](https://labuladong.online/algo/en/data-structure-basic/graph-basic/)**

</div>


<div id="solution">

## Solution



<div class="tab-panel"><div class="tab-nav">
<button data-tab-item="cpp" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">cpp🤖</button>

<button data-tab-item="python" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">python🤖</button>

<button data-tab-item="java" class="tab-nav-button btn active" data-tab-group="default" onclick="switchTab(this)">java🟢</button>

<button data-tab-item="go" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">go🤖</button>

<button data-tab-item="javascript" class="tab-nav-button btn " data-tab-group="default" onclick="switchTab(this)">javascript🤖</button>
</div><div class="tab-content">
<div data-tab-item="cpp" class="tab-item " data-tab-group="default"><div class="highlight">

```cpp
// Note: This cpp code is translated by chatGPT🤖 based on my java code.
// This code has passed all the test cases, should be accepted by LeetCode.

class Solution {
    // record all paths
    vector<vector<int>> res;
    vector<int> path;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        traverse(graph, 0);
        return res;
    }
    // framework for graph traversal
    void traverse(vector<vector<int>>& graph, int s) {
        // add node s to the path
        path.push_back(s);

        int n = graph.size();
        if (s == n - 1) {
            // reach the endpoint
            res.push_back(vector<int>(path));
            path.pop_back();
            return;
        }
        // recursively traverse each adjacent node
        for (int v : graph[s]) {
            traverse(graph, v);
        }
        // remove node s from the path
        path.pop_back();
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# Note: This python code is translated by chatGPT🤖 based on my java code.
# This code has passed all the test cases, should be accepted by LeetCode.

class Solution:
    # record all paths
    def __init__(self):
        self.res = []
        self.path = []

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.traverse(graph, 0)
        return self.res
    # framework for graph traversal
    def traverse(self, graph: List[List[int]], s: int):
        # add node s to the path
        self.path.append(s)

        n = len(graph)
        if s == n - 1:
            # reach the endpoint
            self.res.append(self.path.copy())
            self.path.pop()
            return
        # recursively traverse each adjacent node
        for v in graph[s]:
            self.traverse(graph, v)
        # remove node s from the path
        self.path.pop()
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    // record all paths
    List<List<Integer>> res = new LinkedList<>();
    LinkedList<Integer> path = new LinkedList<>();

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        traverse(graph, 0);
        return res;
    }
    // framework for graph traversal
    void traverse(int[][] graph, int s) {
        // add node s to the path
        path.addLast(s);

        int n = graph.length;
        if (s == n - 1) {
            // reach the endpoint
            res.add(new LinkedList<>(path));
            path.removeLast();
            return;
        }
        // recursively traverse each adjacent node
        for (int v : graph[s]) {
            traverse(graph, v);
        }
        // remove node s from the path
        path.removeLast();
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// Note: This go code is translated by chatGPT🤖 based on my java code.
// This code has passed all the test cases, should be accepted by LeetCode.

func allPathsSourceTarget(graph [][]int) [][]int {
    // record all paths
    var res [][]int
    var path []int
    traverse(graph, 0, &path, &res)
    return res
}
// framework for graph traversal
func traverse(graph [][]int, s int, path *[]int, res *[][]int) {
    // add node s to the path
    *path = append(*path, s)

    n := len(graph)
    if s == n-1 {
        // reach the endpoint
        *res = append(*res, append([]int(nil), *path...))
        *path = (*path)[:len(*path)-1]
        return
    }
    // recursively traverse each adjacent node
    for _, v := range graph[s] {
        traverse(graph, v, path, res)
    }
    // remove node s from the path
    *path = (*path)[:len(*path)-1]
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// Note: This javascript code is translated by chatGPT🤖 based on my java code.
// This code has passed all the test cases, should be accepted by LeetCode.

var allPathsSourceTarget = function(graph) {
    // record all paths
    let res = [];
    let path = [];
    // framework for graph traversal
    var traverse = function(graph, s) {
        // add node s to the path
        path.push(s);

        let n = graph.length;
        if (s === n - 1) {
            // reach the endpoint
            res.push([...path]);
            path.pop();
            return;
        }
        // recursively traverse each adjacent node
        for (let v of graph[s]) {
            traverse(graph, v);
        }
        // remove node s from the path
        path.pop();
    };

    traverse(graph, 0);
    return res;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>👾👾 Algo Visualize 👾👾</strong></summary><div id="data_all-paths-from-source-to-target"  en="true" category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_all-paths-from-source-to-target"></div></div>
</details><hr /><br />

</div>
</details>
</div>





