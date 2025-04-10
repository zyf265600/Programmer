## [Python2.x 与 3​​.x 版本区别](https://www.runoob.com/python/python-2x-3x.html)

[index](目录.md)

---
Python2.x 与 3​​.x 版本区别
======================

Python 的 3​​.0 版本，常被称为 Python 3000，或简称 Py3k。相对于 Python 的早期版本，这是一个较大的升级。

为了不带入过多的累赘，Python 3.0 在设计的时候没有考虑向下相容。

许多针对早期 Python 版本设计的程式都无法在 Python 3.0 上正常执行。

为了照顾现有程式，Python 2.6 作为一个过渡版本，基本使用了 Python 2.x 的语法和库，同时考虑了向 Python 3.0 的迁移，允许使用部分 Python 3.0 的语法与函数。

新的 Python 程式建议使用 Python 3.0 版本的语法。

除非执行环境无法安装 Python 3.0 或者程式本身使用了不支援 Python 3.0 的第三方库。目前不支持 Python 3.0 的第三方库有 Twisted, py2exe, PIL等。

大多数第三方库都正在努力地相容 Python 3.0 版本。即使无法立即使用 Python 3.0，也建议编写相容 Python 3.0 版本的程式，然后使用 Python 2.6, Python 2.7 来执行。

Python 3.0 的变化主要在以下几个方面:

---

print 函数
--------

print 语句没有了，取而代之的是
print()
函数。 Python 2.6 与 Python 2.7 部分地支持这种形式的 print 语法。在 Python 2.6 与Python 2.7 里面，以下三种形式是等价的：

```

print "fish"
print ("fish") # 注意print后面有个空格
print("fish") # print()不能带有任何其它参数

```

然而，Python 2.6 实际已经支持新的 print() 语法，实例如下：

```

from __future__ import print_function
print("fish", "panda", sep=', ')

```

如果 Python2.x 版本想使用使用 Python3.x 的 print 函数，可以导入
\_\_future\_\_
包，该包禁用 Python2.x 的 print 语句，采用 Python3.x 的 print 函数：

实例
--

```
>>> list =["a", "b", "c"]
>>> print list    # python2.x 的 print 语句
['a', 'b', 'c']
>>> from __future__ import print_function  # 导入 __future__ 包
>>> print list     # Python2.x 的 print 语句被禁用，使用报错
  File "<stdin>", line 1
    print list
             ^
SyntaxError: invalid syntax
>>> print (list)   # 使用 Python3.x 的 print 函数
['a', 'b', 'c']
>>>
```

Python3.x 与 Python2.x 的许多兼容性设计的功能可以通过
\_\_future\_\_
这个包来导入。

---

Unicode
-------

Python 2 有 ASCII str() 类型，unicode() 是单独的，不是 byte 类型。

现在， 在 Python 3，我们最终有了 Unicode (utf-8) 字符串，以及一个字节类：byte 和 bytearrays。

由于 Python3.x 源码文件默认使用 utf-8 编码，所以使用中文就更加方便了：

```

>>> 中国 = 'china' 
>>>print(中国) 
china

```

Python 2.x

```

>>> str = "我爱北京天安门"
>>> str
'\xe6\x88\x91\xe7\x88\xb1\xe5\x8c\x97\xe4\xba\xac\xe5\xa4\xa9\xe5\xae\x89\xe9\x97\xa8'
>>> str = u"我爱北京天安门"
>>> str
u'\u6211\u7231\u5317\u4eac\u5929\u5b89\u95e8'

```

Python 3.x

```

>>> str = "我爱北京天安门"
>>> str
'我爱北京天安门'

```

---

除法运算
----

Python 中的除法较其它语言显得非常高端，有套很复杂的规则。Python 中的除法有两个运算符，
/
和
//

首先来说
/
除法:

在 Python 2.x 中
/
除法就跟我们熟悉的大多数语言，比如 Java 和 C ，整数相除的结果是一个整数，把小数部分完全忽略掉，浮点数除法会保留小数点的部分得到一个浮点数的结果。

在 Python 3.x 中
/
除法不再这么做了，对于整数之间的相除，结果也会是浮点数。

Python 2.x:

```

>>> 1 / 2
0
>>> 1.0 / 2.0
0.5

```

Python 3.x:

```

>>> 1/2
0.5

```

而对于
//
除法，这种除法叫做 floor 除法，会对除法的结果自动进行一个 floor 操作，在 Python 2.x 和 Python 3.x 中是一致的。

python 2.x:

```

>>> -1 // 2
-1
```

python 3.x:

```

>>> -1 // 2
-1

```

注意的是并不是舍弃小数部分，而是执行 floor 操作，如果要截取整数部分，那么需要使用 math 模块的 trunc 函数

python 3.x:

```

>>> import math
>>> math.trunc(1 / 2)
0
>>> math.trunc(-1 / 2)
0

```

---

异常
--

在 Python 3 中处理异常也轻微的改变了，在 Python 3 中我们现在使用 as 作为关键词。

捕获异常的语法由
**except exc, var**
改为
**except exc as var**
。

使用语法except (exc1, exc2) as var 可以同时捕获多种类别的异常。 Python 2.6 已经支持这两种语法。

