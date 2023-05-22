# **第一章**

## **第1课 初识自动化测试**





## 第2课 环境搭建 1、jdk安装、环境变量配置

1. **jd k下载地址:<https://www.oracle.com/technetwork/java/javase/>**

环境变量:JAVA\_HOME ->D:\soft\jdk;

`    `Path- -> % JAVA\_HOME%\bin;

`  `ClassPath-->.;%javahome%\lib\dt.jar;%javahome%\lib\tools.jar

**2、eclipse安装**

地址:[https://www.eclipse.org/downloads/ ](https://www.eclipse.org/downloads/)

**3、selenium下载![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.005.png)**

地址:[https://www.seleniumhq.org/download/ ](https://www.seleniumhq.org/download/)Demo:

```java
System.setProperty("webdriver.chrome.driver", "C:/Program Files (x86)/Google/Chrome/chromedriver.exe");

WebDriver driver  = new ChromeDriver();

driver.get("http://www.baidu.com");
```



## **第3课 操作不同浏览器(IE、火狐、谷歌)**

 1、谷歌国内下载源<http://npm.taobao.org/mirrors/chromedriver/>

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.006.png)

测试代码:

驱动镜像地址: 火狐[https://npm.taobao.org/mirrors/geckodriver/ ](https://npm.taobao.org/mirrors/geckodriver/)[https://npm.taobao.org/mirrors/chromedriver/ ](https://npm.taobao.org/mirrors/chromedriver/)System.setProperty("webdriver.chrome.driver", "../chromedriver.exe");

WebDriver driver  = new ChromeDriver(); System.setProperty("webdriver.gecko.driver", "../geckodriver.exe") 注意事项:1 ) 驱动路径写全

`                 `2）路径表示方法

`        `3）参数全部为小写

**第4课 元素定位**

美团登录:[https://passport.meituan.com/account/unitivelogin? ](https://passport.meituan.com/account/unitivelogin)id、name、*className*、linkText、partialLinkText、tagName、css、xpath classname:可以部分属性进行定位 <https://www.w3school.com.cn/cssref/css_selectors.asp>

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.007.png)

注意点:class含空格 定位方式 css,xpath

**第5课 常用方法一**

1、sendKeys 、click、getAttribute、clear、isDisplayed、isSelected Thread.sleep休眠

**第6课 常用方法二**

maximize、getText、getWindowHandle、 getCurrentUrl、quit、back、forward close:关闭当前窗口

quit：退出并关闭所有窗口

Set h =driver.getWindowHandles();

`   `for (String han :h) {

`    `System.out.println(han);

`    `Thread.sleep(1000);

`    `if(han!=hand1) {

`     `driver.switchTo().window(han);

`         `}      }![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.008.png)

**第7课 悬停**

Actions  action = new Actions(driver); action.clickAndHold().perform() clickAndHold、moveToElement

**第8课 下拉框**

直接法:

driver.findElement(By.xpath("//\*[@id="nr"]/option[2]")).click(); Select

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.009.png)

` `Select s = new Select(driver.findElement(By.xpath("//\*[@id="nr"]")));    s.selectByIndex(1);

`   `s.selectByValue("50");

`   `s.selectByVisibleText("每页显示50条");

**第9课 定位一组元素**

findElements

List r= driver.findElements(By.name("SL"));

for(int i=0 ;i<r.size();i++) {     Thread.sleep(1000);     r.get(i).click();

`   `}

**第10课 对frame操作**

switchTo().frame 跳出frame switchTo().defaultContent()

**第11课 附件上传一**

Input ->send\_keys

**第12课 附件上传二**

第三方工具

1）编写好脚本，打包成exe

2 )  selenium写好脚本 打开上传附件窗口

3） 通过java代码去执行exe文件 ControlFocus("打开", "","Edit1") WinWait("[CLASS:#32770]","",5) ControlSetText("打开", "", "Edit1", "D:\test.txt") Sleep(1000)

ControlClick("打开", "","Button1");

Runtime run = Runtime.getRuntime(); run.exec("D:\web\qq\_attach.exe");

**第13课 作业以及课程总结**

实现完整QQ邮箱发送带附件功能脚本邮件

**第二章 TestNg介绍![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.010.png)**

