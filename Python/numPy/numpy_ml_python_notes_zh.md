# NumPy Absolute Basics — ML Python 学习笔记

> 基于 NumPy 官方 `NumPy: the absolute basics for beginners` 整理。  
> 目标：不是逐句翻译，而是保留最重要的官方概念，并按 Machine Learning（机器学习）使用场景重新组织。

---

## 0. 导入 NumPy（Import NumPy）

```python
import numpy as np
```

`np` 是 NumPy 社区最常见的缩写。后续代码通常写成：

```python
np.array(...)
np.zeros(...)
np.mean(...)
```

---

# 1. ndarray（N-dimensional array，N 维数组）

NumPy 的核心数据结构是：

```python
numpy.ndarray
```

可以把它理解成一个规则的、多维的数据容器。

```python
import numpy as np

a = np.array([1, 2, 3, 4])
```

二维数组：

```python
a = np.array([
    [1, 2, 3],
    [4, 5, 6]
])
```

### ndarray 与 Python list 的关键区别

Python `list` 可以存不同类型：

```python
x = [1, "hello", True]
```

而 NumPy array（NumPy 数组）通常是 homogeneous（同质的），也就是所有元素使用相同的数据类型。

```python
a = np.array([1, 2, 3])
print(a.dtype)
```

NumPy 通过这种限制换取：

- 更高的计算效率（computation efficiency）
- 更低的内存开销（memory efficiency）
- 更方便的 vectorized operations（向量化运算）

对于 Machine Learning（机器学习）来说，这一点非常重要，因为：

```text
dataset
weights
activations
gradients
embeddings
```

本质上都可以表示成多维数组。

---

# 2. dimension / axis / shape 到底是什么？

这是 NumPy 和 PyTorch 最重要的基础之一。

假设：

```python
a = np.array([
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
])
```

那么：

```python
a.ndim
# 2

a.shape
# (3, 4)

a.size
# 12
```

## 2.1 ndim（number of dimensions，维度数）

```python
a.ndim
```

表示 array 有多少个 axis（轴）。

上面的矩阵：

```text
3 rows × 4 columns
```

有两个 axis：

```text
axis 0 → rows
axis 1 → columns
```

所以：

```python
a.ndim == 2
```

---

## 2.2 shape（形状）

```python
a.shape
# (3, 4)
```

含义：

```text
axis 0 有 3 个元素
axis 1 有 4 个元素
```

更直观：

```text
shape = (3, 4)

          axis 1
       ──────────→
       1  2  3  4
axis 0 5  6  7  8
  ↓    9 10 11 12
```

### ML 中最常见的 shape

训练数据：

```python
X.shape == (batch_size, num_features)
```

例如：

```python
X.shape == (32, 128)
```

表示：

```text
32 samples（样本）
128 features（特征）
```

神经网络中可能看到：

```text
(batch_size, sequence_length, hidden_dim)
```

例如：

```python
(32, 512, 768)
```

对应：

```text
32 个样本
每个样本 512 个 token
每个 token 用 768 维向量表示
```

这就是以后 Transformer（Transformer 模型）里经常看到的 tensor shape（张量形状）。

---

## 2.3 size（元素总数）

```python
a.size
```

就是：

```text
所有 shape 维度相乘
```

例如：

```python
shape = (3, 4)

size = 3 × 4 = 12
```

---

## 2.4 dtype（data type，数据类型）

```python
a.dtype
```

例如：

```text
int64
float32
float64
```

ML 中尤其要注意：

```python
float32
```

因为大量深度学习计算默认使用 floating-point（浮点数）。

---

# 3. 创建 NumPy Array（Creating Arrays）

## 3.1 np.array()

从 Python list 创建：

```python
a = np.array([1, 2, 3])
```

二维：

```python
a = np.array([
    [1, 2],
    [3, 4]
])
```

---

## 3.2 np.zeros()

```python
np.zeros(3)
```

结果：

```python
array([0., 0., 0.])
```

二维：

```python
np.zeros((2, 3))
```

```text
[[0. 0. 0.]
 [0. 0. 0.]]
```

ML 中常见用途：

```python
grad = np.zeros_like(weights)
```

---

## 3.3 np.ones()

```python
np.ones((2, 3))
```

创建全部为 `1` 的数组。

---

## 3.4 np.empty()

```python
np.empty((2, 3))
```

它只分配内存，不保证里面的数据是什么。

因此可能看到：

```text
random-looking values
```

它适合：

> 马上会把所有位置重新写入数据的情况。

初学阶段一般优先使用：

```python
np.zeros(...)
```

更容易避免错误。

