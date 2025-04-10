# Python For Leetcode

本文针对初学者，介绍 Python 基本用法，包括标准输出、控制语句以及常用的数据结构，以便快速上手刷题。

## 标准输出

在 Python 中，标准输出使用 `print` 函数在控制台打印内容。`print` 默认会在末尾换行，如果想取消换行，可以使用参数 `end=""`。

```python
a = 10

# 输出：10
print(a)

# 串联输出（通过字符串拼接或逗号分隔）
# 输出：Hello, World!
print("Hello" + ", " + "World!")
# 使用 sep 指定分隔符
print("Hello", "World!", sep=", ")

s = "abc"
# 输出：abc 10
print(s, a)

# 格式化输出
# 输出：abc 10
print(f"{s} {a}")
```

## 控制语句

Python 中的控制语句包括条件判断和循环，下面简单介绍一下。

### 条件判断 `if`, `elif`, `else`



```python
a = 10

if a > 5:
    print("a > 5")
elif a == 5:
    print("a == 5")
else:
    print("a < 5")
# 输出：a > 5
```



### Python 循环 for/while

`for` 循环通常用于遍历可迭代对象或已知范围的序列，`while` 循环用于满足条件时反复执行代码块。

```python
# 输出：0 1 2 3 4 
for i in range(5):
    print(i, end=" ")
print()

num = 100
# 输出：100 50 25 12 6 3 1 
while num > 0:
    print(num, end=" ")
    num //= 2
print()
```

==**可迭代对象：**==

- **定义**：
  - 可迭代对象是能够逐个返回其元素的对象，可通过 `for` 循环遍历。
  - 实现了 `__iter__()` 方法，或实现了 `__getitem__()` 方法（序列协议）。
- **核心特征**：
  - **惰性计算**：迭代时按需生成元素（如生成器）。
  - **可重复使用**：每次迭代会生成新的迭代器（如列表、元组）。
  - **内存高效**：部分可迭代对象（如生成器）不一次性加载所有数据。

**常见可迭代对象**

| **类型**              | **示例**                | **特点**                 |
| :-------------------- | :---------------------- | :----------------------- |
| 列表（`list`）        | `[1, 2, 3]`             | 动态数组，可修改         |
| 元组（`tuple`）       | `(4, 5, 6)`             | 不可变，内存更紧凑       |
| 字典（`dict`）        | `{'a': 1, 'b': 2}`      | 遍历键、值或键值对       |
| 字符串（`str`）       | `"hello"`               | 按字符遍历               |
| 文件对象              | `open('file.txt')`      | 逐行读取                 |
| 生成器（`generator`） | `(x for x in range(3))` | 惰性计算，一次遍历后耗尽 |
| 集合（`set`）         | `{1, 2, 3}`             | 无序、去重               |
| `range` 对象          | `range(5)`              | 内存高效，表示整数序列   |



### for 循环的进阶用法

0. **for i in range(4, 2, -1) 灵活反向遍历**

这个 `range` 会生成以下序列：

```python
[4, 3]
```

- 起始值：4（包含）
- 终止值：2（不包含）
- ==步长：-1（向后走）==



1. **同时遍历多个序列：`zip()`**

```python
names = ['Alice', 'Bob', 'Charlie']
scores = [85, 90, 95]

for name, score in zip(names, scores):
    print(f'{name}: {score}')
```

💡 等价于 C++ 中的：

```python
for (int i = 0; i < names.size(); ++i)
    cout << names[i] << ": " << scores[i] << endl;
```



2. **带索引的遍历：`enumerate()`**

```python
for idx, name in enumerate(names):
    print(f'{idx}: {name}')
```

比 `for i in range(len(names))` 更 Pythonic。



3. **列表推导式中的 `for` 循环**

```python
squares = [x*x for x in range(10) if x % 2 == 0]
```

这就是一行搞定 map + filter 的经典写法。



4. **嵌套循环写在一行：二维数组展开**

```python
matrix = [[1, 2], [3, 4], [5, 6]]
flat = [x for row in matrix for x in row]
# 输出: [1, 2, 3, 4, 5, 6]
```

嵌套的顺序：**外层在前，内层在后**



5. **反向遍历：`reversed()`**

```python
for i in reversed(range(5)):
    print(i)
```



6. **集合去重 + 循环**

```python
nums = [1, 2, 2, 3, 3, 3]
for x in set(nums):
    print(x)
```



7. **字典的键值同时遍历**

```python
d = {'a': 1, 'b': 2}
for key, val in d.items():
    print(key, val)
```



8. **循环带 `else` 子句（很 Python 特有）**

```python
for x in range(5):
    if x == 3:
        break
else:
    print("循环正常结束")
```

⚠️ 注意：只有**没有被 break 掉**才会进入 `else` 分支。



## Python 列表 List

### **1. 列表基础**

- **定义**：
  - 列表是 **有序**、**可变** 的容器，支持任意类型元素的混合存储。
  - 基于动态数组实现，支持高效索引和尾部操作，中间插入/删除性能较低（平均时间复杂度 O(n)）。
  
- **创建方式**：

```python
  list1 = [1, 'a', True]              # 直接定义
  list2 = list((2, 'b', False))       # 通过可迭代对象转换
  list3 = [x**2 for x in range(5)]    # 列表推导式
  list4 = []                          # 空列表
```

**常见可迭代对象**

| **类型**              | **示例**                | **特点**                 |
| :-------------------- | :---------------------- | :----------------------- |
| 列表（`list`）        | `[1, 2, 3]`             | 动态数组，可修改         |
| 元组（`tuple`）       | `(4, 5, 6)`             | 不可变，内存更紧凑       |
| 字典（`dict`）        | `{'a': 1, 'b': 2}`      | 遍历键、值或键值对       |
| 字符串（`str`）       | `"hello"`               | 按字符遍历               |
| 文件对象              | `open('file.txt')`      | 逐行读取                 |
| 生成器（`generator`） | `(x for x in range(3))` | 惰性计算，一次遍历后耗尽 |
| 集合（`set`）         | `{1, 2, 3}`             | 无序、去重               |
| `range` 对象          | `range(5)`              | 内存高效，表示整数序列   |



### **2. 核心操作**

- **索引与切片**：

```python
  val = lst[0]           # 正向索引（0-based）
  val = lst[-1]          # 反向索引（-1 表示最后一个）
  sub = lst[1:4]         # 切片 [start:end)（生成新列表）
  sub = lst[::2]         # 步长切片（每2个取一个）
```

