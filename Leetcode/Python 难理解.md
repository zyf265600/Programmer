# Python 难理解

````py
# 整数除法的结果都是向下取整
5 // 3  # => 1

# i % j 结果的正负符号会和 j 相同，而不是和 i 相同
-7 % 3  # => 2

# True 和 False 实质上就是数字 1 和0
True + True  # => 2

# and 和 or 返回的是原来的值，不是 True 或 False。
a and b：如果 a 是假，返回 a；否则返回 b
a or b：如果 a 是真，返回 a；否则返回 b

# None，0，空字符串，空列表，空字典，空元组都算是 False
# 所有其他值都是 True
bool(0)  # => False
bool("")  # => False
bool([])  # => False
bool({})  # => False
bool(())  # => False

# 大小比较可以连起来！
1 < 2 < 3  # => True

# (is 对比 ==) is 判断两个变量是否引用同一个对象,
# 而 == 判断两个对象是否含有相同的值

# 创建字符串可以使用单引号（'）或者双引号（"）

# 字符串可以被当作字符列表
"Hello world!"[0]  # => 'H'

# 你可以使用 f-strings 格式化字符串（python3.6+）
name = "Reiko"
f"She said her name is {name}."  # => "She said her name is Reiko"
# 你可以在大括号内几乎加入任何 python 表达式，表达式的结果会以字符串的形式返回
f"{name} is {len(name)} characters long."  # => "Reiko is 5 characters long."

# 用 .format 来格式化字符串
"{} can be {}".format("strings", "interpolated")
# 可以重复参数以节省时间
"{0} be nimble, {0} be quick, {0} jump over the {1}".format("Jack", "candle stick")
# => "Jack be nimble, Jack be quick, Jack jump over the candle stick"
# 如果不想数参数，可以用关键字
"{name} wants to eat {food}".format(name="Bob", food="lasagna")
# => "Bob wants to eat lasagna"


# "if" 可以用作表达式，它的作用等同于 C 语言的三元运算符 "?:"
"yay!" if 0 > 1 else "nay!"  # => "nay!"







````

