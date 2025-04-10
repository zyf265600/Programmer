cmake_minimum_required(VERSION 3.29)
project(cpp_template)

set(CMAKE_CXX_STANDARD 20)

# 收集公共代码
file(GLOB_RECURSE COMMON_SOURCES "leetcode/editor/common/*.cpp")

# 编译公共代码为库
add_library(common STATIC ${COMMON_SOURCES})

# 收集包含 main 函数的代码
file(GLOB_RECURSE MAIN_SOURCES "leetcode/editor/cn/*.cpp" "leetcode/editor/en/*.cpp")

# 为每个包含 main 函数的文件生成可执行文件
foreach(source_file ${MAIN_SOURCES})
    # 生成可执行文件名（确保唯一性）
    get_filename_component(target_name ${source_file} NAME_WE)  # 提取文件名（无扩展名）
    get_filename_component(dir ${source_file} DIRECTORY)        # 提取所在目录
    file(RELATIVE_PATH relative_dir ${CMAKE_SOURCE_DIR}/leetcode ${dir})
    string(REPLACE "/" "_" unique_prefix "${relative_dir}")     # 替换斜杠为下划线
    set(target_name "${unique_prefix}_${target_name}")          # 组合唯一目标名

    # 生成可执行文件并链接公共库
    add_executable(${target_name} ${source_file})
    target_link_libraries(${target_name} common)
endforeach()