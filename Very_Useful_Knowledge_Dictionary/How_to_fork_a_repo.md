# How Fork Works

下面是对开源协作中典型流程 **“fork → clone → 开发 → push（到 fork）→ PR”** 的详细解释，适合你现在参与像 `eisop/checker-framework` 这样的项目。



## 一、Fork：在 GitHub 上复制一份仓库到自己的账号下

### 操作：

1. 打开目标项目仓库，比如：
    https://github.com/eisop/checker-framework
2. 点击右上角的 **“Fork”** 按钮。
3. GitHub 会在你的账号下创建一个新的远程仓库：
    `https://github.com/<你的用户名>/checker-framework`

### 结果：

你现在拥有了一个**独立的云端副本**，对它拥有完整写权限。

------



## 二、Clone：将 fork 下来的仓库复制到本地

```
git clone git@github.com:<你的用户名>/checker-framework.git
cd checker-framework
```

### 结果：

你在本地获得了完整的仓库副本，Git 自动设置远程名为：

```
origin → 你的 fork（你有推送权限）
```

------



## 三、添加上游（可选但推荐）：追踪原始仓库的变动

```
git remote add upstream https://github.com/eisop/checker-framework.git
git remote -v
# origin    git@github.com:<你>/checker-framework.git (fetch/push)
# upstream  https://github.com/eisop/checker-framework.git (fetch)
```

这样你以后可以通过 `git fetch upstream` 把主项目的最新提交拉下来。

------



## 四、开发：基于主分支创建功能分支并开发

### 示例：

```
git checkout -b fix-nullness-analysis upstream/master
```

然后你可以开始在这个分支中修改代码。

------

## 五、Push：把本地更改推送到你的 fork

```
git add .
git commit -m "Fix bug in Nullness Checker when analyzing lambda expressions"
git push origin fix-nullness-analysis
```

注意这里是推送到你的 fork（origin），不是主仓库。

------

## 六、PR（Pull Request）：请求将你的更改合并回主仓库

1. 打开浏览器，进入你 fork 的 GitHub 页面。
2. GitHub 会自动检测你新推送的分支，并提示你“Compare & Pull Request”。
3. 点击，填写：
   - PR 标题（说明你做了什么）
   - PR 描述（详细解释动机、修改点、测试情况等）
4. 设置目标仓库是：
    `eisop/checker-framework` 的主分支（如 `master`）
5. 提交 PR。

------

## 七、等待审查 / 修改 / 合并

- Maintainer（如 Alex 或 Werner）会审核你的更改。

- 可能会提出改进建议，要求你修改：

  ```
  # 修改后
  git add .
  git commit --amend 或 git commit -m "Update according to review"
  git push origin fix-nullness-analysis -f  # 强推更新 PR
  ```

- 审查通过后，Maintainer 会将你的 PR 合并入主项目！

------

## 总结流程图

```
GitHub:
┌─────────────┐
│ Upstream    │ ← 你无写权限
│ (原始仓库)   │
└────┬────────┘
     ↓ Fork
┌─────────────┐
│ Your Fork   │ ← 你有写权限
│ (cloud copy)│
└────┬────────┘
     ↓ Clone
┌─────────────┐
│ Your Local  │ ← 开发、测试
│ Git repo    │
└────┬────────┘
     ↓ Push
┌─────────────┐
│ Your Fork   │ ← 新分支含更改
└────┬────────┘
     ↓ Pull Request
┌─────────────┐
│ Upstream    │ ← Maintainer Review + Merge
└─────────────┘
```

------

这个流程是参与任何大型开源项目的**标准协作方式**。如果你未来打算为 Java 开源工具如 Checker Framework、Spring、JMH 等贡献代码，都会用到这个模式。
