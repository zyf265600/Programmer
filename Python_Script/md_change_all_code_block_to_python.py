import os

def process_md_file(filepath):
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except Exception as e:
        print(f"❌ 读取文件失败: {filepath}, 错误：{e}")
        return

    new_lines = []
    inside_code_block = False

    for line in lines:
        stripped = line.strip()
        if stripped.startswith("```") and not inside_code_block:
            if stripped == "```":
                new_lines.append("```python\n")
            else:
                new_lines.append(line)
            inside_code_block = True
        elif stripped.startswith("```") and inside_code_block:
            new_lines.append(line)
            inside_code_block = False
        else:
            new_lines.append(line)

    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.writelines(new_lines)
        print(f"✅ 已处理: {filepath}")
    except Exception as e:
        print(f"❌ 写入文件失败: {filepath}, 错误：{e}")

# ✅ 指定你要处理的 markdown 文件路径
# file_path = str(input("file_path: "))
file_path = "/Users/zyf/Desktop/Programmer/Leetcode/python_for_leetcode.md"

if not os.path.isfile(file_path):
    print(f"❌ 文件不存在: {file_path}")
else:
    process_md_file(file_path)
