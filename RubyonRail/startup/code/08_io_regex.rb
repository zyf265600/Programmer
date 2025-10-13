# 学习卡片：文件 IO 与正则
# - 要点：File.write/read 简洁；=~/match/[] 提取；gsub 全局替换；命名分组。
# - 易错：路径拼接用 File.join；正则默认贪婪；注意换行符与编码。
# - 练习：屏蔽邮箱中间 4 位；提取所有手机号并去重。
file_path = File.join(__dir__, "tmp.txt")

# 写文件（若不存在会创建）
File.write(file_path, "Ruby is fun!\n123-456-7890")

# 读文件
content = File.read(file_path)
puts content.lines.first.strip

# 正则匹配：=~ 返回匹配位置或 nil；/i 表示忽略大小写
if content =~ /ruby/i
  puts "匹配到单词 Ruby (忽略大小写)"
end

# [] 可按正则提取第一个匹配子串
phone = content[/\d{3}-\d{3}-\d{4}/]
puts "手机号样式: #{phone}"

# gsub 全局替换：将所有数字替换为 *
masked = content.gsub(/\d/, "*")
puts masked


