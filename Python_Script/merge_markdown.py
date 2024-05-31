import os

def merge_markdown_files(folder_path, output_file):
    # 确保输出文件不存在
    if os.path.exists(output_file):
        os.remove(output_file)

    # 打开输出文件进行写操作
    with open(output_file, 'w', encoding='utf-8') as outfile:
        # 遍历文件夹中的所有文件
        for root, dirs, files in os.walk(folder_path):
            for file in files:
                # 检查文件扩展名是否为.md
                if file.endswith('.md'):
                    file_path = os.path.join(root, file)
                    with open(file_path, 'r', encoding='utf-8') as infile:
                        # 读取Markdown文件内容并写入输出文件
                        outfile.write(f"# {file}\n\n")  # 在合并文件中添加文件名作为标题
                        outfile.write(infile.read())
                        outfile.write("\n\n---\n\n")  # 添加分隔符

if __name__ == "__main__":
    folder_path = "/Users/zyf/Desktop/Programmer/Java/Java_Fundamental"  # 替换为你的Markdown文件夹路径
    output_file = "components.md"  # 指定输出文件的名称
    merge_markdown_files(folder_path, output_file)
    print(f"All markdown files in '{folder_path}' have been merged into '{output_file}'")