- **增删改元素**：

```python
  lst.append(10)         # 尾部添加元素（O(1)）
  lst.insert(2, 'x')     # 指定位置插入（O(n)）
  lst[1] = 20            # 修改元素
  del lst[0]             # 删除索引位置元素
  lst.remove('a')        # 删除首个匹配值（值不存在则 ValueError）
  popped = lst.pop()     # 删除并返回尾部元素（或指定索引元素）
```

- **合并与重复**：

```python
  lst3 = lst1 + lst2     # 合并生成新列表
  lst1.extend(lst2)      # 原地扩展（等效于 +=）
  repeated = lst * 3     # 重复列表元素
```

------

### **3. 常用方法**

- **查找与统计**：

```python
  index = lst.index('a')     # 返回首个匹配值的索引（不存在则 ValueError）
  count = lst.count(5)       # 统计某值出现次数
  exists = 5 in lst          # 成员检查（返回布尔值）
```

- **排序与反转**：

```python
  lst.sort()                 # 原地排序（可指定 key 和 reverse）
  sorted_lst = sorted(lst)   # 返回新排序列表
  lst.reverse()              # 原地反转顺序
  reversed_iter = reversed(lst)  # 生成反向迭代器（需转换列表：list(reversed_iter)）
```

- **内存管理**：

```python
  lst.clear()            # 清空列表（等效于 del lst[:]）
  lst.copy()             # 浅拷贝（等效于 lst[:]）
```

------

### **4. 特性与注意事项**

- **可变性**：
  - 列表内容可修改，但赋值 `=` 是浅拷贝（修改原列表会影响引用）。
  - 深拷贝需使用 `copy.deepcopy()`。
- **性能特点**：
  - 尾部追加（`append`/`pop`）平均 O(1)，中间操作（`insert`/`remove`）平均 O(n)。
  - 预分配内存（动态数组），扩容时会有额外开销。
- **==与元组的区别：==**
  - **==列表可变，元组不可变；列表用 `[]`，元组用 `()`。==**
  - **==元组适用于固定数据（如字典键），列表适用于动态数据。==**

------

### **5. 高级用法**

- **列表推导式**：

```python
  squares = [x**2 for x in range(10)]                # 基本推导式
  filtered = [x for x in lst if x % 2 == 0]           # 条件过滤
  nested = [[i*j for j in range(3)] for i in range(2)] # 嵌套推导式
```

- **多维列表**：

```python
  matrix = [[1, 2], [3, 4]]       # 二维列表
  value = matrix[0][1]            # 访问元素（输出 2）
```

- **解包与展开**：

```python
  a, *rest, b = [1, 2, 3, 4]      # 解包（a=1, rest=[2,3], b=4）
  merged = [*lst1, *lst2]         # 合并列表（Python 3.5+）
```

------

### **6. 应用场景**

- **动态数据集合**：存储可变长度的元素序列（如日志记录、用户输入）。

- **栈结构**（LIFO）：

```python
  stack = []
  stack.append(1)    # 入栈
  top = stack.pop()  # 出栈
```

- **队列结构**（FIFO，效率低，建议用 `collections.deque`）：

```python
  queue = []
  queue.append(1)           # 入队
  first = queue.pop(0)      # 出队（O(n)）
```

- **数据转换**：

```python
  chars = list("hello")            # 字符串转列表
  numbers = list(map(int, ["1", "2"]))  # 映射转换
```

------

### **7. 性能优化技巧**

- **预分配空间**（减少动态扩容）：

```python
  lst = [None] * 1000      # 初始化固定长度列表
```

- **避免频繁中间操作**：优先使用 `append`/`pop`。

- **使用生成器代替大列表**：

```python
  gen = (x**2 for x in range(10**6))  # 节省内存
```



### 8. 二维数组

关于二维数组：`matrix = [[1] * n for _ in range(m)]`

- **`[1] * n`**：创建一个包含 `n` 个 `1` 的一维列表。例如，`n=4` 时得到 `[1, 1, 1, 1]`。
- **`for _ in range(m)`**：循环 `m` 次（`_` 表示循环变量不需要使用）。
- **==列表推导式==**：每次循环都会执行一次 `[1] * n`，生成一个新的列表，最终将这些新列表组合成二维列表。列表推导式的核心逻辑是：**“为每次循环执行一次表达式，并将结果收集到列表中”**。

- **错误写法**：`matrix = [[1] * n] * m`

  ```python
  # 所有行指向同一个列表的引用
  matrix = [[1, 1, 1, 1]] * 3  # 三行实际上是同一个列表
  matrix[0][0] = 5
  print(matrix)  # 输出: [[5, 1, 1, 1], [5, 1, 1, 1], [5, 1, 1, 1]]
  ```

  **问题根源**：乘法操作符 `*` 复制的是列表的引用，而不是创建新列表。

**为什么 `nums = [0] * n` 是安全的？如果 `[0]` 是列表，为什么说 `*n` 只能用于不可变对象？**

不看[0]，而是看[ ]内的数据结构。这里0是不可变对象，**==`[0] * n` 实际上复制的是列表的引用，==**但由于列表中的元素 `0` 是不可变的，所以即使所有列表共享同一个 `0`，也不会出现问题。



### 双端队列 `deque`

`deque` 是 `collections` 模块提供的双端队列，可以高效地在两端插入和删除元素。

```python
from collections import deque

# 初始化双端队列
lst = deque([1, 2, 3, 4, 5])

# 检查是否为空，输出：False
print(len(lst) == 0)

# 获取大小，输出：5
print(len(lst))

# 在头部插入 0，尾部插入 6
lst.appendleft(0)
lst.append(6)

# 获取头部和尾部元素，输出：0 6
print(lst[0], lst[-1])

# 删除头部和尾部元素
lst.popleft()
lst.pop()

# 在索引 2 处插入 99
lst.insert(2, 99)

# 删除索引 1 处的元素
del lst[1]

# 遍历双端队列
# 输出：1 99 3 4 5
for val in lst:
    print(val, end=" ")
print()
```



## Python 队列 Queue

队列是一种操作受限制的数据结构：只允许在队尾插入元素，在队头删除元素。

Python 没有专门的队列类型，但可以使用 `deque` 来模拟队列，`append` 相当于入队，`popleft` 相当于出队。

