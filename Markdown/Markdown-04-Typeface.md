# Markdown Typeface 强调语法

#### 通过将文本设置为**粗体**或*斜体*来强调其重要性。



## 粗体（Bold）

要加粗文本，请在单词或短语的前后各添加**两个**星号（asterisks）或**两个**下划线（underscores）。

| Markdown语法                 | HTML                                      | 预览效果                   |
| ---------------------------- | ----------------------------------------- | -------------------------- |
| `I just love **bold text**.` | `I just love <strong>bold text</strong>.` | I just love **bold text**. |
| `I just love __bold text__.` | `I just love <strong>bold text</strong>.` | I just love **bold text**. |
| `Love**is**bold`             | `Love<strong>is</strong>bold`             | Love**is**bold             |



## 斜体（Italic）

要用斜体显示文本，请在单词或短语前后添加**一个**星号（asterisk）或**一个**下划线（underscore）。要斜体突出单词的中间部分，请在字母前后各添加一个星号，**中间不要带空格**。

| Markdown语法                           | HTML                                          | 预览效果                             |
| -------------------------------------- | --------------------------------------------- | ------------------------------------ |
| `Italicized text is the *cat's meow*.` | `Italicized text is the <em>cat's meow</em>.` | Italicized text is the *cat’s meow*. |
| `Italicized text is the _cat's meow_.` | `Italicized text is the <em>cat's meow</em>.` | Italicized text is the *cat’s meow*. |
| `A*cat*meow`                           | `A<em>cat</em>meow`                           | A*cat*meow                           |

### 

## 同时使用粗体（Bold）和斜体（Italic）

要同时用粗体和斜体突出显示文本，请在单词或短语的前后各添加三个星号或下划线。要加粗并用斜体显示单词或短语的中间部分，请在要突出显示的部分前后各添加三个星号，中间不要带空格。(尽量用三个Star Signs)

| Markdown语法                              | HTML                                                         | 预览效果                                |
| ----------------------------------------- | ------------------------------------------------------------ | --------------------------------------- |
| `This text is ***really important***.`    | `This text is <strong><em>really important</em></strong>.`   | This text is ***really important***.    |
| `This text is ___really important___.`    | `This text is <strong><em>really important</em></strong>.`   | This text is ***really important***.    |
| `This text is __*really important*__.`    | `This text is <strong><em>really important</em></strong>.`   | This text is ***really important***.    |
| `This text is **_really important_**.`    | `This text is <strong><em>really important</em></strong>.`   | Thi text is ***really important***.     |
| `This is really***very***important text.` | `This is really<strong><em>very</em></strong>important text.` | This is really***very***important text. |



### 粗体（Bold）和斜体（Italic）用法注意事项

Markdown 应用程序在如何处理单词或短语中间的下划线上并不一致。为兼容考虑，在单词或短语中间部分加粗的话，请使用星号（asterisks）。**<font color="red">（少用下划线）</font>**

| ✅ Do this        | ❌ Don't do this  |
| ---------------- | ---------------- |
| `Love**is**bold` | `Love__is__bold` |

