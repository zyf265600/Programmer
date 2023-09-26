# Angular 组件概述

Angular应用比喻大楼的话，那组件就是每一个房间。一个房间是有着独立的完整的居住功能。

==组件类控制模板的渲染，换句话说**Angular的渲染是靠数据**，理解这一点非常重要。==

组件是 Angular 应用的主要构造块。每个组件包括如下部分：

- ==一个 HTML 模板，用于声明页面要渲染的内容==
- ==一个用于定义行为的 TypeScript 类==
- ==一个 CSS 选择器，用于定义组件在模板中的使用方式==
- ==（可选）要应用在模板上的 CSS 样式==

通过 `@Component` 装饰器，可以快速告诉Angular这个组件是什么样的。

```typescript
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent { }
```

这里传递了三个信息：

- `selector` 给组件设个门牌号，当这个组件被使用时，用它来告诉组件所处的位置。
- `templateUrl` 告诉组件布局是什么样子的。
- `styleUrls` 告诉组件应该粉刷成什么样子的。



### selector

一个带有语义的名称对于定位非常重要，因为组件最终在DOM树中会以 `<app-root></app-root>` 这样的标签存在。

有很多文章或人会告诉你这个名词就像 CSS Selector（CSS选择器）一样，所以也可以设置为 `[app-root]` 而调用是 `<div app-root></div>`，二者虽说都没问题，但我不建议这么理解，因为组件就是组件，它是**有意义的一个完整性功能完整的DOM**。



### templateUrl / template

指定组件模板，同她后缀意思一样传递的是一个 URL 地址 `./app.component.html`。当 Webpack 打包以后，会将上面的内容打包进js文件中。

> `./` 表示当前所在目录。

当然她也提供另一种写法，可以直接将模板内容写在装饰器里面。

```typescript
template: `<h1></h1>`
```



### styleUrls

同组件模板类似，只不过她是以**数组**形式出现。（别问我为什么是数组）

这里的URL接收不光可以是一个 `css` 文件，她允许接收时下所有浏览CSS预处理（例：scss、less等），当然这并不是Angular的功能，而是Webpack的特性。

更多细节见[样式](https://cipchk.gitbooks.io/angular-practice/content/component/styles.html)章节。



## 前提条件

要创建一个组件，请先验证你是否满足以下前提条件：

1. [安装 Angular CLI](https://angular.cn/guide/setup-local#install-the-angular-cli)。
2. [创建一个带有初始项目的 Angular 工作区](https://angular.cn/guide/setup-local#create-a-workspace-and-initial-application)。如果还没有项目，你可以用 `ng new <project-name>` 创建一个，其中 `<project-name>` 是你的 Angular 应用的名字。



## 创建一个组件

Angular CLI 是用来创建组件的最简途径。你也可以手动创建一个组件。



### 使用 Angular CLI 创建组件

使用 Angular CLI 创建一个组件：

1. 在终端窗口中，导航到要放置你应用的目录。
2. 运行 `ng generate component <component-name>` 命令，其中 `<component-name>` 是新组件的名字。

默认情况下，该命令会创建以下内容：

- 一个以该组件命名的文件夹
- 一个组件文件 `<component-name>.component.ts`
- 一个模板文件 `<component-name>.component.html`
- 一个 CSS 文件，`<component-name>.component.css`
- 测试文件 `<component-name>.component.spec.ts`

其中 `<component-name>` 是组件的名称。

你可以更改 `ng generate component` 创建新组件的方式。欲知详情，参阅 Angular CLI 文档中的 [ng generate component](https://angular.cn/cli/generate#component-command)。