```python
from collections import deque

# 初始化队列
q = deque()

# 向队尾插入元素
q.append(10)
q.append(20)
q.append(30)

# 是否为空，输出：False
print(len(q) == 0)

# 大小，输出：3
print(len(q))

# 获取队头元素，不出队，输出：10
print(q[0])

# 队头元素出队
q.popleft()

# 新的队头元素，输出：20
print(q[0])
```



## Python 栈 Stack

虽然 Python 没有专门的栈类型，但可以使用 `list` 或 `deque` 来模拟栈。`append` 相当于压栈，`pop` 相当于出栈。

```python
# 使用 list 作为栈
s = []

# 压栈
s.append(10)
s.append(20)
s.append(30)

# 是否为空，输出：False
print(len(s) == 0)

# 大小，输出：3
print(len(s))

# 栈顶元素，输出：30
print(s[-1])

# 出栈
s.pop()

# 新的栈顶元素，输出：20
print(s[-1])
```



## Python 字典 Dictionary 

### 1. **字典基础**

- **定义**：字典是无序集合（Python 3.7+ 后为插入有序），通过键（**不可变类型**）快速访问值，基于哈希表实现，操作平均时间复杂度为 O(1)。

- **创建方式**：

  ```python
  d1 = {'name': 'Alice', 'age': 25}           # 花括号
  d2 = dict(name='Alice', age=25)             # dict构造函数
  d3 = dict([('name', 'Alice'), ('age', 25)]) # 键值对列表
  d4 = {x: x**2 for x in range(5)}            # 字典推导式
  ```

### **2. 核心操作**

- **访问元素**：

  ```python
  value = d['name']                  # KeyError 若键不存在
  value = d.get('key', default=None) # 安全访问，返回默认值
  value = d.setdefault('key', 0)     # 若键不存在，设置默认值后返回
  ```

- **增删改**：

  ```python
  d['new_key'] = 'value'    # 添加或修改
  del d['key']              # 删除键（KeyError 若不存在）
  value = d.pop('key')      # 删除并返回值（可设默认值）
  k, v = d.popitem()        # 删除并返回最后插入的键值对（Python 3.7+）
  ```

- **遍历**：

  ```py
  for key in d: ...                 # 遍历键（等效于 d.keys()）
  for value in d.values(): ...      # 遍历值
  for key, value in d.items(): ...  # 遍历键值对
  ```

### **3. 常用方法**

- **合并更新**：

```python
  d.update({'age': 26})          # 合并字典或键值对
  d3 = {**d1, **d2}             # 字典解包合并（Python 3.5+）
  d3 = d1 | d2                  # 使用 | 运算符合并（Python 3.9+）
```

- **其他方法**：

```python
  d.clear()          # 清空字典
  d.copy()           # 浅拷贝
  len(d)             # 键的数量
```

### **4. 特性与注意事项**

- **==键的要求：==**
  - **==必须是不可变类型（如字符串、数字、元组）。==**
  - **==不允许重复，后插入的值会覆盖前者。==**
- **有序性**（Python 3.7+）：
  - 默认保留插入顺序，但删除后重新插入的键会置于末尾。
- **==相等性判断：==**
  - **==键值对内容相同即相等，与顺序无关：`{'a':1, 'b':2} == {'b':2, 'a':1}` 为 `True`。==**
- **性能与内存**：
  - 查找、插入、删除平均 O(1)，但内存占用较高。

### **5. 高级用法**

- **默认值处理**：

```python
  from collections import defaultdict
  d = defaultdict(int)  # 不存在的键返回 0
```

- **避免遍历时修改**：

```python
  for key in list(d.keys()):  # 先转换为列表
      if condition:
          del d[key]
```

- **嵌套字典**：

```python
  nested = {'user': {'name': 'Alice', 'age': 25}}
  age = nested['user']['age']
```

### **6. 应用场景**

- **快速查找**：缓存、配置项、数据库查询结果。

- **计数统计**：

```python
  counts = {}
  for word in words:
      counts[word] = counts.get(word, 0) + 1
```

- **JSON 转换**：

```python
  import json
  json_str = json.dumps(d)   # 字典转 JSON
  d = json.loads(json_str)   # JSON 转字典
```



### 集合 `set`（哈希集合）

`set` 是 Python 的哈希集合，用于存储不重复元素，常用于去重和快速查询元素是否存在。

```python
# 初始化集合
hashset = {1, 2, 3, 4}

# 是否为空，输出：False
print(len(hashset) == 0)

# 大小，输出：4
print(len(hashset))

# 查找元素
if 3 in hashset:
    print("Element 3 found.")
else:
    print("Element 3 not found.")
# 输出：Element 3 found.

# 插入新元素
hashset.add(5)

# 删除元素 2
hashset.discard(2)  # discard 不存在的元素不会报错

# 检查删除后
if 2 in hashset:
    print("Element 2 found.")
else:
    print("Element 2 not found.")
# 输出：Element 2 not found.

# 遍历集合，输出：
# 1
# 3
# 4
# 5
for element in hashset:
    print(element)
```



## Python 可变 vs 不可变类型

在 Python 中，所有数据都是对象（object）。根据对象创建后其值是否可以修改，可将对象分为两类：

- **可变类型（Mutable Type）**：对象创建后，其内容可以被修改
- **不可变类型（Immutable Type）**：对象创建后，其内容不可修改，**==任何修改行为都会创建新对象==**



### **一、不可变类型（Immutable Types）**

不可变类型一旦创建，其值不可更改。对其执行“修改”操作会生成新的对象，原对象保持不变。

**常见的不可变类型：**

- 整数（`int`）
- 浮点数（`float`）
- 布尔值（`bool`）
- 字符串（`str`）
- 元组（`tuple`）
- 冻结集合（`frozenset`）
- 字节串（`bytes`）

**示例：**

```python
x = 5

def change(val):
    val += 1
    print("函数内部:", val)

change(x)
print("函数外部:", x)
```

输出：

```python
函数内部: 6
函数外部: 5
```

解释：`int` 是不可变类型，`val += 1` 实际上创建了一个新的整数对象，不影响原变量 `x`。



### 二、可变类型（Mutable Types）

可变类型允许在不改变对象引用的前提下修改其内容。即修改操作作用于原始对象本身。

**常见的可变类型：**

- 列表（`list`）
- 字典（`dict`）
- 集合（`set`）
- 自定义类的实例
- 字节数组（`bytearray`）

示例：

```python
a = [1, 2, 3]

def modify(lst):
    lst.append(4)

modify(a)
print(a)
```

输出：

```python
[1, 2, 3, 4]
```

