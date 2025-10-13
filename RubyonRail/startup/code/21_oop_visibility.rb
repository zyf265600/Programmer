# 学习卡片：OOP 与方法可见性（public/protected/private）

class Account
  attr_reader :owner

  def initialize(owner, balance)
    @owner = owner
    @balance = balance
  end

  def transfer_to(other, amount)
    withdraw(amount)
    other.send(:deposit, amount)  # private 方法只能在当前接收者上调用；此处用 send 演示
  end

  def balance_info
    "#{owner}: #{masked_balance}"
  end

  protected
  # protected 方法可在同类或子类实例之间相互调用（接收者可以是别的实例）
  def masked_balance
    "****#{@balance % 100}"
  end

  private
  # private 方法只能隐式调用（接收者必须省略，默认为 self）
  def withdraw(amount)
    raise "余额不足" if amount > @balance
    @balance -= amount
  end

  def deposit(amount)
    @balance += amount
  end
end

a = Account.new("Alice", 300)
b = Account.new("Bob", 100)
a.transfer_to(b, 50)
puts a.balance_info
puts b.balance_info


