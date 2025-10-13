# 学习卡片：数字与字符串
# - 要点：整数/整数为整数除法；to_f 触发浮点；heredoc <<~ 支持缩进。
# - 易错：大量拼接建议用插值或 <<；strip 去首尾空白。
# - 练习：实现 title_case，把每个单词首字母大写。
a = 7
b = 3

# 基本算术与字符串插值
puts "a + b = #{a + b}"

# Ruby 中整数/整数会做整数除法
puts "a / b = #{a / b} (整数除法)"

# 转为浮点即可得到小数结果
puts "a / b (浮点) = #{a.to_f / b}"

str = "Ruby"
puts "长度: #{str.length}"
puts "拼接: " + str + " rocks"  # 使用 + 号拼接
puts "插值: #{str} rocks"        # 推荐：使用字符串插值

# 多行字符串（heredoc）
multi = <<~TEXT
多行字符串
第2行
TEXT

# strip 去掉首尾空白
puts multi.strip


