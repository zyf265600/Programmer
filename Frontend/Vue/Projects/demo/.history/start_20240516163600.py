import os
import subprocess
import webbrowser
import time

def run_command(command):
    process = subprocess.Popen(command, shell=True)
    return process

def main():
    # 确定项目路径
    project_path = os.path.abspath(os.path.dirname(__file__))
    
    # 打印项目路径
    print(f"项目路径: {project_path}")
    
    # 检查 package.json 是否存在
    package_json_path = os.path.join(project_path, 'package.json')
    if not os.path.exists(package_json_path):
        print("package.json 文件未找到，请确认你在项目根目录中运行此脚本。")
        return

    # 启动开发服务器
    print("正在启动开发服务器...")
    process = run_command("npm run dev")

    # 等待开发服务器启动
    time.sleep(2)  # 等待 2 秒，确保服务器启动完成

    # 打开默认浏览器并访问指定端口
    url = "http://localhost:5173"  # 根据实际端口修改
    print(f"正在打开浏览器: {url}")
    webbrowser.open(url)


if __name__ == "__main__":
    main()
