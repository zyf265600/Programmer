# 学习卡片：文件/YAML/JSON
# - 要点：JSON 适合交换；YAML 适合人读配置；pretty_generate 便于调试。
# - 易错：YAML 反序列化生产环境用 safe_load；注意符号/字符串键差异。
# - 练习：实现 todo 列表的保存/加载。
# 文件读写、YAML 与 JSON 序列化
require 'json'
require 'yaml'

data = {
  name: 'Alice',
  age: 21,
  tags: %w[ruby rails]
}

# JSON
json_path = File.join(__dir__, 'data.json')
File.write(json_path, JSON.pretty_generate(data))
puts "写入 JSON: #{json_path}"
loaded = JSON.parse(File.read(json_path))
p loaded

# YAML（更适合配置）
yaml_path = File.join(__dir__, 'data.yml')
File.write(yaml_path, data.to_yaml)
puts "写入 YAML: #{yaml_path}"
p YAML.load_file(yaml_path)


