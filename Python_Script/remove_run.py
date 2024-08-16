import re

def remove_exact_run_from_md(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.readlines()

    # 过滤掉只包含 "Run" 的行
    updated_content = [line for line in content if not re.match(r'^\s*Run\s*$', line)]

    with open(file_path, 'w', encoding='utf-8') as file:
        file.writelines(updated_content)

    print(f"Removed all lines containing only 'Run' from {file_path}")

# Replace 'your_file.md' with the path to your Markdown file
remove_exact_run_from_md('/Users/zyf/Desktop/Programmer/Java/Java_Fundamental/Java_Fundamental.md')
