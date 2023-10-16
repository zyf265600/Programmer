# jQuery

## 1. 什么是jQuery?

jQuery实际上就是对现有的JavaScript的一种扩展，它非常轻量级，压缩后大概32KB，它兼容于各种浏览器，这样就可以非常方便地添加适用于多种浏览器的特效。

jQuery是由美国人John Resig最初创建的，经过几个版本的发展，最重要的是它提供了相当健全的文档，便于广大jQuery爱好者进行学习。

`jQuery` 库是一个 `JavaScript `文件，您可以使用 HTML 的 `<script>` 标签引用它：

```javascript
<script src="jquery-3.5.1.min.js"></script>
```



### 1.1 jQuery的作用

jQuery本身是一个基于插件的JavaScript库，它的各种功能可以通过新的插件进行增强。jQuery为Web编程提供了一个抽象的层，使得它可以兼容于任何浏览器，并且大大简化了原先用JavaScript做的工作。

**总而言之， jQuery可以完成如下所示的工作：**

> **1. 快速获取文档元素**
> jQuery的选择机制构建于Css的选择器，它提供了快速查询DOM文档中元素的能力，而且大大强化了JavaScript中获取页面元素的方式。
>
> **2. 提供漂亮的页面动态效果:**
> jQuery中内置了一系列的动画效果，可以开发出非常漂亮的网页，目前许多知名的网站都使用了jQuery的内置的效果，比如淡入淡出，元素移除等动态特效。
>
> **3. 创建Ajax无刷新网页**
> Ajax是异步的JavaScript和XML的简称，可以开发出非常灵敏无刷新的网页，特别是开发服务器端网页时，比如PHP网站，需要往返地与服务器沟通，如果不使用Ajax，每次数据更新不得不重新刷新网页，而使用了Ajax特效后，可以对页面进行局部刷新，提供非常动态的效果。
>
> **4. 提供对JavaScript语言的增强:**
> jQuery提供了对基本JavaScript结构的增强，比如元素选代和数组处理等操作。
>
> **5. 增强的事件处理:**
> jQuery提供了各种页面事件，它可以避免程序员在HTML中添加太多事件处理代码，最重要的是，它的事件处理器消除了各种浏览器兼容性问题。
>
> **6. 更改网页内容**
> jQuery可以修改网页中的内容,比如更改网页的文本、插入或转网页图像, jQuery简化了原本使用JavaScript代码需要处理的方式。



## 2. jQuery 基本使用

### 2.1 文档加载后执行代码

