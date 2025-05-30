jPython Cheat Sheet

> Updated: Jan 22, 2025
> Author: Navdeep Singh

This guide is a collection of Python code snippets that cover the basics of the language. It is intended to be a quick reference for anyone who is new to Python or needs a refresher.

You may also find the following courses helpful:

- [Python for Beginners](https://neetcode.io/problems/python-hello-world) - Learn the basics of Python with 80 interactive coding challenges.
- [Python for Coding Interviews](https://neetcode.io/problems/python-sort-custom) - Learn how to use all of the built-in data structures and algorithms in Python.
- [Python for Object-Oriented Programming](https://neetcode.io/problems/python-intro-to-classes) - Learn how to write object-oriented code in Python.

## Variables

```python
# Variables are dynamicly typed
n = 0
print('n =', n)
>>> n = 0

n = "abc"
print('n =', n)
>>> n = abc

# Multiple assignments
n, m = 0, "abc"
n, m, z = 0.125, "abc", False

# Increment
n = n + 1 # good
n += 1    # good

# None is null (absence of value)
n = 4
n = None
print("n =", n)
>>> n = None
```



## If-statements

```python
# If statements don't need parentheses 
# or curly braces.
n = 1
if n > 2:
    n -= 1
elif n == 2:
    n *= 2
else:
    n += 2

# Parentheses needed for multi-line conditions.
# and = &&
# or  = ||
n, m = 1, 2
if ((n > 2 and 
    n != m) or n == m):
    n += 1
```



## Loops

```python
n = 5
while n < 5:
    print(n)
    n += 1

# Looping from i = 0 to i = 4
for i in range(5):
    print(i)

# Looping from i = 2 to i = 5
for i in range(2, 6):
    print(i)

# Looping from i = 5 to i = 2
for i in range(5, 1, -1):
    print(i)
```



## Math

| Method         | Behavior                  | Example (`-7/2`)     |
| -------------- | ------------------------- | -------------------- |
| `//`           | Floor division (downward) | `-4`                 |
| `int()`        | Truncates toward zero     | `-3`                 |
| `math.floor()` | Always rounds down        | `-4`                 |
| `math.ceil()`  | Always rounds up          | `-3`                 |
| `round()`      | round half to even        | `round(-3.5)` → `-4` |

```python
# Regular division returns a float (even if it divides evenly)
print(5 / 2)       # Output: 2.5

# Double slash performs floor division (rounds down toward -infinity)
print(5 // 2)      # Output: 2
print(-3 // 2)     # Output: -2  ← rounds *down* to -2, not toward zero!

# To mimic C-style behavior (rounding toward zero), use:
print(int(-3 / 2)) # Output: -1  ← truncates toward 0

# Standard modulo (remainder)
print(10 % 3)      # Output: 1

# Python keeps the result sign the same as the divisor (positive 3 here)
print(-10 % 3)     # Output: 2

print(math.floor(3 / 2))  # Output: 1  ← round down
print(math.ceil(3 / 2))   # Output: 2  ← round up
print(math.sqrt(2))       # Output: 1.4142...
print(math.pow(2, 3))     # Output: 8.0


print(float("inf"))       # Positive infinity
print(float("-inf"))      # Negative infinity

# Python integers have arbitrary precision — no overflow!
print(math.pow(2, 200))   # Very large number
print(math.pow(2, 200) < float("inf"))  # Output: True
```



## Arrays

```python
# === Lists in Python (arrays) ===
arr = [1, 2, 3]
print(arr)  # [1, 2, 3]

# === Stack operations ===
arr.append(4)       # push
arr.append(5)
print(arr)          # [1, 2, 3, 4, 5]

arr.pop()           # pop last element
print(arr)          # [1, 2, 3, 4]

# === Insert and update elements ===
arr.insert(1, 7)    # insert 7 at index 1
print(arr)          # [1, 7, 2, 3, 4]

arr[0] = 0          # update index 0
arr[3] = 0          # update index 3
print(arr)          # [0, 7, 2, 0, 4]

# === Initialize a list of size n with a default value ===
n = 5
arr = [1] * n
print(arr)          # [1, 1, 1, 1, 1]
print(len(arr))     # 5

# === Indexing: support for negative indices ===
arr = [1, 2, 3]
print(arr[-1])      # 3 (last element)
print(arr[-2])      # 2 (second to last)

# === Slicing (sublist) ===
arr = [1, 2, 3, 4]
print(arr[1:3])     # [2, 3] (from index 1 up to but not including 3)
print(arr[0:4])     # [1, 2, 3, 4] (full list)
print(arr[0:10])    # [1, 2, 3, 4] (no out-of-bounds error)

# === Unpacking ===
a, b, c = [1, 2, 3]
print(a, b, c)      # 1 2 3

# Invalid unpacking (uncommenting will raise ValueError)
# a, b = [1, 2, 3]

# === Iteration ===
nums = [1, 2, 3]

# Using index
for i in range(len(nums)):
    print(nums[i])

# Direct iteration
for n in nums:
    print(n)

# With index and value
for i, n in enumerate(nums):
    print(i, n)

# Simultaneous iteration over multiple lists
nums1 = [1, 3, 5]
nums2 = [2, 4, 6]
for n1, n2 in zip(nums1, nums2):
    print(n1, n2)

# === Reverse a list ===
nums = [1, 2, 3]
nums.reverse()
print(nums)         # [3, 2, 1]

# === Sorting ===
arr = [5, 4, 7, 3, 8]
arr.sort()
print(arr)          # [3, 4, 5, 7, 8]

arr.sort(reverse=True)
print(arr)          # [8, 7, 5, 4, 3]

# Lexicographic sort (strings)
arr = ["bob", "alice", "jane", "doe"]
arr.sort()
print(arr)          # ['alice', 'bob', 'doe', 'jane']

# Custom sort: by string length
arr.sort(key=lambda x: len(x))
print(arr)          # ['bob', 'doe', 'jane', 'alice']

# === List Comprehension ===
arr = [i for i in range(5)]
print(arr)          # [0, 1, 2, 3, 4]

# === 2D Lists ===
arr = [[0] * 4 for _ in range(4)]
arr = [[0 for _ in range(4)] for _ in range(4)]
print(arr)
print(arr[0][0], arr[3][3])  # 0 0

# ⚠️ Don't use this (shared inner lists!)
# arr = [[0] * 4] * 4
```



## Strings

```python
# === Strings in Python ===

s = "abc"

# Strings support indexing and slicing (like arrays)
print(s[0:2])     # Output: 'ab' (characters at index 0 and 1)

# Strings are immutable — cannot assign directly to an index
# s[0] = "A"      # ❌ This would raise a TypeError

# Modifying a string creates a new string
s += "def"
print(s)          # Output: 'abcdef'

# === String and number conversion ===

# Convert valid numeric strings to integers
print(int("123") + int("123"))  # Output: 246

# Convert integers to strings
print(str(123) + str(123))      # Output: '123123'

# === ASCII value of characters ===

print(ord("a"))    # Output: 97
print(ord("b"))    # Output: 98

# (Optional) Convert ASCII value back to character
print(chr(97))     # Output: 'a'

# === Join a list of strings ===

strings = ["ab", "cd", "ef"]

# Combine into one string with "" as separator
print("".join(strings))         # Output: 'abcdef'

# Join with custom separator
print("-".join(strings))        # Output: 'ab-cd-ef'

```



## Queues

```python
# === Queues in Python using collections.deque ===
from collections import deque

# Initialize an empty deque
queue = deque()

# Append to the right (acts like enqueue)
queue.append(1)
queue.append(2)
print(queue)           # Output: deque([1, 2])

# Pop from the left (acts like dequeue)
queue.popleft()
print(queue)           # Output: deque([2])

# Append to the left
queue.appendleft(1)
print(queue)           # Output: deque([1, 2])

# Pop from the right (standard pop)
queue.pop()
print(queue)           # Output: deque([1])

```



## HashSets

```python
# === HashSet in Python (built-in set type) ===

# Initialize an empty set
mySet = set()

# Add elements (duplicates are ignored)
mySet.add(1)
mySet.add(2)
print(mySet)           # Output: {1, 2}
print(len(mySet))      # Output: 2

# Membership test (very fast — O(1) average case)
print(1 in mySet)      # True
print(2 in mySet)      # True
print(3 in mySet)      # False

# Remove an element
mySet.remove(2)
print(2 in mySet)      # False

# === Convert a list to a set ===
print(set([1, 2, 3]))  # Output: {1, 2, 3}

# === Set comprehension ===
mySet = {i for i in range(5)}
print(mySet)           # Output: {0, 1, 2, 3, 4}

set 不保证顺序。
```



## HashMaps

```python
# === HashMap in Python (aka dict) ===

# Initialize an empty dict
myMap = {}

# Add key-value pairs
myMap["alice"] = 88
myMap["bob"] = 77
print(myMap)            # {'alice': 88, 'bob': 77}
print(len(myMap))       # 2

# Update a value
myMap["alice"] = 80
print(myMap["alice"])   # 80

value = d.get('key', default=None) # 安全访问，返回默认值

# Check key existence
print("alice" in myMap) # True

# Remove a key
myMap.pop("alice")
print("alice" in myMap) # False

# === Initialize with values directly ===
myMap = { "alice": 90, "bob": 70 }
print(myMap)            # {'alice': 90, 'bob': 70}

# === Dict comprehension ===
myMap = { i: 2 * i for i in range(3) }
print(myMap)            # {0: 0, 1: 2, 2: 4}

# === Iterating through a dictionary ===
myMap = { "alice": 90, "bob": 70 }

# Iterate through keys
for key in myMap:
    print(key, myMap[key])

# Iterate through values only
for val in myMap.values():
    print(val)

# Iterate through key-value pairs
for key, val in myMap.items():
    print(key, val)

```



## Tuples

```python
# Tuples are like arrays but immutable
tup = (1, 2, 3)
print(tup)
print(tup[0])
print(tup[-1])

# Can't modify
# tup[0] = 0

# Can be used as key for hash map/set
myMap = { (1,2): 3 }
print(myMap[(1,2)])

mySet = set()
mySet.add((1, 2))
print((1, 2) in mySet)

# Lists can't be keys
# myMap[[3, 4]] = 5
```



## Heaps

```python
import heapq

# === Min Heap (default in Python) ===

# Heaps are implemented as lists
minHeap = []

# Push elements into heap
heapq.heappush(minHeap, 3)
heapq.heappush(minHeap, 2)
heapq.heappush(minHeap, 4)

# The smallest element is always at index 0
print(minHeap[0])         # Output: 2

# Pop all elements in sorted order (ascending)
while minHeap:
    print(heapq.heappop(minHeap))
# Output: 2 3 4

# === Max Heap (Python has no built-in, but can be emulated) ===

# Use negative values to reverse the order
maxHeap = []
heapq.heappush(maxHeap, -3)
heapq.heappush(maxHeap, -2)
heapq.heappush(maxHeap, -4)

# Convert back to positive to read the max
print(-maxHeap[0])        # Output: 4

# Pop all elements in sorted order (descending)
while maxHeap:
    print(-heapq.heappop(maxHeap))
# Output: 4 3 2

# === Build a heap from an existing list ===

arr = [2, 1, 8, 4, 5]

# Convert list to a valid min heap in-place
heapq.heapify(arr)

# Pop all elements in sorted order
while arr:
    print(heapq.heappop(arr))
# Output: 1 2 4 5 8

```



## Functions

```python
# === Basic function with parameters ===

def myFunc(n, m):
    return n * m

print(myFunc(3, 4))         # Output: 12

# === Nested functions and closures ===

def outer(a, b):
    c = "c"

    # Inner function can access outer scope variables
    def inner():
        return a + b + c

    return inner()

print(outer("a", "b"))      # Output: "abc"

# === Variable scope: nested function and modification ===

def double(arr, val):
    def helper():
        # ✅ Modify the list in-place (affects outer scope)
        for i, n in enumerate(arr):
            arr[i] *= 2

        # ❌ This won't modify val in the outer function
        # val *= 2

        # ✅ Use nonlocal to modify outer variable (Python 3+)
        nonlocal val
        val *= 2

    helper()
    print(arr, val)

# Call example
nums = [1, 2]
val = 3
double(nums, val)           # Output: [2, 4] 6

```



## Classes

```python
class MyClass:
    # Constructor
    def __init__(self, nums):
        # Create member variables
        self.nums = nums
        self.size = len(nums)
    
    # self key word required as param
    def getLength(self):
        return self.size

    def getDoubleLength(self):
        return 2 * self.getLength()

myObj = MyClass([1, 2, 3])
print(myObj.getLength())
print(myObj.getDoubleLength())
```
