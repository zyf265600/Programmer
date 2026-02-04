import os
import re

def process_md_file(filepath):
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"❌ 读取文件失败: {filepath}, 错误：{e}")
        return

    # ============ 0. 删除所有的 java 🟢cpp 🤖python 🤖go 🤖javascript 🤖 ============
    content = content.replace("java 🟢cpp 🤖python 🤖go 🤖javascript 🤖", "")
    content = content.replace("javacpppythongojavascript", "")

    # ============ 1. 删除 <details ... </details> 之间所有内容（包含标签本身） ============
    #   - 使用 DOTALL 模式，让 '.' 能匹配换行
    content = re.sub(r'<details.*?</details>', '', content, flags=re.DOTALL)

    # ============ 2. 保留中括号内文字，删除括号与链接部分 (只匹配以 https 开头的链接) ============
    #   - 之前脚本是替换为 [\1]，现在改为 \1，去掉外部方括号
    content = re.sub(r'\[([^\]]+)\]\(https[^\)]*\)', r'\1', content)

    # ============ 3. 原有功能：将单独的 ``` 替换为 ```go ============
    #   - 这里我们需要行级处理，因为要判断 code block 的开合
    lines = content.splitlines(keepends=True)
    new_lines = []
    inside_code_block = False

    for line in lines:
        stripped = line.strip()
        if stripped.startswith("```") and not inside_code_block:
            # 遇到开头的 ```
            if stripped == "```":
                new_lines.append("```go\n")
            else:
                # 保持原有可能存在的语言标记，如 ```go 之类
                new_lines.append(line)
            inside_code_block = True
        elif stripped.startswith("```") and inside_code_block:
            # 遇到结尾的 ```
            new_lines.append(line)
            inside_code_block = False
        else:
            new_lines.append(line)

    # 最终写回文件
    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.writelines(new_lines)
        print(f"✅ 已处理: {filepath}")
    except Exception as e:
        print(f"❌ 写入文件失败: {filepath}, 错误：{e}")

# ============ 使用示例 ============
if __name__ == "__main__":
    file_path = "../Leetcode/Data_Structure/25二叉树拓展：最近公共祖先系列解题框架.md"
    if not os.path.isfile(file_path):
        print(f"❌ 文件不存在: {file_path}")
    else:
        process_md_file(file_path)
