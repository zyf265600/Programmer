# 学习卡片：异常处理（begin/rescue/ensure、重试、自定义异常）

class NetworkError < StandardError; end

def flaky_request
  # 模拟偶发失败
  raise NetworkError, "temporary failure" if rand < 0.5
  "OK"
end

retries = 0
begin
  puts flaky_request
rescue NetworkError => e
  retries += 1
  warn "失败: #{e.message} (第 #{retries} 次)"
  retry if retries < 3
  raise
ensure
  puts "清理资源（无论成功或失败都会执行）"
end


