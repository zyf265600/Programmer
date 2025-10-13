# Ruby 学习笔记大纲

## 第一部分 Ruby 环境管理

- **rbenv 的介绍**
  - 作用与原理
  - 核心机制（shims、版本优先级）
  - 常用命令
  - 相关目录说明
  - 总结
- **RVM 与 rbenv 的对比（可选）**
- **Bundler 与 Gem 简介**（包管理工具）

------

## 第二部分 Ruby 基础语法

1. **基本语法**
   - 变量与常量
   - 数据类型（数字、字符串、数组、哈希、符号）
   - 控制结构（if、unless、case、while、for、each）
2. **方法与块**
   - 方法定义与调用
   - 参数与默认值
   - 块（block）、`yield`、`Proc`、`lambda`
3. **面向对象编程**
   - 类与对象
   - 继承与模块（module）
   - Mixins
   - 方法可见性（public/protected/private）
4. **异常处理**
   - `begin`、`rescue`、`ensure`
   - 自定义异常

------

## 第三部分 Ruby 工具链

- **irb/pry**：交互式调试环境
- **RubyGems**：包管理系统
- **Bundler**：依赖管理工具
- **Rake**：任务执行工具

------

## 第四部分 数据与文件操作

- **文件 I/O**：读写文件、目录操作
- **JSON/YAML**：数据格式解析与生成
- **数据库连接**（ActiveRecord、Sequel）

------

## 第五部分 Ruby 进阶特性

- **元编程**
  - 动态定义方法
  - `method_missing`
  - 反射与 introspection
- **Enumerator 与 Enumerable 模块**
- **Fiber 与协程**

------

## 第六部分 Rails 入门

1. **Rails 简介**
   - MVC 架构
   - Rails 的目录结构
2. **Rails 基础操作**
   - 生成项目：`rails new`
   - 控制器与路由
   - 模型与数据库迁移
   - 视图与模板（ERB）
3. **Rails 开发流程**
   - RESTful 风格
   - 表单与验证
   - ActiveRecord ORM
   - 简单的 CRUD 应用

------

## 第七部分 Rails 进阶

- **关联（Associations）**：`has_many`、`belongs_to`
- **验证（Validations）**
- **回调（Callbacks）**
- **后台任务（ActiveJob）**
- **API-only 模式与 JSON 渲染**
- **前端集成（React、Vue 与 Rails）**

------

## 第八部分 测试与部署

- **RSpec 与 Minitest**：测试框架
- **Capybara**：集成测试
- **Rails 部署**
  - Heroku 部署
  - Docker 容器化
  - 本地与生产环境配置

------

## 第九部分 实战项目

- 使用 Rails + PostgreSQL 实现一个博客系统
- 添加用户注册与登录功能（Devise）
- 实现文件上传（ActiveStorage）
- 集成 React 前端（Rails + React/Vite）

------

## 第十部分 进阶与扩展

- **性能优化与调试**
- **安全性（CSRF、SQL 注入防护）**
- **Ruby 与其他语言的比较**
- **社区与学习资源**