---

# 4. arange 与 linspace

## np.arange()

类似 Python：

```python
range()
```

例如：

```python
np.arange(4)
```

得到：

```python
[0, 1, 2, 3]
```

指定：

```python
np.arange(2, 9, 2)
```

得到：

```python
[2, 4, 6, 8]
```

---

## np.linspace()

```python
np.linspace(0, 10, num=5)
```

得到：

```text
[0, 2.5, 5, 7.5, 10]
```

区别：

```text
arange → 给 step（步长）
linspace → 给 number of points（点的数量）
```

---

# 5. Indexing & Slicing（索引与切片）

一维：

```python
data = np.array([1, 2, 3])

data[1]
# 2

data[0:2]
# [1, 2]

data[1:]
# [2, 3]

data[-2:]
# [2, 3]
```

和 Python list 基本一致。

---

## 二维索引

```python
a = np.array([
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
])
```

访问：

```python
a[1, 3]
```

得到：

```python
8
```

可以理解成：

```text
a[row, column]
```

也就是：

```text
a[axis0_index, axis1_index]
```

---

# 6. Boolean Indexing（布尔索引）

这是 ML / Data Science 中非常常见的 NumPy 技巧。

```python
a = np.array([1, 2, 3, 4, 5])
```

找大于 3 的元素：

```python
a[a > 3]
```

得到：

```python
[4, 5]
```

它实际上分两步。

第一步：

```python
a > 3
```

得到：

```python
[False, False, False, True, True]
```

第二步：

```python
a[mask]
```

只选择 `True` 的位置。

---

## 多个条件

必须使用：

```python
&
|
```

例如：

```python
a[(a > 2) & (a < 5)]
```

而不是：

```python
a[a > 2 and a < 5]   # 错误
```

NumPy 中：

```text
& → element-wise AND（逐元素与）
| → element-wise OR（逐元素或）
```

条件一定要加括号：

```python
(a > 2) & (a < 5)
```

---

# 7. View vs Copy（视图与复制）

这是 NumPy 非常容易踩坑的地方。

```python
a = np.array([1, 2, 3, 4, 5, 6])

b = a[3:]
```

很多人会以为：

```text
b 是一个新的 array
```

但 NumPy slicing（切片）经常返回：

```text
view（视图）
```

即：

```text
b 与 a 共享底层数据
```

所以：

```python
b[0] = 100
```

可能同时修改：

```python
a
```

如果你明确需要独立数据：

```python
b = a.copy()
```

### 为什么 ML 中重要？

你以后会大量：

```python
batch = X[start:end]
subset = embeddings[idx]
```

如果不了解 view / copy（视图 / 复制），可能会无意修改原始数据。

---

# 8. reshape（形状变换）

```python
a = np.arange(6)
```

现在：

```python
a.shape
# (6,)
```

转换成：

```python
b = a.reshape(3, 2)
```

得到：

```text
[[0 1]
 [2 3]
 [4 5]]
```

shape：

```python
b.shape
# (3, 2)
```

关键规则：

> reshape 前后的元素总数必须相同。

例如：

```text
6 → 3 × 2
6 → 2 × 3
6 → 1 × 6
```

都可以。

但是：

```text
6 → 4 × 2
```

不可以。

---

## ML 中最重要的 reshape 技巧：-1

例如：

```python
a.reshape(-1, 1)
```

`-1` 的意思不是负维度。

它表示：

> 这一维让 NumPy 自动推断。

例如：

```python
a = np.array([1, 2, 3, 4, 5, 6])

a.reshape(-1, 1).shape
# (6, 1)
```

---

# 9. 1D vector 与 row / column vector

```python
a = np.array([1, 2, 3, 4, 5, 6])

a.shape
# (6,)
```

注意：

```text
(6,)
```

不是：

```text
(1, 6)
```

也不是：

```text
(6, 1)
```

这是 NumPy 初学者非常重要的一点。

---

## row vector（行向量）

```python
row = a[np.newaxis, :]
```

shape：

```python
(1, 6)
```

或者：

```python
row = a.reshape(1, -1)
```

---

## column vector（列向量）

```python
col = a[:, np.newaxis]
```

shape：

```python
(6, 1)
```

或者：

```python
col = a.reshape(-1, 1)
```

---

# 10. Basic Operations（基本运算）

```python
data = np.array([1, 2])
ones = np.ones(2)
```

加法：

```python
data + ones
```

减法：

```python
data - ones
```

乘法：

```python
data * data
```

除法：

```python
data / data
```

注意：

```python
*
```

是：

```text
element-wise multiplication（逐元素乘法）
```

