# Ruby 基础与进阶示例

参阅更详细的逐题讲解与练习：`GUIDE.md`

## 基础脚本（00~09）
```bash
ruby 00_hello.rb
ruby 01_variables.rb
ruby 02_numbers_strings.rb
ruby 03_arrays_hashes.rb
ruby 04_control_flow.rb 85
ruby 05_methods.rb
ruby 06_classes_modules.rb
ruby 07_blocks_enumerable.rb
ruby 08_io_regex.rb
ruby 09_error_handling.rb
```

## 高级脚本（10~18）
```bash
ruby 10_ranges_symbols_time.rb       # 范围/符号/时间日期
ruby 11_files_yaml_json.rb           # 文件 + YAML/JSON
ruby 12_mixin_module_refinement.rb   # 模块混入与 Refinement
ruby 13_enumerator_fiber.rb          # Enumerator/Fiber
ruby 14_metaprogramming.rb           # 元编程与 method_missing
ruby 15_oop_inheritance_mixins.rb    # 继承/多态/Mixin
ruby 16_cli_option_parser.rb --times 3 --verbose Tom
ruby 17_network_http.rb              # Net::HTTP 请求
ruby 18_testing_minitest.rb          # Minitest 单元测试
```

## 加强主题（19~22）
```bash
ruby 19_syntax_basics_plus.rb        # 基本语法全面版（变量/常量/控制结构）
ruby 20_methods_blocks_proc_lambda.rb# 方法/块/yield/Proc/lambda 对比
ruby 21_oop_visibility.rb            # OOP 与方法可见性 public/protected/private
ruby 22_exceptions_full.rb           # 异常处理：自定义、重试、ensure
```

建议从 00 开始依次运行，理解后再做小改动验证。若想结合 Rails，可把 11 的 YAML 当作配置文件、14 的元编程思想应用到模型宏上。
