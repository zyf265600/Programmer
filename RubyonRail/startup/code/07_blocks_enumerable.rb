# 学习卡片：块与 Enumerable
# - 要点：yield 或 &block 调用；map/select/reduce 常用；符号转方法 &:upcase。
# - 易错：块内 return 会从定义方法处返回；必要时使用 block.call。
# - 练习：实现 with_resource(path){|f| ...} 自动打开/关闭文件。
def with_logging(label)
  # 方法接收一个块：yield 会执行传入的块
  puts "[#{label}] start"
  result = yield(3) # 可向块传参
  puts "[#{label}] end"
  result
end

value = with_logging("calc") do |x|
  x * 10
end
puts "结果: #{value}"

arr = %w[ruby rails react] # %w[...] 生成字符串数组
p arr.map(&:upcase)        # &:方法名 是 { |s| s.方法名 } 的简写
p arr.select { |s| s.include?("r") }
sum = [1, 2, 3, 4].reduce(0) { |acc, n| acc + n }
puts "sum=#{sum}"


