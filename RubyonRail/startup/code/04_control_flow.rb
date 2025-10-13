# 学习卡片：流程控制
# - 要点：if/case 都是表达式；times/while/each 三种循环；break/next 控制流。
# - 易错：= 与 ==；while 退出条件别忘自增；case 可逗号匹配多个值。
# - 练习：实现 1..100 的 FizzBuzz。
score = (ARGV.first || "85").to_i  # 从命令行读取分数

# if/elsif/else 分支
if score >= 90
  grade = "A"
elsif score >= 80
  grade = "B"
elsif score >= 70
  grade = "C"
else
  grade = "D"
end
puts "成绩等级: #{grade}"

# case 表达式（相当于 switch），支持逗号匹配多个值
case grade
when "A", "B"
  puts "干得好!"
when "C"
  puts "需要努力"
else
  puts "下次加油"
end

# times 循环（执行 3 次）
3.times { |i| puts "times 迭代 #{i}" }

# while 循环
i = 0
while i < 3
  puts "while #{i}"
  i += 1
end

# each 遍历数组
[10, 20, 30].each do |n|
  puts "each: #{n}"
end


