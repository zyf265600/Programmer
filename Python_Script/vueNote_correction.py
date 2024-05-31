import os
import glob

# 定义要处理的文件夹路径
folder_path = r'/Users/zyf/Desktop/a'  # 请将此路径替换为实际文件夹路径

# 获取文件夹中所有的 .md 文件
md_files = glob.glob(os.path.join(folder_path, '*.md'))

# 遍历每个 .md 文件
for file_path in md_files:
    # 读取文件内容
    with open(file=file_path, mode="r", encoding='utf-8') as f:
        content = f.read()
    
    # 替换所有的 '<p class="tip">'
    new_content = content.replace('<div class="composition-api">', '')

    # 写回处理后的内容
    with open(file=file_path, mode='w', encoding='utf-8') as f:
        f.write(new_content)

print("处理完成")