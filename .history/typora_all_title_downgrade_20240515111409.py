fileName = r'/Users/zyf/Desktop/Programmer/Frontend/Vue/'
with open(file=fileName, mode="r", encoding='utf-8') as f1:
    lines = f1.readlines()
    for i in range(0, len(lines)):
        if lines[i][0] == '#':
            lines[i] = '#' + lines[i]

#将处理过的lines写入新的文件中
fileName2 = r'F:\md笔记\java\file-修改.md'
with open(file = fileName2,mode='w',encoding='utf-8') as f2:
    f2.writelines(lines)