# Markdown Code Blocks 代码语法

要将单词或短语表示为代码，请将其包裹在反引号 (`` ` ) 中。

![image-20220801073421813](assets/image-20220801073421813.png)



### 转义反引号

如果你要表示为代码的单词或短语中包含一个或多个反引号，则可以通过将单词或短语包裹在双反引号(```` ``)中。

![image-20220801073444543](assets/image-20220801073444543.png)



### 代码块

要创建代码块，请将代码块的每一行缩进至少四个空格或一个制表符。

```text
    <html>
      <head>
      </head>
    </html>
```

渲染效果如下：

```text
<html>
  <head>
  </head>
</html>
```



# Markdown 围栏代码块

Markdown基本语法允许您通过将行缩进四个空格或一个制表符来创建[代码块](https://markdown.com.cn/basic-syntax/code-blocks.html)。如果发现不方便，请尝试使用受保护的代码块。根据Markdown处理器或编辑器的不同，您将在代码块之前和之后的行上使用三个反引号（`）或三个波浪号（~）。

~~~text
```
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```
~~~

呈现的输出如下所示：

```text
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```



## 语法高亮

许多Markdown处理器都支持受围栏代码块的语法突出显示。使用此功能，您可以为编写代码的任何语言添加颜色突出显示。要添加语法突出显示，请在受防护的代码块之前的反引号旁边指定一种语言。

~~~tex
```json
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```
~~~

呈现的输出如下所示：

```json
{
  "firstName": "John",
  "lastName": "Smith",
  "age": 25
}
```

