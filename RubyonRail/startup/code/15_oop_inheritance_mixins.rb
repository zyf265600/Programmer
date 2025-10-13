# 学习卡片：继承/多态/Mixin
# - 要点：优先组合（mixin）而非深继承；鸭子类型（只要有方法就能用）。
# - 易错：少用 is_a? 做强耦合判断；改用 respond_to? 检查接口。
# - 练习：新增 Duck 类不继承 Animal 但实现 speak 也能工作。
# 面向对象：继承、多态、Mixin

module Speakable
  def speak
    "..."
  end
end

class Animal
  include Speakable
  def move
    "moving"
  end
end

class Dog < Animal
  def speak
    "woof"
  end
end

class Cat < Animal
  def speak
    "meow"
  end
end

def make_it_speak(animal)
  # 多态：不同子类实现相同接口
  puts animal.speak
end

make_it_speak(Dog.new)
make_it_speak(Cat.new)