不是 matrix multiplication（矩阵乘法）。

---

# 11. Matrix Multiplication（矩阵乘法）

矩阵乘法使用：

```python
@
```

例如：

```python
X @ W
```

假设：

```text
X.shape = (32, 128)
W.shape = (128, 64)
```

那么：

```python
Y = X @ W
```

结果：

```text
Y.shape = (32, 64)
```

这是 neural network（神经网络）最核心的运算之一：

```python
Y = X @ W + b
```

---

# 12. Aggregation（聚合运算）

常见：

```python
a.sum()
a.mean()
a.min()
a.max()
a.std()
a.prod()
```

例如：

```python
a = np.array([1, 2, 3])

a.sum()
# 6

a.mean()
# 2
```

---

# 13. axis（轴）——必须真正理解

假设：

```python
a = np.array([
    [1, 2],
    [3, 4]
])
```

shape：

```python
(2, 2)
```

执行：

```python
a.sum(axis=0)
```

得到：

```python
[4, 6]
```

因为：

```text
1 + 3 = 4
2 + 4 = 6
```

可以理解：

> `axis=0` 被消掉。

原来：

```text
(2, 2)
```

执行：

```python
sum(axis=0)
```

结果：

```text
(2,)
```

---

执行：

```python
a.sum(axis=1)
```

得到：

```python
[3, 7]
```

因为：

```text
1 + 2 = 3
3 + 4 = 7
```

可以理解：

> `axis=1` 被消掉。

---

## 推荐的 axis 心智模型

不要死记：

```text
axis=0 → column
axis=1 → row
```

更通用的理解：

> `axis=n` 表示 operation（操作）沿第 n 个维度进行，并通常把这一维压缩掉。

这个理解可以直接扩展到 3D / 4D tensor（张量）。

---

# 14. keepdims=True（保留维度）

假设：

```python
X.shape == (32, 128)
```

执行：

```python
X.sum(axis=1)
```

得到：

```text
(32,)
```

但：

```python
X.sum(axis=1, keepdims=True)
```

得到：

```text
(32, 1)
```

为什么重要？

因为 `(32, 1)` 往往更容易参与 broadcasting（广播）。

例如：

```python
X / X.sum(axis=1, keepdims=True)
```

在 ML code 中非常常见。

---

# 15. Broadcasting（广播）

Broadcasting（广播）是 NumPy 最重要的机制之一。

最简单例子：

```python
data = np.array([1.0, 2.0])

data * 1.6
```

NumPy 会把：

```text
1.6
```

逻辑上应用到：

```text
每一个元素
```

得到：

```text
[1.6, 3.2]
```

---

## 更重要的例子

假设：

```python
X.shape == (32, 128)
b.shape == (128,)
```

计算：

```python
Y = X + b
```

NumPy 会把 `b` 应用到 32 个 sample（样本）上。

逻辑上相当于：

```text
X:
(32, 128)

b:
     (128,)

→ broadcasting

b:
(32, 128)
```

但 NumPy 不需要真的复制 32 份数据。

---

## Broadcasting compatibility rule（广播兼容规则）

从 shape 的最后一个维度开始比较。

两个维度 compatible（兼容），如果：

```text
1. 两个维度相等
或
2. 其中一个维度是 1
```

例如：

```text
(32, 128)
     (128)
```

兼容。

```text
(32, 128)
(1,   128)
```

兼容。

```text
(32, 128)
(32,   1)
```

兼容。

但：

```text
(32, 128)
(32,  64)
```

不兼容。

---

# 16. concatenate / stack（拼接）

```python
a = np.array([1, 2, 3])
b = np.array([4, 5, 6])
```

```python
np.concatenate((a, b))
```

得到：

```text
[1, 2, 3, 4, 5, 6]
```

二维：

```python
x = np.array([
    [1, 2],
    [3, 4]
])

y = np.array([
    [5, 6]
])
```

```python
np.concatenate((x, y), axis=0)
```

结果：

```text
[[1, 2],
 [3, 4],
 [5, 6]]
```

---

# 17. transpose（转置）

```python
arr = np.arange(6).reshape(2, 3)
```

```text
[[0, 1, 2],
 [3, 4, 5]]
```

执行：

```python
arr.T
```

得到：

```text
[[0, 3],
 [1, 4],
 [2, 5]]
```

shape：

```text
(2, 3)
    ↓
(3, 2)
```

也可以：

```python
arr.transpose()
```

---

# 18. NumPy ↔ PyTorch 对应关系

你学 NumPy 时最好同时建立下面这张表。

