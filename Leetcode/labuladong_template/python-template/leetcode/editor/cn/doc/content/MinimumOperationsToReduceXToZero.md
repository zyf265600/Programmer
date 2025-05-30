<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>x</code> 。每一次操作时，你应当移除数组 <code>nums</code> 最左边或最右边的元素，然后从 <code>x</code> 中减去该元素的值。请注意，需要 <strong>修改</strong> 数组以供接下来的操作使用。</p>

<p>如果可以将 <code>x</code>&nbsp;<strong>恰好</strong> 减到&nbsp;<code>0</code> ，返回<strong> 最小操作数 </strong>；否则，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,4,2,3], x = 5
<strong>输出：</strong>2
<strong>解释：</strong>最佳解决方案是移除后两个元素，将 x 减到 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,6,7,8,9], x = 4
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,20,1,1,3], x = 10
<strong>输出：</strong>5
<strong>解释：</strong>最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul> 
 <li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li> 
 <li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li> 
 <li><code>1 &lt;= x &lt;= 10<sup>9</sup></code></li> 
</ul>

<details><summary><strong>Related Topics</strong></summary>数组 | 哈希表 | 二分查找 | 前缀和 | 滑动窗口</details><br>

<div>👍 425, 👎 0<span style='float: right;'><span style='color: gray;'><a href='https://github.com/labuladong/fucking-algorithm/issues' target='_blank' style='color: lightgray;text-decoration: underline;'>bug 反馈</a> | <a href='https://labuladong.online/algo/fname.html?fname=jb插件简介' target='_blank' style='color: lightgray;text-decoration: underline;'>使用指南</a> | <a href='https://labuladong.online/algo/' target='_blank' style='color: lightgray;text-decoration: underline;'>更多配套插件</a></span></span></div>

<div id="labuladong"><hr>