解释：`list` 是可变类型，函数中对其进行修改直接影响了原始对象。



### 三、函数参数传递与类型可变性的关系

Python 的函数参数传递方式为：

> 传递的是对象的引用的副本（call by object reference）

- 如果传入的是**不可变类型**：函数内部对参数的修改不会影响原始变量
- 如果传入的是**可变类型**：函数内部对参数内容的修改会影响原始变量



### 四、默认参数的可变类型陷阱

```python
def append_item(item, lst=[]):  # 不推荐
    lst.append(item)
    return lst

print(append_item(1))  # [1]
print(append_item(2))  # [1, 2] —— 使用了同一个列表对象
```

推荐写法：

```python
def append_item(item, lst=None):
    if lst is None:
        lst = []
    lst.append(item)
    return lst
```



### 五、常见数据类型分类总结

| 数据类型    | 可变性 | 说明                             |
| ----------- | ------ | -------------------------------- |
| `int`       | 不可变 | 数值类型，操作创建新对象         |
| `float`     | 不可变 | 同上                             |
| `bool`      | 不可变 | `True`, `False`                  |
| `str`       | 不可变 | 所有字符串均不可变               |
| `tuple`     | 不可变 | 元组本身不可变，但内部元素可变   |
| `list`      | 可变   | 可添加、修改、删除元素           |
| `dict`      | 可变   | 可增删键值对                     |
| `set`       | 可变   | 无序、唯一性集合，可添加删除元素 |
| `frozenset` | 不可变 | 不可变集合                       |
| `bytearray` | 可变   | 可修改的字节序列                 |
| `bytes`     | 不可变 | 不可修改的字节序列               |



## Python 深浅拷贝问题：

### **1. 基本概念**

#### **1.1 赋值操作（不是拷贝）**

- ==**赋值**（`=`）仅复制对象的**引用**（内存地址），新旧变量指向同一个对象。==

- **修改一个会影响另一个**：

  ```python
  a = [1, 2, [3, 4]]
  b = a  # 赋值操作，b 和 a 指向同一个列表
  b.append(5)
  print(a)  # 输出 [1, 2, [3, 4], 5]（a 和 b 共享同一对象）
  ```



#### **1.2 浅拷贝（Shallow Copy）**

- **浅拷贝**创建一个新对象，但仅复制原对象的**顶层引用**（不递归复制内部对象）。==**创建新对象，但内部元素是原对象元素的引用。**==
- 适用于不可变元素，但嵌套的可变对象仍共享引用。
- **实现方式**：
  - `copy()` 方法：`new_list = old_list.copy()`
  - 列表切片：`new_list = old_list[:]`
  - `list()` 构造函数：`new_list = list(old_list)`
  - `copy` 模块：`import copy; new_list = copy.copy(old_list)`

```py
import copy

a = [1, 2, [3, 4]]
b = copy.copy(a)  # 浅拷贝
b.append(5)       # 修改 b 的顶层元素，不影响 a
b[2].append(99)   # 修改嵌套列表，a 和 b 共享该嵌套列表！

print(a)  # 输出 [1, 2, [3, 4, 99]]（嵌套列表被修改）
print(b)  # 输出 [1, 2, [3, 4, 99], 5]
```





#### **1.3 深拷贝（Deep Copy）**

- **深拷贝**创建一个新对象，并递归复制所有内部对象，完全独立于原对象。

- 适用于多层嵌套的可变对象。

- **实现方式**：

  ```python
  import copy
  
  a = [1, 2, [3, 4]]
  b = copy.deepcopy(a)  # 深拷贝
  b.append(5)
  b[2].append(99)       # 嵌套列表独立，不影响 a
  
  print(a)  # 输出 [1, 2, [3, 4]]
  print(b)  # 输出 [1, 2, [3, 4, 99], 5]
  ```



### 2. **深浅拷贝的核心区别**

| **操作**     | **赋值**   | **浅拷贝**                   | **深拷贝**             |
| :----------- | :--------- | :--------------------------- | :--------------------- |
| **复制内容** | 仅复制引用 | 复制顶层结构，嵌套层共享引用 | 递归复制所有层级       |
| **独立性**   | 完全共享   | 顶层独立，嵌套层共享         | 完全独立               |
| **适用场景** | 无独立需求 | 外层独立，内层无嵌套或不可变 | 多层嵌套且需要完全独立 |



### 3. 自定义对象的拷贝

- **浅拷贝**：默认复制对象的引用，若对象内部有可变属性，仍需谨慎。

- **深拷贝**：通过 `__deepcopy__` 方法自定义递归拷贝逻辑。

- 示例：

  ```python
  class MyClass:
      def __init__(self, data):
          self.data = data
  
      def __deepcopy__(self, memo):
          new_data = copy.deepcopy(self.data, memo)
          return MyClass(new_data)
  
  obj = MyClass([1, 2, 3])
  obj_copy = copy.deepcopy(obj)
  ```



## Python 值传递以及引用传递

在 Python 中，参数传递的机制被称为 **“传对象引用”（Call by Sharing）**。这种机制既不是纯粹的“值传递”（传拷贝）也不是“引用传递”（传内存地址），而是通过传递对象的引用来实现。具体行为取决于对象的类型（可变或不可变）：

### 核心机制

1. **传递的是对象的引用**
   **==所有变量在 Python 中都是对象的引用。当调用函数时，实参的引用（即指向对象的指针）会被复制给形参。因此，形参和实参指向同一个对象。==**
2. **可变对象 vs 不可变对象**
   - **可变对象**（如列表、字典）：
     函数内部对对象的修改（如增删元素）会直接影响外部对象，因为操作的是同一个对象。
   - **不可变对象**（如整数、字符串、元组）：
     函数内部对形参的“修改”实际上是让形参指向新对象，不会影响外部实参的指向。==**不可变对象（immutable）一旦创建，就不能被修改。因此，任何在函数内的对于形参的“修改”操作（如 `+=`、`=`）都会创建一个新对象，并让变量引用这个新对象。**==

#### 示例 1：不可变对象（整数）

```python
def modify(x):
    x = 10  # 形参 x 指向新对象 10
    print("函数内 x:", x)

a = 5
modify(a)    # 输出：函数内 x: 10
print("函数外 a:", a)  # 输出：函数外 a: 5（外部 a 仍指向原对象 5）
```

#### 示例 2：可变对象（列表）

