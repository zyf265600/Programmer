# 学习卡片：方法、块、yield、Proc、lambda
# - 差异：Proc 对参数宽松、return 会从外层方法返回；lambda 参数严格、return 只退出自身。

def demo_yield
  puts "before"
  result = yield(2, 3) if block_given?
  puts "after"
  result
end

puts demo_yield { |a, b| a + b }

# Proc 与 lambda
adder_proc = Proc.new { |a, b| a + (b || 0) }   # 参数宽松，b 不传为 nil 也能运行
adder_lambda = ->(a, b) { a + b }               # 参数严格，必须两个

puts adder_proc.call(1)
puts adder_proc.call(1, 2)
puts adder_lambda.call(1, 2)

def proc_vs_lambda_return
  p1 = Proc.new { return "proc: exited outer method" }
  p1.call
  "unreachable"
end

def lambda_return
  l = -> { return "lambda: only exit lambda" }
  msg = l.call
  "outer still runs with: #{msg}"
end

puts proc_vs_lambda_return
puts lambda_return


