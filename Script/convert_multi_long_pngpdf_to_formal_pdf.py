#!/usr/bin/env python3
"""
智能PDF合并脚本
- 第一个参数：输入路径（目录或单个 .pdf/.png 文件）
- 自动识别 PDF 和图片，长图按 Letter 纸比例分割
- 按顺序合并为单个 PDF 文件
"""

import os
import sys
import glob
import tempfile
import shutil
from pypdf import PdfWriter, PdfReader
from PIL import Image
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch

# 支持的图片格式
IMAGE_EXTENSIONS = ['.png', '.jpg', '.jpeg', '.gif', '.bmp', '.tiff']

def is_image_file(filename):
    """检查文件是否为图片"""
    ext = os.path.splitext(filename)[1].lower()
    return ext in IMAGE_EXTENSIONS

def is_pdf_file(filename):
    """检查文件是否为PDF"""
    return os.path.splitext(filename)[1].lower() == '.pdf'

def split_long_image_to_pdfs(image_path, output_dir, base_name):
    """
    将长图片分割成多个Letter纸比例的PDF
    
    参数:
        image_path: 图片文件路径
        output_dir: 输出目录
        base_name: 基础文件名（不含扩展名）
    
    返回:
        生成的PDF文件路径列表
    """
    print(f"  处理图片: {os.path.basename(image_path)}")
    
    try:
        # 读取图片
        img = Image.open(image_path)
        img_width, img_height = img.size
        
        # 计算按Letter纸比例的分割高度
        letter_ratio = 11.0 / 8.5
        segment_height = int(img_width * letter_ratio)
        
        # 计算需要分割成多少段
        num_segments = (img_height + segment_height - 1) // segment_height
        
        print(f"    图片尺寸: {img_width} x {img_height} 像素")
        print(f"    将分割为 {num_segments} 个PDF")
        
        output_files = []
        
        # 分割图片并生成PDF
        for i in range(num_segments):
            # 计算裁剪区域
            top = i * segment_height
            bottom = min((i + 1) * segment_height, img_height)
            actual_height = bottom - top
            
            # 裁剪图片
            cropped_img = img.crop((0, top, img_width, bottom))
            
            # 生成输出文件名
            if num_segments == 1:
                output_file = os.path.join(output_dir, f"{base_name}.pdf")
            else:
                output_file = os.path.join(output_dir, f"{base_name}-{i+1}.pdf")
            
            # 创建PDF - 使用标准Letter纸尺寸
            pdf_width = 8.5 * inch
            pdf_height = 11 * inch
            
            c = canvas.Canvas(output_file, pagesize=(pdf_width, pdf_height))
            
            # 保存为临时图片文件
            with tempfile.NamedTemporaryFile(suffix='.png', delete=False) as tmp:
                temp_img_file = tmp.name
                cropped_img.save(temp_img_file, "PNG")
            
            # 计算图片在PDF中的实际尺寸（保持宽高比）
            img_display_width = pdf_width
            img_display_height = (actual_height / img_width) * pdf_width
            
            # 如果图片高度超过页面，按高度缩放
            if img_display_height > pdf_height:
                img_display_height = pdf_height
                img_display_width = (img_width / actual_height) * pdf_height
            
            # 居中放置图片
            x_offset = (pdf_width - img_display_width) / 2
            y_offset = (pdf_height - img_display_height) / 2
            
            # 将图片绘制到PDF上
            c.drawImage(temp_img_file, x_offset, y_offset, 
                       width=img_display_width, height=img_display_height)
            c.save()
            
            # 删除临时文件
            os.remove(temp_img_file)
            
            output_files.append(output_file)
        
        return output_files
        
    except Exception as e:
        print(f"    错误: 处理图片时出错 - {e}")
        return []