**通知：为满足广大读者的需求，网站上架 [速成目录](https://labuladong.online/algo/intro/quick-learning-plan/)，如有需要可以看下，谢谢大家的支持~**

<details><summary><strong>labuladong 思路</strong></summary>


<div id="labuladong_solution_zh">

## 基本思路

很多读者第一眼看到这个题，可能就想到了递归算法来穷举所有可能的操作方法对吧？每次我可以选择移除最左边或最右边的元素，然后对剩下的数组递归调用，直到 `x` 减到 0，肯定可以算出最小的操作数。

这很好，说明大家已经理解并运用了「算法本质是穷举」的思想，对于容易穷举的，用 for 循环遍历；对于每次选择之间互相关联的，用递归算法借助递归树穷举。

但是这里可以用到我在 [时空复杂度分析实用指南](https://labuladong.online/algo/essential-technique/complexity-analysis/) 中分享的小技巧，你看完题就知道这题不能用递归：就是看数据规模预估反推算法思路。

这道题的数据规模是 `1 <= nums.length <= 10^5`，这就意味着递归算法的时间复杂度不能达到 `O(2^n)` 这个级别，因为 10^5 的平方就是 10^10，这个数量级，在任何判题平台都是不能被接受的。

你如果用递归算法，且不说指数级复杂度的回溯算法了，即便你能用动态规划算法消除重叠子问题，那你至少也要用两个状态，也就是数组两端 `i, j` 的索引位置。那么时空复杂度最起码都要 `O(2^n)`，所以这道题不适合用递归算法。

有了上面的分析，你必须再观察观察，转换一下思路。题目让你从边缘删除掉和为 `x` 的元素，那剩下来的是什么？剩下来的是不是就是 `nums` 中的一个子数组？让你尽可能少地从边缘删除元素说明什么？是不是就是说剩下来的这个子数组大小尽可能的大？

**所以，这道题等价于让你寻找 `nums` 中元素和为 `sum(nums) - x` 的最长子数组**。

寻找子数组就是考察滑动窗口技巧。前文 [滑动窗口框架](https://labuladong.online/algo/essential-technique/sliding-window-framework/) 说过，使用滑动窗口算法需要搞清楚以下几个问题：

1、什么时候应该扩大窗口？

2、什么时候应该缩小窗口？

3、什么时候得到一个合法的答案？

针对本题，以上三个问题的答案是：

1、当窗口内元素之和小于目标和 `target` 时，扩大窗口，让窗口内元素和增加。

2、当窗口内元素之和大于目标和 `target` 时，缩小窗口，让窗口内元素和减小。

3、当窗口内元素之和等于目标和 `target` 时，找到一个符合条件的子数组，我们想找的是最长的子数组长度。

> 注意：类似 [✨713. 乘积小于 K 的子数组](/problems/subarray-product-less-than-k/)，之所以本题可以用滑动窗口，关键是题目说了 `nums` 中的元素都是正数，这就保证了只要有元素加入窗口，和一定变大，只要有元素离开窗口，和一定变小。
>
> 你想想如果存在负数的话就没有这个性质了，也就不能确定什么时候扩大和缩小窗口，也就不能使用滑动窗口算法，而应该使用 [前缀和 + 哈希表的方式](https://labuladong.online/algo/problem-set/perfix-sum/) 解决，参见 [✨560. 和为K的子数组](/problems/subarray-sum-equals-k/)。

**详细题解**：
  - [【练习】滑动窗口算法经典习题](https://labuladong.online/algo/problem-set/sliding-window/)

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
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        // 滑动窗口需要寻找的子数组目标和
        int target = sum - x;

        int left = 0, right = 0;
        // 记录窗口内所有元素和
        int windowSum = 0;
        // 记录目标子数组的最大长度
        int maxLen = INT_MIN;
        // 开始执行滑动窗口框架
        while (right < nums.size()) {
            // 扩大窗口
            windowSum += nums[right];
            right++;

            while (windowSum > target && left < right) {
                // 缩小窗口
                windowSum -= nums[left];
                left++;
            }
            // 寻找目标子数组
            if (windowSum == target) {
                maxLen = max(maxLen, right - left);
            }
        }
        // 目标子数组的最大长度可以推导出需要删除的字符数量
        return maxLen == INT_MIN ? -1 : n - maxLen;
    }
};
```

</div></div>

<div data-tab-item="python" class="tab-item " data-tab-group="default"><div class="highlight">

```python
# 注意：python 代码由 chatGPT🤖 根据我的 java 代码翻译。
# 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        n = len(nums)
        sum_ = sum(nums)
        # 滑动窗口需要寻找的子数组目标和
        target = sum_ - x

        left = 0
        right = 0
        # 记录窗口内所有元素和
        window_sum = 0
        # 记录目标子数组的最大长度
        max_len = float('-inf')
        # 开始执行滑动窗口框架
        while right < n:
            # 扩大窗口
            window_sum += nums[right]
            right += 1

            while window_sum > target and left < right:
                # 缩小窗口
                window_sum -= nums[left]
                left += 1

            # 寻找目标子数组
            if window_sum == target:
                max_len = max(max_len, right - left)

        # 目标子数组的最大长度可以推导出需要删除的字符数量
        return -1 if max_len == float('-inf') else n - max_len
```

</div></div>

<div data-tab-item="java" class="tab-item active" data-tab-group="default"><div class="highlight">

```java
class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        // 滑动窗口需要寻找的子数组目标和
        int target = sum - x;

        int left = 0, right = 0;
        // 记录窗口内所有元素和
        int windowSum = 0;
        // 记录目标子数组的最大长度
        int maxLen = Integer.MIN_VALUE;
        // 开始执行滑动窗口框架
        while (right < nums.length) {
            // 扩大窗口
            windowSum += nums[right];
            right++;

            while (windowSum > target && left < right) {
                // 缩小窗口
                windowSum -= nums[left];
                left++;
            }
            // 寻找目标子数组
            if (windowSum == target) {
                maxLen = Math.max(maxLen, right - left);
            }
        }
        // 目标子数组的最大长度可以推导出需要删除的字符数量
        return maxLen == Integer.MIN_VALUE ? -1 : n - maxLen;
    }
}
```

</div></div>

<div data-tab-item="go" class="tab-item " data-tab-group="default"><div class="highlight">

```go
// 注意：go 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

func minOperations(nums []int, x int) int {
    n := len(nums)
    sum := 0
    for _, num := range nums {
        sum += num
    }
    // 滑动窗口需要寻找的子数组目标和
    target := sum - x

    left, right := 0, 0
    // 记录窗口内所有元素和
    windowSum := 0
    // 记录目标子数组的最大长度
    maxLen := -1
    // 开始执行滑动窗口框架
    for right < len(nums) {
        // 扩大窗口
        windowSum += nums[right]
        right++

        for windowSum > target && left < right {
            // 缩小窗口
            windowSum -= nums[left]
            left++
        }
        // 寻找目标子数组
        if windowSum == target {
            if maxLen == -1 || right-left > maxLen {
                maxLen = right - left
            }
        }
    }
    // 目标子数组的最大长度可以推导出需要删除的字符数量
    if maxLen == -1 {
        return -1
    }
    return n - maxLen
}
```

</div></div>

<div data-tab-item="javascript" class="tab-item " data-tab-group="default"><div class="highlight">

```javascript
// 注意：javascript 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

var minOperations = function(nums, x) {
    let n = nums.length, sum = 0;
    for (let i = 0; i < n; i++) {
        sum += nums[i];
    }
    // 滑动窗口需要寻找的子数组目标和
    let target = sum - x;

    let left = 0, right = 0;
    // 记录窗口内所有元素和
    let windowSum = 0;
    // 记录目标子数组的最大长度
    let maxLen = -Infinity;
    // 开始执行滑动窗口框架
    while (right < nums.length) {
        // 扩大窗口
        windowSum += nums[right];
        right++;

        while (windowSum > target && left < right) {
            // 缩小窗口
            windowSum -= nums[left];
            left++;
        }
        // 寻找目标子数组
        if (windowSum == target) {
            maxLen = Math.max(maxLen, right - left);
        }
    }
    // 目标子数组的最大长度可以推导出需要删除的字符数量
    return maxLen == -Infinity ? -1 : n - maxLen;
};
```

</div></div>
</div></div>

<hr /><details open hint-container details><summary style="font-size: medium"><strong>🍭🍭 算法可视化 🍭🍭</strong></summary><div id="data_minimum-operations-to-reduce-x-to-zero"  category="leetcode" ></div><div class="resizable aspect-ratio-container" style="height: 100%;">
<div id="iframe_minimum-operations-to-reduce-x-to-zero"></div></div>
</details><hr /><br />

</div>
</details>
</div>

