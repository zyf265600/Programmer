# 学习卡片：范围/符号/时间
# - 要点：1..5 包含 5；1...5 不包含 5；符号常作枚举；Time/Date 常用。
# - 练习：实现 in_business_hours?(time) 判定工作日 9:00–18:00。
# 范围、符号、时间与日期

# 范围（Range）
range_inclusive = 1..5   # 包含 5
range_exclusive = 1...5  # 不包含 5
p range_inclusive.to_a
p range_exclusive.to_a

# 符号（Symbol）适合做常量/枚举
status = :pending
case status
when :pending then puts "待处理"
when :done    then puts "完成"
else puts "未知"
end

# 时间/日期
now = Time.now
puts now.strftime("%Y-%m-%d %H:%M:%S")
require 'date'
date = Date.parse('2025-09-14')
puts (date >> 1).to_s  # 推进一个月


