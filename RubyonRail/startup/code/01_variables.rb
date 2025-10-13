# 学习卡片：变量与基本类型
# - 要点：一切皆对象；Integer/Float/Boolean/Symbol/String；.class 查看类型。
# - 易错：只有 false 和 nil 视为假；符号适合做键/枚举。
# - 练习：实现摄氏转华氏、浮点近似相等比较。

age = 20              # 整数（Integer）
pi = 3.14159         # 浮点数（Float）
is_adult = age >= 18 # 布尔值（true/false）
language = :ruby     # 符号（Symbol）：不可变、可复用（同名符号只存一份），适合作为 Hash 键、枚举常量、事件名等。
user_name = "Alice"  # 字符串（String）

# .class 打印对象的类型
puts age.class       #=> Integer
puts pi.class        #=> Float

# 比较运算返回布尔值
puts is_adult        #=> true/false

# 符号与字符串差异：
# - 字符串可变、每次字面量可能分配新对象；符号不可变、同名符号是同一对象（节省内存、比较更快）。
# - 常用于 Hash 键：{ lang: :ruby }；或作为状态值：:pending, :done。
puts language        # puts 会把对象转成字符串（调用 to_s）后打印并自动换行

# puts 与 p 的区别：
# - puts 输出 to_s 后的结果，适合人读；
# - p 输出对象的 inspect（更偏调试），会展示引号、类型细节。

# 字符串方法示例：upcase 转为大写
puts user_name.upcase