def process_files(input_path, output_name, prefix=None):
    """
    主处理函数：识别文件类型，转换图片，合并PDF
    
    参数:
        input_path: 输入路径，可为目录（处理该目录下所有 pdf/图片）或单个 pdf/png 文件路径
        output_name: 输出PDF文件名
        prefix: 文件名前缀过滤器（仅当 input_path 为目录时有效）
    """
    input_path = os.path.abspath(os.path.expanduser(input_path))
    if not os.path.exists(input_path):
        print(f"错误: 路径不存在 - {input_path}")
        return

    # 确定源文件列表与输出目录
    if os.path.isfile(input_path):
        if is_pdf_file(input_path) or is_image_file(input_path):
            target_files = [input_path]
            current_dir = os.path.dirname(input_path)
        else:
            print(f"错误: 不支持的文件类型，请使用 PDF 或图片 (png/jpg 等) - {input_path}")
            return
    else:
        current_dir = input_path
        if prefix:
            pattern = os.path.join(current_dir, f"{prefix}*.*")
        else:
            pattern = os.path.join(current_dir, "*.*")
        all_files = glob.glob(pattern)
        target_files = []
        for f in all_files:
            basename = os.path.basename(f)
            if basename.endswith('.py') or basename.startswith('temp_') or basename.endswith('_split.pdf'):
                continue
            if is_pdf_file(f) or is_image_file(f):
                target_files.append(f)

    # 创建临时目录用于存放转换后的PDF
    temp_dir = tempfile.mkdtemp()

    try:
        # 按文件名排序
        target_files.sort()
        
        if not target_files:
            print(f"未找到匹配的文件 (前缀: {prefix or '无'})")
            return
        
        print(f"\n找到 {len(target_files)} 个文件:")
        for i, f in enumerate(target_files, 1):
            file_type = "PDF" if is_pdf_file(f) else "图片"
            print(f"  {i}. {os.path.basename(f)} [{file_type}]")
        
        print(f"\n开始处理文件...")
        
        # 处理每个文件，生成PDF列表
        pdf_files = []
        
        for file_path in target_files:
            base_name = os.path.splitext(os.path.basename(file_path))[0]
            
            if is_pdf_file(file_path):
                # 如果是PDF，直接使用
                print(f"  添加PDF: {os.path.basename(file_path)}")
                pdf_files.append(file_path)
                
            elif is_image_file(file_path):
                # 如果是图片，分割成PDF
                converted_pdfs = split_long_image_to_pdfs(file_path, temp_dir, base_name)
                pdf_files.extend(converted_pdfs)
        
        if not pdf_files:
            print("没有PDF文件可以合并")
            return
        
        # 合并所有PDF
        print(f"\n开始合并 {len(pdf_files)} 个PDF文件...")
        writer = PdfWriter()
        
        for pdf_file in pdf_files:
            try:
                reader = PdfReader(pdf_file)
                for page in reader.pages:
                    writer.add_page(page)
                print(f"  已添加: {os.path.basename(pdf_file)}")
            except Exception as e:
                print(f"  错误: 添加 {os.path.basename(pdf_file)} 时出错 - {e}")
        
        # 输出合并后的文件
        if output_name:
            if not output_name.endswith('.pdf'):
                output_name += '.pdf'
            output_file = os.path.join(current_dir, output_name)
        else:
            output_file = os.path.join(current_dir, "merged_output.pdf")
        
        try:
            with open(output_file, "wb") as f:
                writer.write(f)
            print(f"\n✅ 成功！合并后的PDF已保存为: {os.path.basename(output_file)}")
            print(f"   文件位置: {output_file}")
        except Exception as e:
            print(f"保存文件时出错: {e}")
    
    finally:
        # 清理临时目录
        try:
            shutil.rmtree(temp_dir)
        except:
            pass

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("使用方法: python3 mergepy.py <输入路径> <输出文件名> [前缀过滤器]")
        print("\n  输入路径: 目录（处理该目录下所有 pdf/图片）或单个 .pdf / .png 文件路径")
        print("\n示例:")
        print("  python3 mergepy.py ./Module\\ 1 merged.pdf")
        print("    - 合并该目录下所有 PDF 和图片")
        print("  python3 mergepy.py ./Module\\ 1 1b_merged.pdf 1b")
        print("    - 只合并以 '1b' 开头的 PDF 和图片")
        print("  python3 mergepy.py /path/to/single.png out.pdf")
        print("    - 将单个图片转为 PDF 并保存为 out.pdf")
        sys.exit(1)

    input_path = sys.argv[1]
    output_name = sys.argv[2]
    prefix = sys.argv[3] if len(sys.argv) > 3 else None

    process_files(input_path, output_name, prefix)
