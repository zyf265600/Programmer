# Markdown Picture 图片语法

要添加图像，请使用感叹号 (`!`), 然后在方括号增加替代文本，图片链接放在圆括号里，括号里的链接后可以增加一个可选的图片标题文本，用双括号括起来。

插入图片Markdown语法代码：`![图片alt](图片链接 "图片title")`。

对应的HTML代码：`<img src="图片链接" alt="图片alt" title="图片title">`

```text
![这是图片](/assets/img/philly-magic-garden.jpg "Magic Gardens")
```

渲染效果如下：

![这是图片](assets/image-20220801081108572.png "Magic Gardens")



### 链接图片

给图片增加链接，请将图像的Markdown 括在方括号中，然后将链接添加在圆括号中。（相当于把网址的名字换成图片格式）

```text
[![沙漠中的岩石图片](/assets/img/shiprock.jpg "Shiprock")](https://markdown.com.cn)
```

渲染效果如下：

[![我的Github](assets/image-20220801081849039.png)](https://github.com/zyf265600)