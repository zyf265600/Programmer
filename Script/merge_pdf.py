#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
PDF合并脚本
功能：将指定目录下的所有PDF文件按照文件名排序后合并为一个PDF文件
"""

import os
import sys
import re
from pathlib import Path

try:
    from pypdf import PdfWriter, PdfReader
    USE_PYPDF = True
except ImportError:
    try:
        from PyPDF2 import PdfMerger
        USE_PYPDF = False
    except ImportError:
        print("❌ 错误：未安装PDF处理库")
        print("💡 请运行以下命令安装：")
        print("   pip install pypdf")
        print("   或")
        print("   pip install PyPDF2")
        sys.exit(1)


def natural_sort_key(filename):
    """
    自然排序的key函数
    将文件名中的数字部分转换为整数进行排序
    例如: file1.pdf, file2.pdf, file10.pdf
    """
    def convert(text):
        return int(text) if text.isdigit() else text.lower()
    
    return [convert(c) for c in re.split('([0-9]+)', filename)]


def find_pdf_files(directory, recursive=False):
    """
    在指定目录中查找所有PDF文件
    
    Args:
        directory: 目录路径
        recursive: 是否递归扫描子目录
    
    Returns:
        按自然排序的PDF文件路径列表
    """
    pdf_files = []
    
    if recursive:
        # 递归扫描所有子目录
        for root, dirs, files in os.walk(directory):
            for file in files:
                if file.lower().endswith('.pdf'):
                    pdf_files.append(os.path.join(root, file))
    else:
        # 只扫描当前目录
        for file in os.listdir(directory):
            filepath = os.path.join(directory, file)
            if os.path.isfile(filepath) and file.lower().endswith('.pdf'):
                pdf_files.append(filepath)
    
    # 按文件名自然排序
    pdf_files.sort(key=lambda x: natural_sort_key(os.path.basename(x)))
    
    return pdf_files


def merge_pdfs(pdf_files, output_path, show_progress=True):
    """
    合并多个PDF文件
    
    Args:
        pdf_files: PDF文件路径列表
        output_path: 输出文件路径
        show_progress: 是否显示进度
    """
    print(f"\n📄 开始合并 {len(pdf_files)} 个PDF文件...")
    print("=" * 60)
    
    if USE_PYPDF:
        # 使用 pypdf 库
        writer = PdfWriter()
        
        for idx, pdf_file in enumerate(pdf_files, 1):
            try:
                if show_progress:
                    print(f"[{idx}/{len(pdf_files)}] 正在添加: {os.path.basename(pdf_file)}")
                reader = PdfReader(pdf_file)
                for page in reader.pages:
                    writer.add_page(page)
            except Exception as e:
                print(f"⚠️  警告：无法读取文件 {os.path.basename(pdf_file)}: {e}")
                continue
        
        print("=" * 60)
        print(f"💾 正在保存合并后的PDF...")
        
        try:
            with open(output_path, 'wb') as output_file:
                writer.write(output_file)
            print(f"✅ 合并完成！输出文件: {output_path}")
        except Exception as e:
            print(f"❌ 保存文件失败: {e}")
            sys.exit(1)
    else:
        # 使用 PyPDF2 库
        merger = PdfMerger()
        
        for idx, pdf_file in enumerate(pdf_files, 1):
            try:
                if show_progress:
                    print(f"[{idx}/{len(pdf_files)}] 正在添加: {os.path.basename(pdf_file)}")
                merger.append(pdf_file)
            except Exception as e:
                print(f"⚠️  警告：无法读取文件 {os.path.basename(pdf_file)}: {e}")
                continue
        
        print("=" * 60)
        print(f"💾 正在保存合并后的PDF...")
        
        try:
            merger.write(output_path)
            merger.close()
            print(f"✅ 合并完成！输出文件: {output_path}")
        except Exception as e:
            print(f"❌ 保存文件失败: {e}")
            sys.exit(1)
    
    # 显示文件大小
    file_size = os.path.getsize(output_path)
    if file_size < 1024 * 1024:
        size_str = f"{file_size / 1024:.2f} KB"
    else:
        size_str = f"{file_size / (1024 * 1024):.2f} MB"
    print(f"📊 文件大小: {size_str}")


def main():
    """主函数"""
    # 解析命令行参数
    if len(sys.argv) < 2:
        print("❌ 用法: python merge_pdf.py <输入目录> [选项]")
        print("\n选项:")
        print("  -o, --output <文件名>    指定输出文件名 (默认: merged_output.pdf)")
        print("  -r, --recursive          递归扫描子目录")
        print("  -q, --quiet              静默模式，不显示进度")
        print("\n示例:")
        print("  python merge_pdf.py /path/to/pdfs")
        print("  python merge_pdf.py /path/to/pdfs -o result.pdf")
        print("  python merge_pdf.py /path/to/pdfs -r -o result.pdf")
        sys.exit(1)
    
    input_dir = sys.argv[1]
    
    # 检查目录是否存在
    if not os.path.isdir(input_dir):
        print(f"❌ 错误：目录不存在: {input_dir}")
        sys.exit(1)
    
    # 解析可选参数
    output_filename = "merged_output.pdf"
    recursive = False
    show_progress = True
    
    i = 2
    while i < len(sys.argv):
        arg = sys.argv[i]
        if arg in ['-o', '--output']:
            if i + 1 < len(sys.argv):
                output_filename = sys.argv[i + 1]
                i += 2
            else:
                print("❌ 错误：-o/--output 需要指定文件名")
                sys.exit(1)
        elif arg in ['-r', '--recursive']:
            recursive = True
            i += 1
        elif arg in ['-q', '--quiet']:
            show_progress = False
            i += 1
        else:
            print(f"❌ 错误：未知参数 {arg}")
            sys.exit(1)
    
    # 确保输出文件名以.pdf结尾
    if not output_filename.lower().endswith('.pdf'):
        output_filename += '.pdf'
    
    # 构建输出路径
    output_path = os.path.join(input_dir, output_filename)
    
    # 检查输出文件是否已存在
    if os.path.exists(output_path):
        response = input(f"⚠️  文件 {output_filename} 已存在，是否覆盖? (y/n): ")
        if response.lower() not in ['y', 'yes', '是']:
            print("❌ 操作已取消")
            sys.exit(0)
    
    # 查找PDF文件
    print(f"🔍 正在扫描目录: {input_dir}")
    if recursive:
        print("📂 递归模式：将扫描所有子目录")
    
    pdf_files = find_pdf_files(input_dir, recursive)
    
    if not pdf_files:
        print("❌ 错误：未找到任何PDF文件")
        sys.exit(1)
    
    print(f"✅ 找到 {len(pdf_files)} 个PDF文件")
    
    if show_progress:
        print("\n📋 文件列表（按排序顺序）:")
        for idx, pdf in enumerate(pdf_files, 1):
            print(f"  {idx}. {os.path.basename(pdf)}")
    
    # 合并PDF
    merge_pdfs(pdf_files, output_path, show_progress)


if __name__ == "__main__":
    main()
