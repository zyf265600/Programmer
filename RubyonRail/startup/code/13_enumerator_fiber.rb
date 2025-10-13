# 学习卡片：Enumerator 与 Fiber
# - 要点：Enumerator.new 自定义序列；lazy 惰性；Fiber 为协作式并发。
# - 易错：无限序列需 take(n)；Fiber 不等于线程不会并行。
# - 练习：实现质数枚举器并打印前 20 个。
# Enumerator 与 Fiber（协程）

# 自定义枚举器：惰性生成斐波那契数列前 n 个
def fib_enum(n)
  Enumerator.new do |y|
    a, b = 0, 1
    n.times do
      y << a
      a, b = b, a + b
    end
  end
end

p fib_enum(10).to_a

# Fiber 示例（轻量协作式并发）
f = Fiber.new do
  3.times do |i|
    Fiber.yield "tick #{i}"
  end
  "done"
end

puts f.resume
puts f.resume
puts f.resume
puts f.resume


