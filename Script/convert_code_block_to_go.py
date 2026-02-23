import re
import os
import sys

def convert_code_block_to_go(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    code_block_pattern = re.compile(r'```(\w+)?\n(.*?)```', re.DOTALL)

    def replace_code_block(match):
        language = match.group(1)
        code = match.group(2).strip()

        if language == 'ascii':
            return match.group(0)

        return f'```go\n{code}\n```'

    updated_content = re.sub(code_block_pattern, replace_code_block, content)

    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(updated_content)

    print(f"✅ 已将所有代码块转换为 Go 格式: {file_path}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("❌ 用法: python convert_code_block_to_go.py <文件路径或目录路径>")
        sys.exit(1)

    input_path = sys.argv[1]

    if os.path.isfile(input_path):
        convert_code_block_to_go(input_path)
    elif os.path.isdir(input_path):
        md_files = [
            os.path.join(root, file)
            for root, _, files in os.walk(input_path)
            for file in files
            if file.endswith('.md')
        ]
        if not md_files:
            print(f"⚠️  目录下未找到任何 .md 文件: {input_path}")
            sys.exit(0)
        print(f"📁 共找到 {len(md_files)} 个 .md 文件，开始处理...\n")
        for md_file in md_files:
            convert_code_block_to_go(md_file)
        print(f"\n🎉 全部处理完成，共处理 {len(md_files)} 个文件。")
    else:
        print(f"❌ 路径不存在: {input_path}")
        sys.exit(1)