```python
def modify_list(lst):
    lst.append(4)  # 直接修改原列表
    print("函数内 lst:", lst)

my_list = [1, 2, 3]
modify_list(my_list)  # 输出：函数内 lst: [1, 2, 3, 4]
print("函数外 my_list:", my_list)  # 输出：函数外 my_list: [1, 2, 3, 4]
```

------

### 关键结论

| 行为               | 可变对象（如列表）         | 不可变对象（如整数）         |
| :----------------- | :------------------------- | :--------------------------- |
| **传递内容**       | 对象引用（内存地址）       | 对象引用（内存地址）         |
| **函数内修改对象** | 直接影响外部对象           | 无法直接修改，只能创建新对象 |
| **重新赋值形参**   | 形参指向新对象，不影响外部 | 形参指向新对象，不影响外部   |

------

### 类比其他语言

- **类似 Java 的“对象引用传递”**：Python 的行为与 Java 中传递对象引用的方式类似。
- **与 C++ 的引用传递不同**：Python 不会直接操作原始变量的地址，而是通过引用的拷贝操作对象。

------

### 总结

- **Python 参数传递的本质**是传递对象的引用（即“传共享”）。
- **是否影响外部变量**取决于对象的可变性：
  - 修改可变对象的内容（如 `list.append()`）会影响外部。
  - 对不可变对象的操作（如 `x += 1`）会创建新对象，不影响外部。



## Python 面向对象

Python从设计之初就已经是一门面向对象的语言，正因为如此，在Python中创建一个类和对象是很容易的。本章节我们将详细介绍Python的面向对象编程。

我们先来简单的了解下面向对象的一些基本特征。



### **面向对象技术简介**

* **类(Class):**
  用来描述具有相同的属性和方法的对象的集合。它定义了该集合中每个对象所共有的属性和方法。对象是类的实例。
* **类变量：**
  类变量在整个实例化的对象中是公用的。类变量定义在类中且在函数体之外。类变量通常不作为实例变量使用。
* **数据成员：**
  类变量或者实例变量, 用于处理类及其实例对象的相关的数据。
* **方法重写：**
  如果从父类继承的方法不能满足子类的需求，可以对其进行改写，这个过程叫方法的覆盖（override），也称为方法的重写。
* **局部变量：**
  定义在方法中的变量，只作用于当前实例的类。
* **实例变量：**
  在类的声明中，属性是用变量来表示的。这种变量就称为实例变量，是在类声明的内部但是在类的其他成员方法之外声明的。
* **继承：**
  即一个派生类（derived class）继承基类（base class）的字段和方法。继承也允许把一个派生类的对象作为一个基类对象对待。例如，有这样一个设计：一个Dog类型的对象派生自Animal类，这是模拟"是一个（is-a）"关系（例图，Dog是一个Animal）。
* **实例化：**
  创建一个类的实例，类的具体对象。
* **方法：**
  类中定义的函数。
* **对象：**
  通过类定义的数据结构实例。对象包括两个数据成员（类变量和实例变量）和方法。



### 创建类

使用 class 语句来创建一个新类，class 之后为类的名称并以冒号结尾:

```python
class ClassName:
   '类的帮助信息'   #类文档字符串
   class_suite  #类体

```

类的帮助信息可以通过ClassName.\_\_doc\_\_查看。

class\_suite 由类成员，方法，数据属性组成。

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
class Employee:
   '所有员工的基类'
   empCount = 0
 
   def __init__(self, name, salary):
      self.name = name
      self.salary = salary
      Employee.empCount += 1
   
   def displayCount(self):
     print "Total Employee %d" % Employee.empCount
 
   def displayEmployee(self):
      print "Name : ", self.name,  ", Salary: ", self.salary
```

* empCount 变量是一个**==类变量，它的值将在这个类的所有实例之间共享。==**你可以在内部类或外部类使用 Employee.empCount 访问。
* ==**第一种方法\_\_init\_\_()方法是一种特殊的方法，被称为类的构造函数或初始化方法，当创建了这个类的实例时就会调用该方法**==
* **==self 代表类的实例，self 在定义类的方法时是必须有的，虽然在调用时不必传入相应的参数。==**



**self代表类的实例，而非类**

类的方法与普通的函数只有一个特别的区别——它们必须有一个额外的**第一个参数名称**, 按照惯例它的名称是 self。

```python
class Test:
    def prt(self):
        print(self)
        print(self.__class__)
 
t = Test()
t.prt()
```

以上实例执行结果为：

```python
<__main__.Test instance at 0x10d066878>
__main__.Test
```

从执行结果可以很明显的看出，self 代表的是类的实例，代表当前对象的地址，而 **self.__class__** 则指向类。

self 不是 python 关键字，我们把他换成 runoob 也是可以正常执行的:

**实例**

```python
class Test:
    def prt(runoob):
        print(runoob)
print(runoob.__class__)
t = Test()
t.prt()
```

以上实例执行结果为：

```python
<__main__.Test instance at 0x10d066878>
__main__.Test

```



### 创建实例对象

实例化类其他编程语言中一般用关键字 new，但是在 Python 中并没有这个关键字，类的实例化类似函数调用方式。

以下使用类的名称 Employee 来实例化，并通过 \_\_init\_\_ 方法接收参数。

```python
"创建 Employee 类的第一个对象"
emp1 = Employee("Zara", 2000)
"创建 Employee 类的第二个对象"
emp2 = Employee("Manni", 5000)

```



### 访问属性

您可以使用点号` . `来访问对象的属性。使用如下类的名称访问类变量:

```python
emp1.displayEmployee()
emp2.displayEmployee()
print "Total Employee %d" % Employee.empCount

```

完整实例：

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
class Employee:
   '所有员工的基类'
   empCount = 0
 
   def __init__(self, name, salary):
      self.name = name
      self.salary = salary
      Employee.empCount += 1
   
   def displayCount(self):
     print "Total Employee %d" % Employee.empCount
 
   def displayEmployee(self):
      print "Name : ", self.name,  ", Salary: ", self.salary
 
"创建 Employee 类的第一个对象"
emp1 = Employee("Zara", 2000)
"创建 Employee 类的第二个对象"
emp2 = Employee("Manni", 5000)
emp1.displayEmployee()
emp2.displayEmployee()
print "Total Employee %d" % Employee.empCount
```

执行以上代码输出结果如下：

```python
Name :  Zara ,Salary:  2000
Name :  Manni ,Salary:  5000
Total Employee 2

```

你可以添加，删除，修改类的属性，如下所示：

