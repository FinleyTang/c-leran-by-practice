cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(CTutorPractice)

# 设置C标准
set(CMAKE_C_STANDARD 11)

# 包含头文件目录
include_directories(include)

# 查找所有子目录
file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/*)

# 为每个子目录创建可执行文件
foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/src/${SUBDIR})
        add_executable(${SUBDIR} src/${SUBDIR}/main.c)
    endif()
endforeach()
