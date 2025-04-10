## [Python AI  绘画](https://www.runoob.com/python3/python-ai-draw.html)

[index](目录.md)

---
Python AI 绘画
============

本文我们将为大家介绍如何基于一些开源的库来搭建一套自己的 AI 作图工具。

需要使用的开源库为 Stable Diffusion web UI，它是基于 Gradio 库的 Stable Diffusion 浏览器界面

Stable Diffusion web UI GitHub 地址：
<https://github.com/AUTOMATIC1111/stable-diffusion-webui>

运行 Stable Diffusion 需要硬件要求比较高，运行时会消耗较大的资源，特别是显卡。

### Windows 环境安装

本地环境要求安装 Python 3.10.6 或以上版本，并把它加入到本机的环境变量中。

下载 Stable Diffusion web UI GitHub 源码
<https://github.com/AUTOMATIC1111/stable-diffusion-webui>
。

```
git clone https://github.com/AUTOMATIC1111/stable-diffusion-webui.git
```

如果没有安装 Git ，可以在右上角下载 zip 压缩包。

![](https://www.runoob.com/wp-content/uploads/2023/04/1d0b3880e9f246f3b50075f9dd874eb2.png)

解压 stable-diffusion-webui，并进入 stable-diffusion-webui 目录。

接下来我们需要下载模型，下载地址：
<https://huggingface.co/CompVis/stable-diffusion-v-1-4-original>

![](https://www.runoob.com/wp-content/uploads/2023/04/199a2c028c3fb22d9946391a845b1e93.png)

将下载的模型移动到
stable-diffusion-webui/models/Stable-diffusion
目录下。

进入 stable-diffusion-webui 目录：

Windows 使用非管理员运行:

```
webui-user.bat
```

Linux 和 Mac OS 环境执行以下命令：

```
./webui.sh
```

接下来程序就会自动安装并启动，启动成功会看到一个可访问的 URL 地址
http://127.0.0.1:7860
：

![](https://www.runoob.com/wp-content/uploads/2023/04/e3a349b8c5c122b17af780a0e3918872.png)

访问
http://127.0.0.1:7860
，界面如下：

![](https://www.runoob.com/wp-content/uploads/2023/04/94db8ed9769fee5a9d68e43ec4ba1d76-.png)

> **注意:**
> 如果安装出现卡住不动，很可能是下载 Github 源码出现问题了，可以使用 Github 的一些镜像来解决，目前还没非常稳定的镜像，建议 Google 搜索下。
> 我这边在 2023 年 4 月 6 号使用以下镜像地址
> https://hub.fgit.ml
> ，打开 stable-diffusion-webui 目录的 launch.py 文件，替换以下部分代码的 Github 地址（代码大概在 230～240 行之间）：
>
> ![](https://www.runoob.com/wp-content/uploads/2023/04/5fdfe36f22e6c09312860a789ce5fe70.png)

### Civitai 介绍

Civitai 有许多定制好的模型，而且可以免费下载，我们使用
**国风3**
模型来测试，下载地址：
<https://civitai.com/models/10415/3-guofeng3?modelVersionId=36644>

![](https://www.runoob.com/wp-content/uploads/2023/04/drawai-c-1.png)

下载完后，我们将模型移动到
stable-diffusion-webui/models/Stable-diffusion
目录下，重新启动 stable-diffusion-webui ：

```
./webui.sh
```

这样我们就可以在模型列表中选择
**国风3**
模型了：

![](https://www.runoob.com/wp-content/uploads/2023/04/e570bdeee6a5e36e0bc99078d3033a57.png)

选择后，我们可以到模型介绍页面去拷贝一些提示词和测试参数：

![](https://www.runoob.com/wp-content/uploads/2023/04/drawai-c-2.png)

![](https://www.runoob.com/wp-content/uploads/2023/04/drawai-c-3.png)

![](https://www.runoob.com/wp-content/uploads/2023/04/drawai-c-4.png)

​为了快速生成，我高度跟宽度都减半了，之后点生成按钮即可：

![](https://www.runoob.com/wp-content/uploads/2023/04/dcaaddda2a89ce2e0fb8443ae25823f9.png)

生成完整过程，可以关注我们微信视频号查看：

![](https://www.runoob.com/wp-content/uploads/2023/04/WechatIMG359.jpeg)