```python
emp1.age = 7  # 添加一个 'age' 属性
emp1.age = 8  # 修改 'age' 属性
del emp1.age  # 删除 'age' 属性

```

你也可以使用以下函数的方式来访问属性：

* getattr(obj, name[, default]) : 访问对象的属性。
* hasattr(obj,name) : 检查是否存在一个属性。
* setattr(obj,name,value) : 设置一个属性。如果属性不存在，会创建一个新属性。
* delattr(obj, name) : 删除属性。

```python
hasattr(emp1, 'age') # 如果存在 'age' 属性返回 True。
getattr(emp1, 'age') # 返回 'age' 属性的值
setattr(emp1, 'age', 8) # 添加属性 'age' 值为 8
delattr(emp1, 'age') # 删除属性 'age'
```



### Python内置类属性

* ==**\_\_dict\_\_ : 类的属性（包含一个字典，由类的数据属性组成）**==
* ==**\_\_doc\_\_ :类的文档字符串**==
* ==**\_\_name\_\_: 类名**==
* ==**\_\_module\_\_: 类定义所在的模块（类的全名是'\_\_main\_\_.className'，如果类位于一个导入模块mymod中，那么className.\_\_module\_\_ 等于 mymod）**==
* ==**\_\_bases\_\_ : 类的所有父类构成元素（包含了一个由所有父类组成的元组）**==

Python内置类属性调用实例如下：

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
class Employee:
   '所有员工的基类'
empCount = 0
def __init__(self, name, salary):
      self.name = name
self.salary = salary
Employee.empCount += 1
def displayCount(self):
     print "Total Employee %d" % Employee.empCount
def displayEmployee(self):
      print "Name : ", self.name,  ", Salary: ", self.salary
print "Employee.__doc__:", Employee.__doc__
print "Employee.__name__:", Employee.__name__
print "Employee.__module__:", Employee.__module__
print "Employee.__bases__:", Employee.__bases__
print "Employee.__dict__:", Employee.__dict__
```

执行以上代码输出结果如下：

```python
Employee.__doc__: 所有员工的基类
Employee.__name__: Employee
Employee.__module__: __main__
Employee.__bases__: ()
Employee.__dict__: {'__module__': '__main__', 'displayCount': <function displayCount at 0x10a939c80>, 'empCount': 0, 'displayEmployee': <function displayEmployee at 0x10a93caa0>, '__doc__': '\xe6\x89\x80\xe6\x9c\x89\xe5\x91\x98\xe5\xb7\xa5\xe7\x9a\x84\xe5\x9f\xba\xe7\xb1\xbb', '__init__': <function __init__ at 0x10a939578>}

```



### python对象销毁(垃圾回收)

Python 使用了==**引用计数**==这一简单技术来跟踪和回收垃圾。

在 Python 内部记录着所有使用中的对象各有多少引用。

一个内部跟踪变量，称为一个引用计数器。

当对象被创建时， 就创建了一个引用计数， 当这个对象不再需要时，
**也就是说， 这个对象的引用计数变为0 时， 它被垃圾回收。但是回收不是"立即"的，**
**由解释器在适当的时机，将垃圾对象占用的内存空间回收。**

```python
a = 40      # 创建对象  <40>
b = a       # 增加引用， <40> 的计数
c = [b]     # 增加引用.  <40> 的计数

del a       # 减少引用 <40> 的计数
b = 100     # 减少引用 <40> 的计数
c[0] = -1   # 减少引用 <40> 的计数

```

垃圾回收机制不仅针对引用计数为0的对象，==**同样也可以处理循环引用的情况。**==循环引用指的是，两个对象相互引用，但是没有其他变量引用他们。这种情况下，仅使用引用计数是不够的。**==Python 的垃圾收集器实际上是一个引用计数器和一个循环垃圾收集器。==**作为引用计数的补充， 垃圾收集器也会留心被分配的总量很大（即未通过引用计数销毁的那些）的对象。 在这种情况下， 解释器会暂停下来， 试图清理所有未引用的循环。

析构函数 \_\_del\_\_ ，\_\_del\_\_在对象销毁的时候被调用，当对象不再被使用时，\_\_del\_\_方法运行：

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
class Point:
   def __init__( self, x=0, y=0):
      self.x = x
      self.y = y
   def __del__(self):
      class_name = self.__class__.__name__
      print class_name, "销毁"
 
pt1 = Point()
pt2 = pt1
pt3 = pt1
print id(pt1), id(pt2), id(pt3) # 打印对象的id
del pt1
del pt2
del pt3
```

以上实例运行结果如下：

```python
3083401324 3083401324 3083401324
Point 销毁

```

**注意：**
通常你需要在单独的文件中定义一个类，



### 类的继承

面向对象的编程带来的主要好处之一是代码的重用，实现这种重用的方法之一是通过继承机制。

通过继承创建的新类称为**子类**或**派生类**，被继承的类称为**基类**、**父类**或**超类**。

**继承语法**

```python
class 派生类名(基类名)
    ...

```

在python中继承中的一些特点：