* 1. 在 2.x 时代，所有类型的对象都是可以被直接抛出的，在 3.x 时代，只有继承自BaseException的对象才可以被抛出。
* 2. 2.x raise 语句使用逗号将抛出对象类型和参数分开，3.x 取消了这种奇葩的写法，直接调用构造函数抛出对象即可。

在 2.x 时代，异常在代码中除了表示程序错误，还经常做一些普通控制结构应该做的事情，在 3.x 中可以看出，设计者让异常变的更加专一，只有在错误发生的情况才能去用异常捕获语句来处理。

Python 2.x
: 异常处理语法使用逗号。

```
try:
    # code
except Exception, e:
    print e
```

Python 3.x
: 异常处理语法使用 as。

```
try:
    # code
except Exception as e:
    print(e)
```

---

xrange() 和 range()
------------------

Python 2.x
: range() 返回一个列表，而 xrange() 返回一个生成器（更节省内存）。

```

range(5)  # 返回 [0, 1, 2, 3, 4]
xrange(5)  # 返回 xrange 对象，按需生成数字
```

Python 3.x
: xrange() 被移除，range() 返回一个生成器，节省内存。

```

range(5)  # 返回一个迭代器，按需生成数字
```

---

八进制字面量表示
--------

八进制数必须写成 0o777，原来的形式 0777 不能用了；二进制必须写成
0b111
。

新增了一个
bin()
函数用于将一个整数转换成二进制字串。 Python 2.6 已经支持这两种语法。

在Python 3.x中，表示八进制字面量的方式只有一种，就是0o1000。

python 2.x

```

>>> 0o1000
512
>>> 01000
512

```

python 3.x

```

>>> 01000
  File "<stdin>", line 1
    01000
        ^
SyntaxError: invalid token
>>> 0o1000
512

```

---

不等运算符
-----

Python 2.x中不等于有两种写法 != 和 <>

Python 3.x中去掉了<>, 只有!=一种写法，还好，我从来没有使用<>的习惯

---

去掉了repr表达式``
------------

Python 2.x 中反引号``相当于repr函数的作用

Python 3.x 中去掉了``这种写法，只允许使用repr函数，这样做的目的是为了使代码看上去更清晰么？不过我感觉用repr的机会很少，一般只在debug的时候才用，多数时候还是用str函数来用字符串描述对象。

```

def sendMail(from_: str, to: str, title: str, body: str) -> bool:
    pass

```

---

多个模块被改名（根据PEP8）
---------------

| 旧的名字 | 新的名字 |
| --- | --- |
| \_winreg | winreg |
| ConfigParser | configparser |
| copy\_reg | copyreg |
| Queue | queue |
| SocketServer | socketserver |
| repr | reprlib |

StringIO模块现在被合并到新的io模组内。 new, md5, gopherlib等模块被删除。 Python 2.6已经支援新的io模组。

httplib, BaseHTTPServer, CGIHTTPServer, SimpleHTTPServer, Cookie, cookielib被合并到http包内。

取消了exec语句，只剩下exec()函数。 Python 2.6已经支援exec()函数。

---

5.数据类型
------

1）Py3.X去除了long类型，现在只有一种整型——int，但它的行为就像2.X版本的long

2）新增了bytes类型，对应于2.X版本的八位串，定义一个bytes字面量的方法如下：

```

>>> b = b'china' 
>>> type(b) 
<type 'bytes'> 

```

str 对象和 bytes 对象可以使用 .encode() (
**str -> bytes**
) 或 .decode() (
**bytes -> str**
)方法相互转化。

```

>>> s = b.decode() 
>>> s 
'china' 
>>> b1 = s.encode() 
>>> b1 
b'china' 

```

3）dict的.keys()、.items 和.values()方法返回迭代器，而之前的iterkeys()等函数都被废弃。同时去掉的还有
dict.has\_key()，用 in替代它吧 。

---

6.标准库重组
-------

Python 3.x: 一些模块被重新组织或重命名。例如，urllib、urlparse 被合并为 urllib。

```
# Python 2.x
import urllib
import urlparse

# Python 3.x
import urllib.parse
```

---

7.函数的 iteritems() 和 items()
---------------------------

Python 2.x
: 字典有 items() 和 iteritems() 方法，items() 返回一个列表，iteritems() 返回一个迭代器。

```

d = {'a': 1, 'b': 2}
d.items()     # 返回 [('a', 1), ('b', 2)]
d.iteritems()  # 返回字典的迭代器
```

Python 3.x
: iteritems() 被移除，items() 返回一个字典视图（即一个迭代器）。

```

d = {'a': 1, 'b': 2}
d.items()     # 返回 dict_items([('a', 1), ('b', 2)])
```

---

8. 模块的 \_\_future\_\_ 支持
------------------------

Python 3.x: 许多 Python 2.x 特性已经被移除，Python 2.x 用户如果想要在代码中提前使用 Python 3.x 的行为，可以使用 \_\_future\_\_ 导入来实现兼容。

```

from __future__ import print_function
```

9. 字典的排序
--------

Python 2.x: 字典是无序的（没有保证顺序）。

Python 3.x: 字典是有序的，按照插入顺序保留元素。

10. next() 方法
-------------

Python 2.x: next() 是一个函数，通常与 iter() 一起使用。

Python 3.x: next() 是一个内建函数，用法与 Python 2.x 相同，但其参数不同，Python 3.x 中支持通过 next(iterator, default) 来设置默认值。