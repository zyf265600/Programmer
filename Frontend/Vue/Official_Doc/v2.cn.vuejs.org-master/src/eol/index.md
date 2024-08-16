# Vue 2 已经到达终止支持 (EOL) 时间

Vue 2.0 发布于 7 年前的 2016 年。这是 Vue 成为主流框架过程中的一个重要里程碑。目前的许多 Vue 用户都是在 Vue 2 时代开始使用 Vue 的，并用它构建了许多出色的项目。

然而，同时维护两个大版本对我们来说是无法长期持续的。随着 Vue 3 及其生态系统的逐步成熟，团队是时候继续前进，将精力集中在最新的大版本上了。

**Vue 2 已于 2023 年 12 月 31 日达到终止支持时间。它不再会有新增功能、更新或问题修复。不过，它依然可以从所有现有的分发渠道 (CDN、包管理器、GitHub 等) 上获得。**

如果你要启动一个新项目，请从 [Vue 的最新版本 (3.x)](https://vuejs.org/) 开始。我们也强烈建议当前的 Vue 2 用户了解([迁移指南](https://v3-migration.vuejs.org/zh/))，尽管我们理解并非所有用户都有足够的资源或动力进行升级。如果你需要继续使用 Vue 2，但又对不在维护的软件有合规性或安全性要求，请移步了解 [HeroDevs 对 Vue 2 的无限期支持 (NES)](https://www.herodevs.com/support/nes-vue?utm_source=vuejs-org&utm_medium=vue2-eol-banner)。

## 下一步计划

自 2022 年 2 月 7 日起，Vue 3 已成为 Vue 的默认版本。已经迁移的用户可以享受到：

* 更小的包大小和更快的渲染速度带来的更好的性能。
* 增强的 TypeScript 支持，使大规模应用开发更轻松。
* 基于 Proxy 的更高效的响应性系统。
* 新的内置组件，如 Fragment、Teleport 和 Suspense。
* 改进的构建工具支持和 Vue Devtools 体验。
* ……以及更多！

如果条件允许，请考虑迁移！

## 仍需使用 Vue 2？你有如下选择

我们理解在过渡期间会出现各种情况，也充分意识到用户在迁移之前可能需要其他选择，或者迁移根本不可行。以下是一些可以考虑的其他方案。

### 更新至 Vue 2 最终版本

Vue 2 的最新版本 2.7.16，也是 Vue 2 的最终版本。该补丁版本包含一些对 2.7 功能的最终修复，并改进了与 Vue 3 的类型一致性。我们强烈建议更新至 2.7.16。这是下述延长支持的起点。

### 购买 Vue 2 的延长支持

如果你需要在终止支持 (EOL) 后继续使用 Vue 2，我们已与 HeroDevs 合作提供无限期支持 (NES)。Vue 2 无限期支持在官方结束支持后为 Vue 2 提供持续更新和安全补丁，从而使具有严格合规性要求的应用程序保持安全和合规。它还保证 Vue 2 应用程序将继续在现代浏览器中有效运行，并保持与 Nuxt、Vuex 和 Vuetify 2 等重要库的兼容性。 最后，Vue 2 无限期支持包含持续的安全监控，以及 14 天内修复问题的 SLA。

Vue 2 无限期支持是你在 Vue 2 长期技术支持 (LTS) 期间所享受的支持的延续，而且是无限期的。更多详细信息，请访问 [HeroDevs 的 Vue 2 无限期支持页面](https://www.herodevs.com/support/nes-vue?utm_source=vuejs-org&utm_medium=blog&utm_campaign=eol-by-eoy)。

### 通知用户你的 Vue 2 终止支持后的计划 

如果你目前无法迁移到 Vue 3 或使用 Vue 2 无限期支持，但仍使用 Vue 2，你可能需要考虑如何跟客户沟通你的 Vue 2 安全计划。

这并不适用于所有 Vue 用户，但许多团队被 SLA、合同和协议或其他下游方的义务所约束而禁止交付*不在维护的软件*。他们可能是客户、合规机构，甚至是公司内部部门。对于越来越多的行业来说，监管机构也在提高对软件创建者责任的期望。

如果你的工作涉及此类业务需求，你可能需要让客户、经理、首席信息安全官 (CISO) 或其他相关利益方了解你的支持管理计划，并解决任何潜在的公共漏洞披露 (CVE) 问题。[Vue 2 在过去并未出现重大漏洞](https://v2.cn.vuejs.org/lts/#:~:text=Vue%202%20%E5%9C%A8%E8%BF%87%E5%8E%BB%E5%B0%9A%E6%9C%AA%E6%9C%89%E8%BF%87%E7%9C%9F%E6%AD%A3%E7%9A%84%E5%AE%89%E5%85%A8%E9%97%AE%E9%A2%98%E7%9A%84%E8%AE%B0%E5%BD%95%EF%BC%8C%E4%BD%86%E6%98%AF%E4%BD%A0%E5%8F%AF%E8%83%BD%E4%BC%9A%E9%9C%80%E8%A6%81%E4%B8%80%E4%B8%AA%E7%89%88%E6%9C%AC%E6%9D%A5%E5%BA%94%E5%AF%B9%E5%90%88%E8%A7%84%E6%88%96%E5%85%AC%E5%8F%B8%E6%94%BF%E7%AD%96%E9%97%AE%E9%A2%98%E3%80%82)，但即使是最成熟的项目终止支持后也难免会出现 CVE——无论是直接出现还是通过受损的依赖关系出现。通过 [OpenCVE](https://www.opencve.io/) 和 [Snyk](https://snyk.io) 等组织订阅 CVE 通知，可以在漏洞被发现后第一时间发现它们。浏览器也可能会发布不兼容旧版库的变更——这种情况很少见，但确实会发生。