# 学习卡片：类与模块
# - 要点：attr_accessor 生成 getter/setter；类方法/实例变量；模块作命名空间或工具集。
# - 易错：类变量 @@var 会在继承层共享；常用类实例变量 @count + 类方法访问。
# - 练习：实现 birthday! 自增年龄；把计数改为类实例变量。
module MathUtil
  # 模块常作为命名空间/工具方法容器
  def self.square(x)
    x * x
  end
end

class Person
  # 生成 getter/setter 方法
  attr_accessor :name, :age

  # 类变量：所有实例共享
  @@count = 0

  # 类方法（在类上调用）
  def self.count
    @@count
  end

  # 构造方法
  def initialize(name, age)
    @name = name  # 实例变量：每个对象独有
    @age = age
    @@count += 1
  end

  def greet
    "我是#{name}，今年#{age}岁"
  end

  # to_s 定义对象的字符串表示
  def to_s
    "Person(name=#{name}, age=#{age})"
  end
end

alice = Person.new("Alice", 20)
bob = Person.new("Bob", 22)
puts alice.greet
puts bob
puts "人数: #{Person.count}"
puts "4 的平方: #{MathUtil.square(4)}"