* 1、如果在子类中需要父类的构造方法就需要显式的调用父类的构造方法，或者不重写父类的构造方法。详细说明可查看：[ python 子类继承父类构造函数说明](https://www.runoob.com/w3cnote/python-extends-init.html)。
* 2、在调用基类的方法时，需要加上基类的类名前缀，且需要带上 self 参数变量。区别在于类中调用普通函数时并不需要带上 self 参数
* 3、Python 总是首先查找对应类型的方法，如果它不能在派生类中找到对应的方法，它才开始到基类中逐个查找。（先在本类中查找调用的方法，找不到才去基类中找）。

如果在继承元组中列了一个以上的类，那么它就被称作"多重继承" 。

**语法：**

派生类的声明，与他们的父类类似，继承的基类列表跟在类名之后，如下所示：

```python
class SubClassName (ParentClass1[, ParentClass2, ...]):
    ...

```

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
class Parent:        # 定义父类
   parentAttr = 100
   def __init__(self):
      print "调用父类构造函数"
 
   def parentMethod(self):
      print '调用父类方法'
 
   def setAttr(self, attr):
      Parent.parentAttr = attr
 
   def getAttr(self):
      print "父类属性 :", Parent.parentAttr
 
class Child(Parent): # 定义子类
   def __init__(self):
      print "调用子类构造方法"
 
   def childMethod(self):
      print '调用子类方法'
 
c = Child()          # 实例化子类
c.childMethod()      # 调用子类的方法
c.parentMethod()     # 调用父类方法
c.setAttr(200)       # 再次调用父类的方法 - 设置属性值
c.getAttr()          # 再次调用父类的方法 - 获取属性值
```

以上代码执行结果如下：

```python
调用子类构造方法
调用子类方法
调用父类方法
父类属性 : 200

```

你可以继承多个类

```python
class A:        # 定义类 A
.....

class B:         # 定义类 B
.....

class C(A, B):   # 继承类 A 和 B
.....

```

你可以使用issubclass()或者isinstance()方法来检测。

* issubclass() - 布尔函数判断一个类是另一个类的子类或者子孙类，语法：issubclass(sub,sup)
* isinstance(obj, Class) 布尔函数如果obj是Class类的实例对象或者是一个Class子类的实例对象则返回true。



### 方法重写

如果你的父类方法的功能不能满足你的需求，你可以在子类重写你父类的方法：

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
class Parent:        # 定义父类
def myMethod(self):
      print '调用父类方法'
class Child(Parent): # 定义子类
def myMethod(self):
      print '调用子类方法'
c = Child() # 子类实例
c.myMethod() # 子类调用重写方法
```

执行以上代码输出结果如下：

```python
调用子类方法

```



### 基础重载方法

下表列出了一些通用的功能，你可以在自己的类重写：

| 序号 | 方法, 描述 & 简单的调用                                      |
| ---- | ------------------------------------------------------------ |
| 1    | **\_\_init\_\_ ( self [,args...] )**   构造函数   简单的调用方法: *obj = className(args)* |
| 2    | **\_\_del\_\_( self )**   析构方法, 删除一个对象   简单的调用方法 : *del obj* |
| 3    | **\_\_repr\_\_( self )**   转化为供解释器读取的形式   简单的调用方法 : *repr(obj)* |
| 4    | **\_\_str\_\_( self )**   用于将值转化为适于人阅读的形式   简单的调用方法 : *str(obj)* |
| 5    | **\_\_cmp\_\_ ( self, x )**   对象比较   简单的调用方法 : *cmp(obj, x)* |



### 运算符重载

Python同样支持运算符重载，实例如下：

**实例**

```python
#!/usr/bin/python
class Vector:
   def __init__(self, a, b):
      self.a = a
self.b = b
def __str__(self):
      return 'Vector (%d, %d)' % (self.a, self.b)
def __add__(self,other):
      return Vector(self.a + other.a, self.b + other.b)
v1 = Vector(2,10)
v2 = Vector(5,-2)
print v1 + v2
```

以上代码执行结果如下所示:

```python
Vector(7,8)

```



### 类属性与方法

#### 类的私有属性

**__private_attrs**：两个下划线开头，声明该属性为私有，不能在类的外部被使用或直接访问。在类内部的方法中使用时 **self.__private_attrs**。



#### 类的方法

在类的内部，使用 **def** 关键字可以为类定义一个方法，与一般函数定义不同，类方法必须包含参数 self,且为第一个参数



#### 类的私有方法

**__private_method**：两个下划线开头，声明该方法为私有方法，不能在类的外部调用。在类的内部调用 **self.__private_methods**

**实例**

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
class JustCounter:
    __secretCount = 0  # 私有变量
    publicCount = 0    # 公开变量
 
    def count(self):
        self.__secretCount += 1
        self.publicCount += 1
        print self.__secretCount
 
counter = JustCounter()
counter.count()
counter.count()
print counter.publicCount
print counter.__secretCount  # 报错，实例不能访问私有变量
```

Python 通过改变名称来包含类名:

```python
1
2
2
Traceback (most recent call last):
  File "test.py", line 17, in <module>
    print counter.__secretCount  # 报错，实例不能访问私有变量
AttributeError: JustCounter instance has no attribute '__secretCount'

```

Python不允许实例化的类访问私有数据，但你可以使用 **object._className__attrName**（ **对象名._类名__私有属性名** ）访问属性，参考以下实例：

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-

class Runoob:
    __site = "www.runoob.com"

runoob = Runoob()
print runoob._Runoob__site

```

执行以上代码，执行结果如下：

```python
www.runoob.com

```



#### 单下划线、双下划线、头尾双下划线说明：

* **__foo__**: 定义的是特殊方法，一般是系统定义名字 ，类似 **__init__()** 之类的。
* **_foo**: 以单下划线开头的表示的是 protected 类型的变量，即保护类型只能允许其本身与子类进行访问，不能用于 **from module import \***
* **__foo**: 双下划线的表示的是私有类型(private)的变量, 只能是允许这个类本身进行访问了。子类也不行。



## Python泛型

Python 的 **泛型（Generics）** 是用来编写可以接受**多种类型**的函数或类，而不牺牲类型检查的能力。它主要用于**类型提示（type hint）系统**，比如 `List[int]`、`Optional[str]`、`Dict[str, float]`，底层其实都用到了泛型。

#### 自定义泛型：`TypeVar`

你可以用 `TypeVar` 定义自己的泛型函数或类：

```python
from typing import TypeVar, List

T = TypeVar('T')  # 声明一个类型变量 T

def first(lst: List[T]) -> T:
    return lst[0]
```

这样就可以支持：

```python
first([1, 2, 3])       # 推断 T 是 int
first(["a", "b"])  
```



#### 泛型类示例

```python
from typing import Generic, TypeVar

T = TypeVar('T')

class Box(Generic[T]):
    def __init__(self, content: T):
        self.content = content

    def get(self) -> T:
        return self.content
```

用法：

```python
box_int = Box(123)      # 推断为 Box[int]
box_str = Box("hello")  # 推断为 Box[str]
```



## Python String

### Python `String.join`

```python
", ".join(序列)
```

`join()` 是字符串的一个方法，用来把一个**字符串序列**用指定的分隔符连接起来。

示例：

```python
", ".join(["a", "b", "c"])  # 输出：'a, b, c'
```

> 它要求序列里的元素**必须都是字符串类型**，否则会报错。在 Python 中，**字符串序列（sequence of strings）**指的是：一组字符串组成的有序集合，比如：列表（`list`）、元组（`tuple`）、生成器（`generator`）



## Python 可迭代对象

### 一、什么是“可迭代对象（iterable）”？

==**可迭代对象**是指：**可以逐个返回其元素的对象**。简单说，就是你可以用 `for ... in ...` 来遍历它。==

**判断方式**

**==你可以用 `isinstance(obj, collections.abc.Iterable)` 来判断一个对象是否是可迭代的。==**

### 二、常见的可迭代对象有哪些？

Python 中常见的可迭代对象有：

- `list`（列表）
- `tuple`（元组）
- `str`（字符串）
- `dict`（字典）
- `set`（集合）
- `range()`
- 文件对象（`open(...)` 返回的文件）
- 自定义实现了 `__iter__()` 或 `__getitem__()` 的类

### 三、可迭代对象的本质

本质上，一个对象是可迭代的，只要它实现了以下**任一**方法：

**方法一：实现 `__iter__()` 方法**

```python
class MyList:
    def __iter__(self):
        # 返回一个迭代器对象
        ...
```

**方法二：实现 `__getitem__()` 方法（老版本兼容）**

```python
python


CopyEdit
class OldStyle:
    def __getitem__(self, index):
        # 必须支持从索引 0 开始逐个取值，直到抛出 IndexError 为止
        ...
```

### 四、可迭代对象 vs 迭代器（iterator）

**区别**

| 项目                     | 可迭代对象（Iterable） | 迭代器（Iterator） |
| ------------------------ | ---------------------- | ------------------ |
| 是否可用于 for 循环      | ✅ 是                   | ✅ 是               |
| 是否有 `__iter__()` 方法 | ✅ 有                   | ✅ 有               |
| 是否有 `__next__()` 方法 | ❌ 没有                 | ✅ 有               |
| 能否用 `next()` 函数     | ❌ 不行                 | ✅ 可以             |
| 是否一次性（耗尽）       | ❌ 不是                 | ✅ 是               |

“**一次性（耗尽）**”意思是：

> **一旦你遍历了迭代器，它的元素就不能再重新访问了，除非你重新创建它。**

示例：

```python
lst = [1, 2, 3]
it = iter(lst)        # 将可迭代对象变为迭代器
print(next(it))       # 输出 1
print(next(it))       # 输出 2
```

### 五、for 循环背后的机制

Python 的 `for item in iterable:` 实际上等价于下面的操作：

```python
it = iter(iterable)
while True:
    try:
        item = next(it)
        # 执行循环体
    except StopIteration:
        break
```

### 六、可迭代对象与生成器的关系

**生成器（generator）也是一种特殊的可迭代对象，但它每次调用 `next()` 才动态生成下一个元素，不一次性占用内存，非常适合处理大数据流。**

生成器的创建方式：

- 使用 `yield` 的函数
- 或者使用**生成器表达式**，如 `(x for x in range(10))`

### 七、如何自定义一个可迭代对象？

你可以通过实现 `__iter__()` 方法来自定义一个可迭代对象。

**示例：**

```python
class MyRange:
    def __init__(self, n):
        self.n = n

    def __iter__(self):
        self.i = 0
        return self  # 返回一个迭代器

    def __next__(self):
        if self.i < self.n:
            val = self.i
            self.i += 1
            return val
        else:
            raise StopIteration

# 使用：
for num in MyRange(5):
    print(num)  # 输出 0 1 2 3 4
```

### 总结

| 概念                   | 核心特点                                                     |
| ---------------------- | ------------------------------------------------------------ |
| 可迭代对象（Iterable） | 可以用于 `for` 循环；必须实现 `__iter__()` 或 `__getitem__()` |
| 迭代器（Iterator）     | 可迭代 + 实现 `__next__()`；每次 `next()` 返回一个值，直到抛出 `StopIteration` |
| 判断是否可迭代         | `isinstance(obj, collections.abc.Iterable)`                  |
| 转换成迭代器           | 使用 `iter(obj)`                                             |



## Python中的生成器 vs 推导式

这是 Python 中非常核心但容易混淆的两个概念，下面系统地对比讲解：**生成器（generator）** 和 **推导式（comprehension）**

------

**一句话区分**

| 名称   | 简要说明                             |
| ------ | ------------------------------------ |
| 推导式 | 一种快速构造列表、集合或字典的语法糖 |
| 生成器 | 一种按需生成元素、节省内存的迭代器   |

------

### 一、推导式(Comprehensions)

1. **列表推导式（最常见）**

```python
squares = [x * x for x in range(5)]
print(squares)  # 输出: [0, 1, 4, 9, 16]
```

- 一次性生成所有元素
- 占用一定内存
- 可以用于任意 `for` 和 `if` 组合

2. **集合和字典推导式**

```python
s = {x for x in "hello"}             # 集合推导式，自动去重
d = {x: x * x for x in range(3)}     # 字典推导式
```

### 二、生成器(Generator)

生成器用于**按需生成元素**，不会一次性占用内存，适合**大规模或无限序列。**

**1. 生成器表达式（小括号）**

```python
g = (x * x for x in range(5))
print(next(g))  # 输出: 0
print(next(g))  # 输出: 1
```

- 每次调用 `next()` 生成一个元素
- **==用完就不能再用（迭代器特性）==**

**2. 生成器函数（使用 `yield`）**

```python
def my_gen():
    for x in range(3):
        yield x

g = my_gen()
print(next(g))  # 输出: 0
```

- `yield` 替代 `return`，函数变成生成器对象
- 保留函数执行状态，适合复杂逻辑

------

### 三、对比总结

| 特性               | 推导式               | 生成器                        |
| ------------------ | -------------------- | ----------------------------- |
| 语法形式           | `[x for x in ...]`   | `(x for x in ...)` 或 `yield` |
| 是否一次性生成所有 | 是                   | 否（按需生成）                |
| 内存开销           | 较高                 | 较低                          |
| 是否可重复遍历     | 是                   | 否（遍历一次后就 exhausted）  |
| 使用场景           | 小数据、临时构造结构 | 大数据、懒加载、节省内存      |

------

### 四、实例对比

**列表推导式（立刻构建）**

```python
big_list = [x for x in range(10**6)]  # 占用大量内存
```

**生成器表达式（延迟计算）**

```python
big_gen = (x for x in range(10**6))   # 几乎不占内存
```



## Python中的Import

| 导入方式                  | 优点                           | 缺点                   |
| ------------------------- | ------------------------------ | ---------------------- |
| `import module`           | 命名清晰、安全                 | 使用时必须写 `module.` |
| `import module as alias`  | 适合缩写（如 `np`）            | 同上                   |
| `from module import name` | 使用方便、简洁。不用 `module.` | 命名冲突风险           |
| `from module import *`    | 快速试验（不推荐）             | 命名空间污染，易出错   |





