# Ruby 学习深度指南（配合 00~18 脚本）

> 建议：左侧打开对应 `.rb` 文件，边看本指南边运行修改验证。

## 00 你好 Ruby（ARGV、插值、IO）
- 要点：`ARGV` 是命令行参数数组；`puts` 自动换行；`"#{...}"` 字符串插值。
- 易错：在单引号字符串中 `'#{name}'` 不会插值；需使用双引号。
- 练习：当未传参时提示“用法”，传参时问候多个名字（遍历 `ARGV`）。

## 01 变量与基本类型（Integer/Float/Boolean/Symbol/String）
- 要点：Ruby 一切皆对象；`class` 查看运行时类型；`Symbol` 适合做键/枚举且可复用。
- 易错：`true/false/nil` 都是对象；条件判断中只有 `false` 和 `nil` 视为假。
- 练习：将温度 `c` 摄氏转华氏并四舍五入输出；比较浮点近似相等。

## 02 数字与字符串（算术、插值、heredoc）
- 要点：整数/整数做整数除法；`to_f` 触发浮点；`<<~` heredoc 支持缩进；`strip` 去空白。
- 易错：`+` 拼接会创建新字符串，频繁拼接可用 `StringIO` 或 `<<`。
- 练习：实现一个 `title_case(str)`，只让每个单词首字母大写。

## 03 数组与 Hash（map/select、符号键）
- 要点：`map/select/reduce` 是 Enumerable 三件套；符号键 `{ name: 'A' }` 实际是 `{:name => 'A'}` 语法糖。
- 易错：`p` 打印原始对象（调试友好），`puts` 打印 `to_s`；注意破坏性方法 `map!`。
- 练习：给用户 Hash 增加 `:tags` 数组并去重、按字母序输出。

## 04 流程控制（if/elsif/case、times/while/each）
- 要点：`if` 是表达式有返回值；`case` 支持逗号匹配；块变量作用域只在块内。
- 易错：`=` 与 `==`；`while` 循环注意退出条件；`break/next/redo` 的区别。
- 练习：实现 FizzBuzz（1..100）。

## 05 方法与参数（默认、可变、关键字）
- 要点：`def m(a=1, *xs, k:, **kw)` 的参数排列；返回值是最后一个表达式；`p` 查看结构。
- 易错：关键字参数必须带名；可变参数与数组展开 `m(*arr)`。
- 练习：实现 `avg(*nums, precision: 2)` 返回保留指定位小数平均值。

## 06 类与模块（实例/类变量、类方法、to_s）
- 要点：`attr_accessor` 生成 getter/setter；模块常作命名空间或 mixin；`@@var` 类变量共享，`@var` 实例变量独立。
- 易错：过度使用类变量会导致继承层级共享问题；更推荐类实例变量 `@count` + 类方法访问。
- 练习：为 `Person` 添加 `birthday!` 使年龄自增并返回问候；将计数实现改为类实例变量。

## 07 块与 Enumerable（yield、符号转方法）
- 要点：`yield` 与显式块 `&block` 的取舍；`map(&:upcase)` 等价 `{|s| s.upcase}`。
- 易错：块内 `return` 会从定义方法处返回；需要时改用 `next` 或显式 `block.call`。
- 练习：实现 `with_resource(path) { |f| ... }` 自动打开/关闭文件。

## 08 文件与正则（read/write、=~、gsub）
- 要点：`File.write/read` 简洁；正则分组 `()` 与捕获 `match[1]`；命名分组 `(?<name>...)`。
- 易错：Windows 路径分隔符；跨平台用 `File.join`；正则默认贪婪匹配。
- 练习：屏蔽邮箱中间 4 位：`john.doe@example.com` -> `j***.***@example.com`。

## 09 异常处理（raise/rescue/ensure）
- 要点：`rescue SpecificError => e` 精确捕获；`ensure` 做清理；自定义异常继承 `StandardError`。
- 易错：不要吞掉所有异常 `rescue => e` 而不处理；至少记录日志或重新抛出。
- 练习：包装 IO 操作：失败时重试 3 次（`retry`）。

## 10 范围/符号/时间
- 要点：`..` 与 `...` 的包含差异；`case` + 符号做枚举；`Time/Date` 基本操作。
- 练习：实现 `in_business_hours?(time)` 判定 9:00–18:00 工作日。

## 11 文件、YAML、JSON
- 要点：JSON 适合数据交换；YAML 适合人读配置；`pretty_generate` 便于调试。
- 易错：YAML 反序列化使用 `safe_load`（生产场景更安全）。
- 练习：把待办事项存 YAML，提供加载/保存两个函数。

## 12 Mixin 与 Refinement
- 要点：`include` 将模块方法作为实例方法；`extend` 作为类方法；`using` 仅当前作用域生效。
- 易错：Refinement 只在定义后到文件末尾有效；跨文件需再次 `using`。
- 练习：为 `String` 提供 `snake_case` 的 refinement。

## 13 Enumerator 与 Fiber
- 要点：`Enumerator.new` 自定义序列；`lazy` 惰性链式处理；`Fiber` 协作式切换。
- 易错：无限序列记得 `take(n)`；`Fiber` 不等于线程，不做并行。
- 练习：实现一个无限质数枚举器，并 `take(20)` 打印。

## 14 元编程（define_method、method_missing）
- 要点：用 `define_method` 动态生成 DSL；`method_missing` 作为兜底并搭配 `respond_to_missing?`。
- 易错：滥用 `method_missing` 难以调试；记得实现 `respond_to_missing?` 保持一致性。
- 练习：实现 `Config` 支持 `respond_to? :host` 返回 true。

## 15 继承与多态、Mixin
- 要点：优先组合（mixin）而非深继承；以接口（鸭子类型）编程。
- 易错：判断类型不要用 `is_a?` 绑定具体类；多用 `respond_to?`。
- 练习：新增 `Duck`，无需继承 `Animal`，只要实现 `speak` 也能工作。

## 16 命令行解析（OptionParser）
- 要点：声明短/长选项、类型转换、`parse!` 后剩余即位置参数。
- 易错：用户输入非法时给出帮助和非零退出码；用 `opts.banner` 写清用法。
- 练习：增加 `--format json|text` 输出格式切换。

## 17 网络请求（Net::HTTP）
- 要点：`Net::HTTP.get_response` 简易；需要自定义 header/超时可用 `Net::HTTP.start`。
- 易错：处理非 2xx 响应；网络异常需要 `rescue` 并重试或降级。
- 练习：封装 `fetch_json(url, headers: {})`，返回 `Hash` 或抛异常。

## 18 测试（Minitest）
- 要点：文件命名 `*_test.rb` 可自动发现；`assert_equal`、`assert_raises` 常用断言。
- 易错：测试互相依赖导致顺序问题；保持独立可重复。
- 练习：为 14 的 `Config` 写测试，覆盖正常与异常路径。

---
### 进一步实践建议
1. 迷你 CLI 待办项目：命令解析 + YAML 持久化 + 单元测试。
2. 将 11 的配置读取应用到 Rails `config/`，在开发/生产使用不同配置。
3. 尝试用 RuboCop 进行代码规范检查，学习常见风格规则。
