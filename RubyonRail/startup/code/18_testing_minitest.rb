# 学习卡片：Minitest 单元测试
# - 要点：require 'minitest/autorun' 后直接运行本文件即可执行测试。
# - 常用断言：assert/ refute/ assert_equal/ assert_nil/ assert_raises。
# - 建议：测试独立可重复；使用 setup/teardown 管理共享资源。

require 'minitest/autorun'

# 被测代码（通常在独立文件中 require 进来，这里为演示内联写）
def add(a, b)
  a + b
end

class Calculator
  def divide(a, b)
    raise ArgumentError, 'b 不能为 0' if b == 0
    a.to_f / b
  end
end

class TestAdd < Minitest::Test
  def test_add_positive
    assert_equal 3, add(1, 2)
  end

  def test_add_negative
    assert_equal(-1, add(1, -2))
  end
end

class TestCalculator < Minitest::Test
  def setup
    @calc = Calculator.new
  end

  def test_divide_normal
    assert_in_delta 2.5, @calc.divide(5, 2), 0.0001
  end

  def test_divide_by_zero_raises
    err = assert_raises(ArgumentError) { @calc.divide(1, 0) }
    assert_match /不能为 0/, err.message
  end
end


