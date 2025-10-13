# 学习卡片：基本语法（变量/常量/类型/控制结构 完整版）
# - 覆盖：变量与常量、数字/字符串/数组/哈希/符号、if/unless/case/while/until/for/each、范围。

# 变量与常量
username = "alice"     # 小写开头是局部变量
PI = 3.14159           # 全大写是常量（可重新赋值但会告警）

# 数据类型
int_num = 42
float_num = 3.14
bool_val = true
sym = :ruby
arr = [1, 2, 3]
hash = { name: "Alice", age: 20 }

puts [int_num.class, float_num.class, bool_val.class, sym.class, arr.class, hash.class].join(", ")

# 字符串常用：插值、转义、多行
puts "Hello, #{username}\nPI=#{PI}"
multi = <<~MD
第一行
第二行
MD
puts multi.strip

# 控制结构 if / unless（条件为假时执行）
age = 17
if age >= 18
  puts "adult"
else
  puts "minor"
end

puts "未成年" unless age >= 18

# case（等值匹配；也可用范围/正则）
score = 83
case score
when 90..100 then puts "A"
when 80..89  then puts "B"
when 70..79  then puts "C"
else             puts "D"
end

# while / until / for / each
i = 0
while i < 3
  puts "while #{i}"
  i += 1
end

j = 3
until j == 0
  puts "until #{j}"
  j -= 1
end

for k in 1..3
  puts "for #{k}"
end

[10, 20, 30].each { |n| puts "each #{n}" }


