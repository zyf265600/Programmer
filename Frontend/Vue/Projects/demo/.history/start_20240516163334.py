import os
import subprocess
import sys

def run_command(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    while True:
        output = process.stdout.readline()
        if process.poll() is not None and output == b'':
            break
        if output:
            print(output.strip().decode())
    rc = process.poll()
    return rc

def main():
    # 确定项目路径
    project_path = os.path.abspath(os.path.dirname(__file__))
    
    # 打印项目路径
    print(f"项目路径: {project_path}")
    
    # 检查 package.json 是否存在
    package_json_path = os.path.join(project_path, 'package.json')
    if not os.path.exists(package_json_path):
        print("package.json 文件未找到，请确认你在项目根目录中运行此脚本。")
        sys.exit(1)

    # 安装依赖
    print("正在安装依赖...")
    if run_command("npm install") != 0:
        print("依赖安装失败，请检查错误信息。")
        sys.exit(1)

    # 启动开发服务器
    print("正在启动开发服务器...")
    if run_command("npm run dev") != 0:
        print("开发服务器启动失败，请检查错误信息。")
        sys.exit(1)

if __name__ == "__main__":
    main()