| NumPy | PyTorch | 中文 |
|---|---|---|
| `np.ndarray` | `torch.Tensor` | N 维数组 / 张量 |
| `.shape` | `.shape` | 形状 |
| `.ndim` | `.ndim` | 维度数 |
| `.reshape()` | `.reshape()` | 形状变换 |
| `np.expand_dims()` | `.unsqueeze()` | 增加维度 |
| `np.concatenate()` | `torch.cat()` | 拼接 |
| `np.stack()` | `torch.stack()` | 堆叠 |
| `np.sum(axis=...)` | `torch.sum(dim=...)` | 求和 |
| `np.mean(axis=...)` | `torch.mean(dim=...)` | 均值 |
| `A @ B` | `A @ B` | 矩阵乘法 |
| broadcasting | broadcasting | 广播 |

最重要的语言差异之一：

```python
# NumPy
X.sum(axis=1)

# PyTorch
X.sum(dim=1)
```

概念完全一样：

```text
NumPy axis
≈
PyTorch dim
```

---

# 19. ML Coding 必须熟练的 NumPy 写法

## Feature mean（特征均值）

```python
mean = X.mean(axis=0)
```

如果：

```text
X.shape = (N, D)
```

那么：

```text
mean.shape = (D,)
```

---

## Standardization（标准化）

```python
mean = X.mean(axis=0)
std = X.std(axis=0)

X_norm = (X - mean) / std
```

这里自动使用 broadcasting（广播）。

---

## Linear Layer（线性层）

```python
Y = X @ W + b
```

shape：

```text
X : (B, D)
W : (D, H)
b : (H,)

Y : (B, H)
```

这里同时使用：

```text
matrix multiplication（矩阵乘法）
+
broadcasting（广播）
```

---

## Softmax

```python
def softmax(x):
    x = x - np.max(x, axis=-1, keepdims=True)

    exp_x = np.exp(x)

    return exp_x / np.sum(
        exp_x,
        axis=-1,
        keepdims=True
    )
```

这里几乎把最重要的 NumPy 概念都用到了：

```text
axis
keepdims
broadcasting
vectorization
aggregation
```

---

# 20. 你现阶段最应该掌握什么？

第一优先级：

```text
ndarray
shape
ndim
dtype
indexing
slicing
boolean indexing
reshape
axis
keepdims
broadcasting
```

第二优先级：

```text
concatenate
stack
transpose
mean
sum
std
min/max
matrix multiplication
```

第三优先级：

```text
copy vs view
advanced indexing
memory layout
```

---

# 21. 自测

如果你能不运行代码直接回答这些问题，这一部分基本掌握。

### Q1

```python
X = np.zeros((32, 128))
```

问：

```python
X.ndim
X.shape
X.size
```

---

### Q2

```python
X.shape == (32, 128)
```

那么：

```python
X.mean(axis=0).shape
```

是多少？

---

### Q3

```python
X.shape == (32, 128)
```

那么：

```python
X.mean(axis=1).shape
```

是多少？

---

### Q4

```python
X.shape == (32, 128)
```

那么：

```python
X.mean(axis=1, keepdims=True).shape
```

是多少？

---

### Q5

下面能不能 broadcasting（广播）？

```text
X: (32, 128)
b: (128,)
```

---

### Q6

下面能不能 broadcasting？

```text
X: (32, 128)
b: (32, 1)
```

---

### Q7

下面能不能 broadcasting？

```text
X: (32, 128)
b: (64,)
```

---

### Q8

```python
X.shape == (32, 128)
W.shape == (128, 64)

Y = X @ W
```

`Y.shape` 是多少？

---

# 22. 建议学习顺序

不要一次背完整个 NumPy API。

建议：

```text
Day 1
ndarray
shape
ndim
dtype
indexing
slicing

↓

Day 2
reshape
axis
aggregation
keepdims
broadcasting

↓

Day 3
matrix multiplication
boolean indexing
concatenate
transpose
copy vs view

↓

接下来
用 NumPy 手写：

Linear Regression（线性回归）
Logistic Regression（逻辑回归）
KNN（K 近邻）
K-Means（K 均值）
Softmax
Cross Entropy（交叉熵）
Self-Attention（自注意力）
```

---

## 一句话总结

学习 NumPy 最重要的不是记函数，而是训练自己：

> **看到每一行 NumPy / PyTorch 代码，都能立刻判断 tensor / array 的 shape 如何变化。**

这会直接决定你以后写 ML code（机器学习代码）、读 PyTorch、实现 Attention（注意力机制）和参加 ML Coding Interview（机器学习编程面试）时是否顺畅。
