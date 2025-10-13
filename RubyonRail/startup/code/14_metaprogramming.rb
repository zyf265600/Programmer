# 学习卡片：元编程
# - 要点：define_method 生成 DSL；method_missing 做兜底并实现 respond_to_missing?
# - 易错：滥用会难调试；保证 API 可发现性（respond_to? 一致）。
# - 练习：为 Config 实现 respond_to_missing?，使 respond_to?(:host) 返回 true。
# 元编程：动态定义方法与 method_missing

class Config
  def self.attr_config(*names)
    names.each do |name|
      define_method(name) do |value = nil|
        if value.nil?
          instance_variable_get("@#{name}")
        else
          instance_variable_set("@#{name}", value)
        end
      end
    end
  end

  attr_config :host, :port

  def method_missing(name, *args, &block)
    # 兜底：未知方法统一报错提示
    raise NoMethodError, "Unknown config: #{name}"
  end
end

c = Config.new
c.host('localhost')
c.port(3000)
puts "host=#{c.host}, port=#{c.port}"


