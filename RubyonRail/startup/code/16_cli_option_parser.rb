# 学习卡片：命令行解析 OptionParser
# - 要点：定义短/长选项与类型；parse! 后剩余参数即位置参数。
# - 易错：非法输入要给出帮助和非零退出码；banner 写清用法。
# - 练习：新增 --format json|text 切换输出格式。
# 命令行解析：OptionParser
require 'optparse'

options = { verbose: false, times: 1 }

OptionParser.new do |opts|
  opts.banner = "用法: ruby 16_cli_option_parser.rb [选项] [NAME]"
  opts.on('-v', '--verbose', '显示详细信息') { options[:verbose] = true }
  opts.on('-t N', '--times N', Integer, '重复次数') { |n| options[:times] = n }
end.parse!

name = ARGV.first || 'Ruby'
options[:times].times do |i|
  msg = "Hello, #{name}! (#{i + 1})"
  puts(options[:verbose] ? "[VERBOSE] #{msg}" : msg)
end


