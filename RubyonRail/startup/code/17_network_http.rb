# 学习卡片：网络请求（标准库 Net::HTTP）
# - 要点：简单请求用 get_response；需要 header/超时可用 Net::HTTP.start。
# - 易错：处理非 2xx；网络异常需 rescue 并重试/降级。
# - 练习：封装 fetch_json(url, headers: {}) 返回 Hash 或抛异常。
# 简单网络请求：Net::HTTP（标准库）
require 'net/http'
require 'uri'
require 'json'

uri = URI('https://api.github.com/repos/ruby/ruby')
res = Net::HTTP.get_response(uri)
puts "状态: #{res.code}"

if res.is_a?(Net::HTTPSuccess)
  data = JSON.parse(res.body)
  puts "repo: #{data['full_name']} | stars: #{data['stargazers_count']}"
else
  warn "请求失败: #{res.code}"
end


