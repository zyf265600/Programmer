# 学习卡片：方法与参数
# - 要点：默认参数、可变参数 *args、关键字参数 k:, **kw；返回值是最后表达式。
# - 易错：关键字必须带名；数组/哈希可用展开 *arr, **hash；p 查看结构。
# - 练习：实现 avg(*nums, precision: 2) 返回保留小数的平均值。
def greet(name = "world")
  # 默认参数：不传参时 name 为 "world"
  "Hello, #{name}!"
end

def add(a, b = 0)
  # 带默认值的第二个参数
  a + b
end

def sum(*numbers)
  # 可变参数：*numbers 会把任意数量的实参收集成数组
  numbers.reduce(0) { |acc, n| acc + n }
end

def paint(color:, opacity: 1.0)
  # 关键字参数：调用时必须写成 color: xxx
  { color: color, opacity: opacity }
end

puts greet
puts greet("Ruby")
puts add(1, 2)
puts sum(1, 2, 3, 4)
p paint(color: "red", opacity: 0.5)


