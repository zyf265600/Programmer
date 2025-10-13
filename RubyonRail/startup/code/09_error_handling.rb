# 学习卡片：异常处理
# - 要点：raise 抛异常；rescue SpecificError => e 精确捕获；ensure 做清理。
# - 易错：不要吞异常不处理；记录日志或转换为业务错误返回。
# - 练习：对 IO 操作失败重试 3 次（使用 retry）。
class NegativeError < StandardError; end  # 自定义异常类型

def sqrt_safe(x)
  # 使用 raise 主动抛出异常
  raise NegativeError, "不能对负数开平方: #{x}" if x < 0
  Math.sqrt(x)
end

begin
  puts sqrt_safe(9)
  puts sqrt_safe(-1)
rescue NegativeError => e
  # 捕获特定异常类型
  warn "出错: #{e.message}"
ensure
  # ensure 区块无论是否异常都会执行
  puts "无论如何都会执行 ensure"
end