**第1课 TestNg介绍**

TestNG 是一个测试框架，其灵感来自 JUnit 和 NUnit 的，但引入了一些新的功能，使其功能更强大， 使用更方便。TestNG 是一个开源自动化测试框架;TestNG 表示下一代

testng官网:

Help-> insert new software ->work with 输入 <http://beust.com/eclipse>

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.011.jpeg)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.012.png)

**第2课 常用注解**

1).BeforeTest测试方法运行之前运行 (2).AfterTest 测试方法运行之后运行 (3).Parameters将参数传递给 @Test 方法 (4).Test 将类或方法标记为测试的一部分 Assert.assertEquals()![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.013.png)

**第3课 DataProvider介绍**

@DataProvider()

`    `public Object[][] user() {         return new Object[][]{                 {"tim", "123"},

`                `{"tim2", "1234"},                 {"tim3", "tim3"}         };

`    `}

` `@Test(dataProvider = "user")

`    `public void test\_01(String username, String password) {         System.out.println(username + "\_" + password);         Assert.assertEquals(username, password);

`    `}

**第4课 群组测试**

@Test(groups= {"smoke"})

**第5课 TestNg执行Selenium脚本**

(1)通过 run 执行 (2)通过 Testng.xml 执行

1、打开hao123,打开新窗口，判断新窗口是否打开 实际url:[https://tuijian.hao123.com/ ](https://tuijian.hao123.com/)练习:检查下拉框值

**第6课 并发测试**

1）driver改写 2） 多线程

<suite name="test" parallel="tests" thread-count="2">![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.014.png)

**第7课 课程总结**

**第三章 项目实战![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.015.png)**

**第1课 需求分析**

1）项目介绍 [https://trains.ctrip.com/TrainBooking/SearchTrain.aspx### ](https://trains.ctrip.com/TrainBooking/SearchTrain.aspx###)2）功能分析

3）检查点

**第2课 js/jquery用法**

1)控制台通过js执行 2）代码执行

` `JavascriptExecutor js = (JavascriptExecutor) driver;

`        `//js.executeScript("document.getElementById('kw').value=''Test");         //js.executeScript("$('#kw').val('selenium')");

**第3课 登录滑块操作**

注册:<https://passport.ctrip.com/user/reg/home>

Actions action =new Actions(driver);

action.dragAndDropBy(sour, ele.getSize().getWidth(), -ele.getSize().getHeight()).perform();

**第4课 日期操作**

1 ) 直接去除属性 2）js强制改写

**第5课 功能实现练习 第6章 模糊定位**

"//input[starts-with(@id,'')] "//input[ends-with(@id,'')] "//input[  (@id,' ')]")

**第四章 函数![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.003.png)**

**第1课 函数介绍**

函数-函数是具备特定功能的一段代码块，解决了重复性代码的问题 例:public static int sum (int a,int b){

return a+b;

}

**第2课 参数拼接**

driver.manage().timeouts().implicitlyWait(20, TimeUnit.SECONDS); //div[contains(@id,'tbody-01-"+no+"')]

**第3课 函数封装**

封装车次查询

**第4课 异常**

try{

`    `int t =1/0;

`   `}

`   `catch(Exception e){

}![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.016.png)

**第5课 登录Cookie**

1）百度网盘登录

` `Set coo = driver.manage().getCookies();

**第6课 图像识别处理验证码**

1）第三方平台  斐斐

步骤： 1） 登录

`      `2） 注册

`             `3） 充值

`             `4） 根据验证码选取类型   demo   pd\_id、pd\_key      5） 验证码返回参数：resp.pred\_resl

**第7课 元素截图封装**

1） 截整个图片

File file = ((TakesScreenshot)driver).getScreenshotAs(OutputType.FILE); 2） 裁切

**第8课 重构登录**

` `1 ) 元素截图 + 图像识别   2） 完整的登录

**第五章 文件以及数据驱动![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.017.png)**

**第1课 文本文件**

写文件、读文件

FileWriter  BufferedWriter InputStreamReader

**第2课 Excel**

Execl: jxl  不支持 xlsx  poi       支持

从0开始计数 sheet.getLastRowNum() 从1开始计数 sheet.getRow(0).getLastCellNum() 读取单元格 sheet.getRow(row).getCell() 写Excel操作:

FileOutputStream  file = new FileOutputStream("selenium.xlsx");    XSSFWorkbook  workbook = new XSSFWorkbook ();

XSSFSheet sheet = workbook.createSheet(); XSSFRow row;![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.018.png)

XSSFCell cell;

row = sheet.createRow(0);

cell = row.createCell(0); cell.setCellValue("自动化测试");

读EXCEL函数 :每一列  存储到一个数组里 map

**第3课 Json**

json对象：key value json数组：包含多个对象

**第六章 数据驱动框架![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.019.png)**

**第1课 数据驱动概念**

参数与脚本要分离 目标：先对页面元素进行封装    方法：train\_serach

参数要与脚本进行分离， 文件   excel ,json，外部文件里。 参数化

类型 ；WebElement

页面元素封装成多个方法 车次查询

公共方法 查询方法 测试脚本

**第2课 项目重构 第3 课 findby**

1) findby
1) PageFactory

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.020.png)

右击src--build path--use as source folder

remove source folder

**第七章 测试报告![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.021.png)**

**第1课 TestNg重构框架**

1、自动化用例设计

1) TrainBooking/Search.aspx?
1) InputPassengers.aspx?

2、增加断言

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.022.png)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.023.jpeg)

**第2课 reportNg**

1） 引入reportNg包，eclipse 设置reportng 监听org.uncommons.reportng.HTMLReporter

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.024.jpeg)

2） 通过xml运行

**第八课 PO设计模式![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.025.png)**

**第1课 类**

它描述一类对象的行为和状态 get用于取得属性的值，set用于给属性赋值 this调用本类中的属性，也就是类中的成员变量； super（参数）：调用父类中的某一个构造函数

**super**(driver); 在子类的构造方法中，只要里面没有显示的通过super去调用父类相应的构造方法，默 认都是调用super()

set、get 这两个方法是对数据进行设置和获取用的

**第2课 PageObject 一**

What is POM?

`    `Page Object Model is a design pattern to create Object Repository for web UI elements.

`   `Under this model, for each web page in the application, there should be corresponding page class.

`   `This Page class will find the WebElements of that web page and also contains Page methods which perform operations on those WebElements.

`   `Name of these methods should be given as per the task they are performing, i.e., if a loader is waiting for the payment gateway to appear, POM method name can be waitForPaymentScreenDisplay().

优点：

Advantages of POM

1\.Page Object Patten says operations and flows in the UI should be separated from verification. This concept makes our code cleaner and easy to understand.

2\.The Second benefit is the object repository is independent of test cases, so we can use the same object repository for a different purpose with different tools. For example, we can integrate POM with TestNG/JUnit for functional Testing and at the same time with JBehave/Cucumber for acceptance testing.

3\.Code becomes less and optimized because of the reusable page methods in the POM classes.Methods get more realistic names which can be easily mapped with the operation happening in UI. i.e. if after clicking on the button we land on the home page, the method name will be like 'gotoHomePage()'.

Base:封装底层方法

public class Anmail {

`  `int age;

`  `public  void setAge(int age) {

`   `this.age =age;

`  `}

`   `public int getAge() {

`    `return age;

`   `}

`   `public void eat() {

`    `System.out.println("have something");    }

}

class Bird extends Anmail{

`  `String name;

`  `String color;

`  `public void setName(String name) {    this.name =name;

`  `}

`  `public String getName() {

`   `return name;

`  `}

`  `public void setColor(String color) {    this.color =color;

`  `}

`  `public String getColor() {

`   `return color;   }

}

Bird b = new Bird();

`   `b.setAge(18);

`   `b.setColor("red");

`   `b.getAge();

`   `System.out.println(b.getAge());    System.out.println(b.getColor());

**第3课 PageObject 二**

public WebElement findEle(By by) {

`   `return  this.driver.findElement(by);   }

public String  Search(String lea,String arr) thr    findEle(leave).sendKeys(lea);

`   `findEle(arrive).sendKeys(lea);

`   `findEle(current).click();

`   `return this.currentUrl();

`  `}

