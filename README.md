# Programmer

**Programmer** is a personal knowledge base for programming practice, algorithm training, and engineering notes. Content is grouped by language and topic so it is easy to browse and revisit.

This repository is both a long-term learning archive and a practical reference for interview prep, multi-language coding, and tooling.

## What's inside

| Area | Paths | Notes |
|------|--------|--------|
| Algorithms & interview | `Algorithm/`, `Leetcode/`, `Interview/`, `Roadmap/` | Data structures, DP, LeetCode notes, resume/interview material, learning roadmaps |
| Systems languages | `C/`, `Cpp/`, `Go/` | Fundamentals, advanced topics, projects, Go notes + official tour submodules |
| JVM / backend | `Java/`, `Maven/`, `Gradle/`, `Hibernate/`, `SQL/` | Java basics → Spring/Spring Boot, build tools, ORM, MySQL / analytics SQL |
| Web & frontend | `Frontend/`, `React/`, `Web_Dev_Intro/`, `typescript` | HTML/CSS, JS/TS, Vue, Angular, Bootstrap, React apps |
| Other languages | `Python/`, `R/`, `RubyonRail/` | Tutorials, small projects, Rails koans |
| Ops & tooling | `Linux/`, `Git/`, `Homebrew/`, `AWS/`, `Unit_Test/`, `Markdown/` | Environment, VCS, cloud, testing, writing workflow |
| Portfolio site | `portfolio/` | Astro + Tailwind personal site (git submodule) |
| Utilities | `script/`, `Very_Useful_Knowledge_Dictionary/` | Python helpers for notes/PDF/code formatting; quick-reference sheets |
| Misc | `COOP/`, `ChatGPT/`, `English/`, `Typing/`, `Real-Time_Operating_System/` | Coop notes, language practice, RTOS, etc. |

## Git submodules

These directories are formal submodules (see `.gitmodules`):

| Path | Upstream |
|------|----------|
| `portfolio/` | [zyf265600/portfolio](https://github.com/zyf265600/portfolio.git) |
| `Go/tour/` | [Go-zh/tour](https://github.com/Go-zh/tour.git) |
| `Go/go-zh-tour/` | [Go-zh/tour](https://github.com/Go-zh/tour.git) |
| `Leetcode/lc-plugin-template/` | [labuladong/lc-plugin-template](https://github.com/labuladong/lc-plugin-template.git) |

Clone with submodules:

```bash
git clone --recurse-submodules git@github.com:zyf265600/Programmer.git
```

If you already cloned without submodules:

```bash
git submodule update --init --recursive
```

## Layout tips

- Prefer the language/topic folder first (`Go/`, `Java/`, `Frontend/`, …), then drill into notes or code.
- LeetCode practice lives mainly under `Leetcode/` (notes + `lc-plugin-template` editor solutions).
- Reusable automation for Markdown/PDF/code-block cleanup is under `script/`.

Suggestions and issues are welcome.

---

**Programmer** 是个人编程实践、算法训练与工程学习笔记的知识库，按语言与主题分目录整理，便于长期查阅。

既作为个人学习归档，也可作为面试准备、多语言练习与工具链笔记的参考。

## 内容概览

| 方向 | 目录 | 说明 |
|------|------|------|
| 算法与面试 | `Algorithm/`、`Leetcode/`、`Interview/`、`Roadmap/` | 数据结构、DP、刷题笔记、面试/简历材料、学习路线 |
| 系统向语言 | `C/`、`Cpp/`、`Go/` | 基础到进阶、项目练习；Go 笔记及官方 Tour 子模块 |
| JVM / 后端 | `Java/`、`Maven/`、`Gradle/`、`Hibernate/`、`SQL/` | Java 基础 → Spring/Spring Boot、构建工具、ORM、MySQL/分析 SQL |
| Web / 前端 | `Frontend/`、`React/`、`Web_Dev_Intro/`、`typescript` | HTML/CSS、JS/TS、Vue、Angular、Bootstrap、React |
| 其他语言 | `Python/`、`R/`、`RubyonRail/` | 教程、小项目、Rails koans |
| 运维与工具 | `Linux/`、`Git/`、`Homebrew/`、`AWS/`、`Unit_Test/`、`Markdown/` | 环境、版本管理、云、测试、写作流程 |
| 作品集站点 | `portfolio/` | Astro + Tailwind 个人站（git submodule） |
| 工具脚本 | `script/`、`Very_Useful_Knowledge_Dictionary/` | 笔记/PDF/代码块处理脚本；速查资料 |
| 其他 | `COOP/`、`ChatGPT/`、`English/`、`Typing/`、`Real-Time_Operating_System/` | Coop、语言练习、RTOS 等 |

## Git 子模块

正式 submodule 见上表与 `.gitmodules`。克隆时请使用 `--recurse-submodules`，或事后执行 `git submodule update --init --recursive`。

## 使用建议

- 先按语言/主题进目录，再看笔记或代码。
- 刷题相关优先看 `Leetcode/`（含 `lc-plugin-template`）。
- Markdown/PDF/代码格式相关脚本在 `script/`。

欢迎浏览与交流，也可通过 issue 提出建议。
