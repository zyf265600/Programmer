# Ruby 学习笔记

## 第一部分 rbenv 的介绍

### 1. 概述

**rbenv** 是一种 Ruby 版本管理工具。
 它允许在同一台机器上安装、切换和管理多个 Ruby 版本，而不会影响系统自带的 Ruby。

在实际开发中，不同项目可能依赖于不同的 Ruby 版本（例如某些 Rails 项目需要 Ruby 3.x，而另一些可能使用 2.7.x）。rbenv 的核心作用在于实现 **版本切换与隔离**，确保每个项目能够使用其所需的 Ruby 环境。

------

### 2. 核心机制

1. **Shims（垫片）**
   - 当运行 `ruby`、`gem`、`rails` 等命令时，实际执行的是 `~/.rbenv/shims/` 目录下的脚本。
   - 这些脚本会检测当前 rbenv 的配置，并将调用转发到对应版本的 Ruby 可执行文件。
   - 借助这一机制，不同项目能够共存且使用不同的 Ruby 版本。
2. **版本选择优先级**
    rbenv 按照以下顺序确定 Ruby 的版本：
   1. `RBENV_VERSION` 环境变量（临时设置）
   2. 项目目录下的 `.ruby-version` 文件（通过 `rbenv local` 设置）
   3. 全局默认版本（通过 `rbenv global` 设置）
   4. 系统自带 Ruby（例如 macOS 的 `/usr/bin/ruby`）

------

### 3. 常用命令

- **安装 Ruby**

  ```bash
  rbenv install 3.3.1
  ```

  安装 Ruby 3.3.1（依赖 `ruby-build` 插件）。

- **查看已安装的版本**

  ```bash
  rbenv versions
  ```

- **查看当前使用的版本**

  ```bash
  rbenv version
  ```

- **设置全局默认版本**

  ```bash
  rbenv global 3.3.1
  ```

  设置全局默认 Ruby 版本。

- **设置项目本地版本**

  ```bash
  rbenv local 3.2.2
  ```

  在当前目录生成 `.ruby-version` 文件；进入该目录时会自动切换至 3.2.2。

- **临时切换版本（仅在当前终端会话中生效）**

  ```bash
  rbenv shell 3.1.0
  ```

- **重新生成 shims**

  ```bash
  rbenv rehash
  ```

  更新 shim 文件，确保新安装的命令可被识别。

------

### 4. 相关目录

- `~/.rbenv/versions/`
   存放所有已安装的 Ruby 版本。
- `~/.rbenv/shims/`
   存放 shim 文件，用于拦截并转发 `ruby`、`gem`、`rails` 等命令。
- `~/.rbenv/version`
   记录全局默认 Ruby 版本号（由 `rbenv global` 写入）。

------

### 5. 总结

rbenv 的核心功能是 **Ruby 版本的切换与隔离**。
 常见操作可归纳为：

- 安装新版本：`rbenv install`
- 设置全局默认版本：`rbenv global`
- 设置项目本地版本：`rbenv local`
- 临时切换版本：`rbenv shell`

好的，我为你写一个 **Ruby 快速入门笔记（第二部分：Ruby 基础语法）**，内容正式、清晰、采用 Markdown 格式，方便直接保存为笔记。



# 第二部分 Ruby 基础语法

## 1. 基本语法

### 1.1 变量与常量

- **变量**：无需声明类型，直接赋值即可。
  - 局部变量：小写字母或下划线开头（如 `name`、`_count`）
  - 全局变量：以 `$` 开头（如 `$global_var`）
  - 实例变量：以 `@` 开头（如 `@age`）
  - 类变量：以 `@@` 开头（如 `@@counter`）
- **常量**：以大写字母开头（如 `PI = 3.14`）。重新赋值会产生警告，但不会阻止。

```ruby
name = "Alice"
PI = 3.14159
puts name
puts PI
```

------

### 1.2 数据类型

- **数字**

  - 整数（`42`）、浮点数（`3.14`）

- **字符串**

  - 单引号 `'hello'` 或双引号 `"world"`
  - 插值：`"Hello #{name}"`

- **数组**

  ```ruby
  arr = [1, 2, 3]
  arr << 4
  puts arr.inspect
  ```

- **哈希（Hash）**

  ```ruby
  h = { name: "Alice", age: 30 }
  puts h[:name]
  ```

- **符号（Symbol）**

  - 一种轻量、不可变的标识符，常用作哈希键。

  ```ruby
  status = :active
  ```

------

### 1.3 控制结构

```ruby
# if / else
x = 10
if x > 5
  puts "x 大于 5"
else
  puts "x 小于等于 5"
end

# unless（除非）
puts "x 小于等于 5" unless x > 5

# case
grade = "B"
case grade
when "A"
  puts "优秀"
when "B"
  puts "良好"
else
  puts "需努力"
end

# while
i = 0
while i < 3
  puts i
  i += 1
end

# for
for num in [1, 2, 3]
  puts num
end

# each
[1, 2, 3].each do |n|
  puts n
end
```

------

## 2. 方法与块

### 2.1 方法定义与调用

```ruby
def greet(name)
  "Hello, #{name}"
end

puts greet("Alice")
```

### 2.2 参数与默认值

```ruby
def greet(name = "Guest")
  "Hello, #{name}"
end

puts greet       # => Hello, Guest
puts greet("Bob") # => Hello, Bob
```

### 2.3 块（block）、yield、Proc、lambda

```ruby
# 块与 yield
def repeat(times)
  i = 0
  while i < times
    yield i
    i += 1
  end
end

repeat(3) { |n| puts "第 #{n} 次" }

# Proc 对象
p = Proc.new { |x| puts x * 2 }
p.call(5)

# lambda
l = ->(x) { x * 2 }
puts l.call(10)
```

------

## 3. 面向对象编程

### 3.1 类与对象

```ruby
class Person
  def initialize(name, age)
    @name = name
    @age = age
  end

  def introduce
    "我是 #{@name}, 今年 #{@age} 岁"
  end
end

p = Person.new("Alice", 30)
puts p.introduce
```

### 3.2 继承与模块

```ruby
class Student < Person
  def study
    "正在学习"
  end
end

module Greetable
  def greet
    "你好！"
  end
end

class Teacher < Person
  include Greetable
end
```

### 3.3 Mixins

- 使用 `include` 将模块引入类，提供共享功能。

### 3.4 方法可见性

```ruby
class Example
  def public_method
    "这是公共方法"
  end

  protected
  def protected_method
    "这是受保护的方法"
  end

  private
  def private_method
    "这是私有方法"
  end
end
```

------

## 4. 异常处理

### 4.1 基本用法

```ruby
begin
  result = 10 / 0
rescue ZeroDivisionError => e
  puts "捕获异常: #{e.message}"
ensure
  puts "无论如何都会执行"
end
```

### 4.2 自定义异常

```ruby
class MyError < StandardError; end

def risky_method
  raise MyError, "这是自定义错误"
end

begin
  risky_method
rescue MyError => e
  puts "捕获到自定义异常: #{e.message}"
end
```

------

## 总结

Ruby 的基础语法简洁易懂，强调可读性和灵活性：

- 变量与常量无需类型声明
- 数组与哈希使用方便
- 控制结构直观，支持 `unless` 等独特语法
- 方法和块提供了高阶抽象能力
- 面向对象机制灵活，支持 Mixins
- 异常处理机制完善，可自定义错误类型

------

要不要我接着帮你写 **第三部分：Ruby 工具链（irb、gem、bundler、rake）**，这样你的快速入门笔记可以衔接到实际开发环境？