# fileName = r'/Users/zyf/Desktop/Programmer/Frontend/Vue/Official_Doc/v2.cn.vuejs.org-master/src/v2/guide/syntax.md'
# with open(file=fileName, mode="r", encoding='utf-8') as f1:
#     lines = f1.readlines()
#     for i in range(0, len(lines)):
#         if lines[i][0] == '#':
#             lines[i] = '#' + lines[i]

# #将处理过的lines写入新的文件中
# fileName2 = r'/Users/zyf/Desktop/Programmer/Frontend/Vue/Official_Doc/v2.cn.vuejs.org-master/src/v2/guide/syntax.md'
# with open(file = fileName2,mode='w',encoding='utf-8') as f2:
#     f2.writelines(lines)

import os
import glob

# 定义文件夹路径
folder_path = r'/Users/zyf/Desktop/a'

# 获取文件夹中所有的 .md 文件
md_files = glob.glob(os.path.join(folder_path, '*.md'))

# 遍历每个 .md 文件
for file_path in md_files:
    # 读取文件内容
    with open(file=file_path, mode="r", encoding='utf-8') as f:
        lines = f.readlines()
        for i in range(len(lines)):
            if lines[i].startswith('#'):
                lines[i] = '#' + lines[i]

    # 写回处理后的内容
    with open(file=file_path, mode='w', encoding='utf-8') as f:
        f.writelines(lines)