当浏览器 `DOM`（文档对象模型） 已经加载，并且页面（包括图像）已经完全呈现时，会发生 `ready`[事件](https://www.w3cschool.cn/minicourse/play/jquery_learn?cp=16660&gid=0)。

由于[ready事件](https://www.w3cschool.cn/minicourse/play/jquery_learn?cp=16660&gid=0)在文档就绪后发生，因此把所有其他的 jQuery 事件和函数置于该事件中是非常好的做法。

例如:

```javascript
$(document).ready(function() {
 // 在文档加载后执行的代码
});
```

==这是为了防止文档在完全加载（就绪）之前运行 jQuery 代码，即在 DOM 加载完成后才可以对 DOM 进行操作。==



### 2.2 jQuery 基础语法

`jQuery `语法是通过选取 `HTML 元素`，并对选取的元素执行某些操作。

基础语法： 

```text
$(selector).action()
```

- 美元符号定义 jQuery, 也就是说 $ 美元符代表是 jQuery 的简写或简称
- 选择符`（selector）`"查询"和"查找" HTML 元素
- jQuery 的 `action()` 执行对元素的操作, 这边的 action() 只是代表对元素操作的方法, 比如: .click(), prop()方法。

示例:

```javascript
$("#test").hide(); //隐藏 id="test" 的元素
```



### 2.3 使用 jQuery 选择元素

#### 2.3.1  使用 jQuery 配合元素选择器选择元素

让我们开始写第一个`jQuery`语句，所有的 jQuery 函数以`$`开头，这个符号通常被称为`美元符号`。

jQuery 通常选取并操作带有`选择器（selector）`的 HTML 标签。

**元素选择器**

jQuery 元素选择器基于元素名选取元素。

在页面中选取所有 \<p> 元素:

```javascript
$("p")
```

示例:

```javascript
$("button").click(function(){
    $("p").hide();
});
```

**jQuery 的`.addClass()`方法用来给标签添加类。**



#### 2.3.2 使用 jQuery 配合 class 选择器选择元素

jQuery 类选择器可以通过指定的 class 查找元素。

语法如下：

```javascript
$(".test")
```

示例:

```javascript
$(".test").hide();
```



#### 2.3.3 使用 jQuery 配合 id 选择器选择元素

jQuery `#id` 选择器通过 HTML 元素的 id 属性选取指定的元素。

页面中元素的 id 应该是唯一的，所以您要在页面中选取唯一的元素需要通过 #id 选择器。

通过 id 选取元素语法如下：

```javascript
$("#test")
```

示例:

```javascript
$("#test").hide();
```



### 2.4 使用 jQuery 绑定点击事件

`click() `方法触发 click 事件，或规定当发生 click 事件时运行的函数。

语法:

```javascript
$(selector).click()
```

示例

```javascript
$("p").click(function(){
    alert("段落被点击了。");
});
```

给`button`标签绑定点击事件, 使点击按钮时隐藏`p`标签: 

`````html
<head>
<meta charset="utf-8" />
<title>jQuery实战教程</title>
<script src="https://cdn.bootcdn.net/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script>
  $(document).ready(function () {
    // 在这行下面添加代码
    $("button").click(function(){
        $("p").hide();
    });
  });
</script>
</head>
<body>
<h2>这是一个标题</h2>
<p>这是一个段落。</p>
<p>这是另一个段落。</p>
<button>点我</button>
</body>

`````



### 2.5 使用 jQuery 从元素中添加/移除 class

`addClass()` 方法从所选元素中添加一个或多个类名称。

`removeClass()` 方法从所选元素中删除一个或多个类名称。

如果将类名作为参数包括在内，则只会添加/删除该类。

如果在参数中未指定类名，则将添加/删除所有类。

**语法：**

删除所有类

```javascript
$(selector).removeClass()
```

删除指定的类

```javascript
$(selector).removeClass(className)
```

使用函数删除类

```javascript
$(selector).removeClass(function(index, currentClass))
```

示例：

```javascript
$("p").removeClass("highlight");
```



### 2.6 使用 jQuery 更改元素的 CSS

jQuery `css()`方法获取或设置所选元素的一个或多个样式属性。

此方法提供了一种将样式（内联样式）直接应用于HTML元素的快速方法。

**设置CSS属性和值**

语法：

```text
$(selector).css(property, value)
```

示例：

```javascript
$("p").css("color", "blue");
```



### 2.7 使用 jQuery 禁用元素

`prop()` 方法==设置==或==返回==被选元素的属性和值。

当该方法用于返回属性值时，则==返回第一个匹配元素的值。==

当该方法用于设置属性值时，则==为匹配元素集合设置一个或多个属性/值对。==

1. **获取属性值**: 如果你只传递一个参数（属性名）给 `prop()` 方法，它将返回该属性的当前值。

   ```js
   var isChecked = $("#myCheckbox").prop("checked");
   ```

   在上述代码中，我们正在检查一个复选框是否被选中。如果被选中，`isChecked` 将为 `true`，否则为 `false`。

2. **设置属性值**: 你可以传递两个参数给 `prop()` 方法来设置元素的属性值：属性名和你想要设置的值。

   ```js
   $("#myCheckbox").prop("checked", true);
   ```

   这将把 ID 为 "myCheckbox" 的复选框设置为选中状态。

3. **设置多个属性**: 你还可以传递一个对象给 `prop()` 方法来一次设置多个属性。

   ```js
   $("#myElement").prop({
       "checked": true,
       "disabled": false
   });
   ```



示例:

```javascript
$("h2").prop("title","欢迎来到w3cschool学习jQuery");
```

当设置按钮的`disabled`属性的值为`true`效果是禁用按钮。请仅禁用`target1`按钮:

````html
<script>
  $(document).ready(function() {
    $("#target1").css("color", "red");
    $("#target1").prop("disabled", true); //禁用功能
  });
</script>
````



### 2.8 使用 jQuery 更改元素内部的文本

`html()` 方法获取或设置所选元素的内容（`innerHTML`）。`innerHTML` 是 JavaScript 中的一个属性，它允许我们获取或设置某个 HTML 元素的内容。这个内容可以是简单的文本、HTML 标签或者其他的结构化内容。

使用`html()`方法获取内容时，它将返回第一个选定元素的内容。

使用`html()`方法设置内容时，它将覆盖所有选定元素的内容。

**注意：**

使用`html()`设置元素的内容时，该元素中的所有内容都将被新内容完全替换。

**语法：**

获取内容：

```
$(selector).html()
```

设定内容：

```
$(selector).html(content)
```

示例：

```javascript
$("p:eq(1)").html('我是<b>被设置过的</b>第二段');
```

==`:eq(1) `表示获取第二个元素标签。==



### 2.9 使用 jQuery 删除元素

`remove() `方法移除被选元素，包括所有的文本和子节点。

该方法也会移除被选元素的数据和事件。

示例:

```javascript
$("p").remove();
```



### 2.10 使用 jQuery 的 appendTo 方法移动元素

`appendTo()` 方法在被选元素的==结尾插入 HTML 元素。 移动的是元素而不是文本！==

**语法:**

```text
$(content).appendTo(selector)
```

示例:

```javascript
$("<span>Hello World!</span>").appendTo("p");
```

我们也可以选取 HTML 标签并将其添加到另一个标签里面。==原本的标签会消失，从而达成移动的效果。==
例如，如果要把`target4`从右框移到左框，可以设置如下：

```javascript
$("#target4").appendTo("#left-well"); 
```



### 2.11 使用 jQuery 克隆元素

`clone()` 方法生成被选元素的副本，包含子节点、文本和属性。

**语法:**

```text
$(selector).clone(true|false)
```

参数: true 规定需复制事件处理程序。当使用 `clone(true)` 时，==它不仅会复制元素及其内容，还会复制所有附加到元素和其子元素上的事件处理程序。==

参数: false 默认。规定不复制事件处理程序。当使用没有参数的 `clone()` 方法时，==它将默认只复制元素及其内容。==这意味着任何附加到元素的事件处理程序都不会被复制。

示例:

```javascript
$("p").clone().appendTo("body");
```

如果想把`target2`从`left-well`复制到`right-well`，可以设置如下：

```javascript
 $("#target2").clone().appendTo("#right-well"); 
```

你是否注意到这两个 jQuery 方法连在一起了吗？

这被称为`链式调用（function chaining）`，是一种用 jQuery 实现效果的简便方法。



### 2.12 使用 jQuery 选择元素的父元素

每个 HTML 标签都默认`继承（inherits）`其`父标签（parent element）`的 CSS 属性。 

`parent() `方法返回被选元素的直接父元素。

==DOM 树：该方法只沿着 DOM 树向上遍历单一层级。==

**语法:**

```text
$(selector).parent(filter)
```

示例:

```javascript
$("span").parent().css({ color: "red", border: "2px solid red" });
```



### 2.13 使用 jQuery 选择元素的子元素

把 HTML 标签放到另一个级别的标签里，这些 HTML 标签被称为该标签的`子标签（children element）`。

`children() `方法返回被选元素的所有直接子元素。

==DOM 树：该方法只沿着 DOM 树向下遍历单一层级。==

**语法:**

```text
$(selector).children(filter)
```

示例:

```javascript
$("ul").children().css({ color: "red", border: "2px solid red" });
```



#### 2.13.1 使用 jQuery 选择元素的特定子元素

`:nth-child(*n*)` 选择器选取属于==其父元素的不限类型的第 *n* 个子元素==的所有元素。先看父，后看子。

**语法:**

```text
:nth-child(n|even|odd|formula)
```

| 参数      | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| *n*       | 要匹配的每个子元素的索引。 必须是一个数字。==第一个元素的索引号是 1。== |
| even      | 选取每个偶数子元素。                                         |
| odd       | 选取每个奇数子元素。                                         |
| *formula* | 规定哪个子元素需通过公式 (*an* + *b*) 来选取。 实例：p:nth-child(3n+2) 选取每个第三段，从第二个子元素开始。 |

示例:

```javascript
$("p:nth-child(3)").css("background-color", "yellow");
```



#### 2.13.2 使用 jQuery 选择偶数元素

`:odd` 选择器选取带有奇数索引号的每个元素（比如：1、3、5 等等）。

==索引值从 0 开始，==第一个元素是偶数 (0)，第二个元素是奇数 (1)，以此类推。

最常见的用法：与其他选择器一起使用，选取指定组合中每个奇数序号的元素（如上面的实例）。

**提示：**请使用 `:even` 选择器来选取带有偶数序号的元素。

**语法:**

```text
$(":odd")
```

示例:

```javascript
$("tr:odd").css("background-color", "yellow");
```



### 2.14 使用 jQuery 修改整个页面

现在我们来试一试让元素消失的特效。jQuery 也能选取`body`标签。使整个`body`标签淡出：

```javascript
$("body").addClass("animated fadeOut");
```