ows InterruptedException {

**第九章 Maven![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.026.png)**

**第1课 Maven环境搭建**

安装apache-maven [http://maven.apache.org/download.cgi ](http://maven.apache.org/download.cgi)Maven\_HOME,PATH;cmd下mvn -v

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.027.png)

阿里源：

` `alimaven 

` `aliyun maven 

` `[http://maven.aliyun.com/nexus/content/groups/public/ ](http://maven.aliyun.com/nexus/content/groups/public/) central     

库 <http://mvnrepository.com/>

本地库

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.028.png)

eclipse配置settings文件

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.029.png)

GroupID 是项目组织唯一的标识符，实际对应JAVA的包的结构。 ArtifactID是项目的唯一的标识符，实际对应项目的名称

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.030.png)

增加rescource文件夹，

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.031.png)

选择resources便可

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.032.png)

创建项目时选“New"->Maven Module ->(项目包含resource文件夹)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.033.png)

添加依赖:

`            `org.seleniumhq.selenium             selenium-java

`            `3.14.0

`            `org.testng             testng

`            `6.14.3

`            `test

异常:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.034.png)

pom.xml文件加入:

`    `<project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>     <maven.compiler.source>1.8</maven.compiler.source>     <maven.compiler.target>1.8</maven.compiler.target>

执行成功

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.035.png)

常用maven命令:

mvn clean 清理（删除target目录下编译内容） mvn compile 编译项目mvn package 打包发布 test       test case junit/testNG

install    把项目install到local repo

deploy    发本地jar发布到remote

右键选中工程，选择Maven-Update Project cmd->项目工程 mvn test

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.036.png)

**第2课 Maven构建项目**

项目用maven重构 mvn test执行项目

**第3课 logback**

日志级别：DEBUG < INFO < WARN < ERROR 项目增加日志:

final static Logger logger = LoggerFactory.getLogger("LogTest.class");   public static void main(String[] args) {

`   `logger.trace("trace");![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.037.png)

`   `logger.debug("debug str");   logger.info("info str");

`  `logger.warn("warn");

`  `logger.error("error");

`   `}

maven依赖:     org.slf4j     slf4j-api     1.7.25

`    `ch.qos.logback     logback-core

`    `1.1.11

`    `ch.qos.logback     logback-classic     1.1.11

配置文件

**第十章 平台搭建![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.026.png)**

**第1课 搭建平台优势**

1、账号管理 2、集成不同的环境 3、存储每次执行结果 4、发邮件 5、定时执行

......

**第2课 配置环境**

源码管理工具:svn或git jenkins 下载相应版本:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.038.jpeg)

安装

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.039.png)

主页访问：[http://localhost:8080/ ](http://localhost:8080/)初始化：等待10几分钟（与电脑配置也有关系）

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.040.jpeg)

输入秘钥:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.041.jpeg)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.042.png)

选择插件:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.043.jpeg)

推荐的插件

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.044.jpeg)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.045.jpeg)

安装TestNg插件

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.046.png)

构建job:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.047.jpeg)

邮件:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.048.png)

获取授权码:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.049.png)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.050.png)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.051.jpeg)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.052.png)

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.053.png)

**第3课 项目构建**

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.054.png)

H(28-30)09,21\*\*\*

**Poll SCM**：定时检查源码变更（根据SCM软件的版本号），如果有更新就checkout最新code下来，然 后执行构建动作。我的配置如下：

H/15 \* \* \* \* （每15分钟检查一次源码变化）

**Build periodically**：周期进行项目构建（它不care源码是否发生变化），我的配置如下：

0 9 \* \* \* （每天9:00 必须build一次源码）

mvn test执行test目录下文件 pom.xml增加maven插件

之前增加

`                `org.apache.maven.plugins                 maven-surefire-plugin

`                `2.4.3

`         `<suiteXmlFiles>![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.055.png)

`           `<!--代表的是要执行的测试套件名称-->

`           `<suiteXmlFile>testng.xml</suiteXmlFile>          </suiteXmlFiles>

</configuration>

</plugin> </plugins> </build>![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.056.png)

执行命令:mvn clean install

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.057.png)

jenkins配置:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.058.png)

注意: 用命令执行报告存放在target\surefire-reports 目录下

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.059.png)

异常处理:

![](Aspose.Words.cc198325-1825-4855-9d23-26d349be048d.060.png)

课程答疑作者:QQ:2574674466
