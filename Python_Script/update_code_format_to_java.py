import re

def set_code_format_to_java(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    # 使用正则表达式匹配代码块，捕获组包括起始标记、可选的语言标识符和代码内容
    code_block_pattern = re.compile(r'```(\w+)?\n(.*?)```', re.DOTALL)

    def replace_code_block(match):
        language = match.group(1)
        code = match.group(2).strip()

        # 如果语言标识符是ascii，跳过这段代码块
        if language == 'ascii':
            return match.group(0)

        return f'```java\n{code}\n```'

    updated_content = re.sub(code_block_pattern, replace_code_block, content)

    with open(file_path, 'w', encoding='utf-8') as file:
        file.write(updated_content)

    print(f"Converted all code blocks to Java format in {file_path}")

# Replace 'your_file.md' with the path to your Markdown file
set_code_format_to_java('/Users/zyf/Desktop/Programmer/Java/Java_Fundamental/Java_Fundamental.md')
