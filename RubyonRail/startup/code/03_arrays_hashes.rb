# 学习卡片：数组与 Hash
# - 要点：map/select/reduce 常用；符号键语法糖；p 用于调试打印原样。
# - 易错：破坏性方法（如 map!）会修改原数组；注意副作用。
# - 练习：给用户增加 tags 数组，去重并排序输出。
numbers = [1, 2, 3, 4]  # 数组（Array）
numbers << 5            # 追加元素

# map 会返回新数组；块参数用 |n|，返回表达式的值收集到新数组
p numbers.map { |n| n * 2 }

# select 选择满足条件的元素，这里 &:even? 是符号转方法的简写
p numbers.select(&:even?)

# Hash（键值对），通常以符号作键
user = { name: "Alice", age: 20 }
user[:city] = "Shanghai"  # 新增键
p user
puts "姓名: #{user[:name]}, 年龄: #{user[:age]}"


