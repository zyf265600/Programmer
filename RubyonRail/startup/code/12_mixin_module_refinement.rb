# 学习卡片：Mixin 与 Refinement
# - 要点：include 注入实例方法；extend 注入类方法；using 仅在当前作用域生效。
# - 易错：Refinement 不会影响全局；跨文件需再次 using。
# - 练习：为 String 提供 snake_case 的 refinement。
# Mixin（模块混入）与 Refinement（局部猴子补丁）

module Flyable
  def fly
    "I can fly!"
  end
end

class Bird
  include Flyable  # 将模块方法作为实例方法引入
end

puts Bird.new.fly

# Refinement：只在 using 的文件/作用域生效，不污染全局
module StringTitleize
  refine String do
    def titleize
      split.map { |w| w[0].upcase + w[1..] }.join(' ')
    end
  end
end

using StringTitleize
puts "ruby on rails".titleize


