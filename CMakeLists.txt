cmake_minimum_required(VERSION 3.20)

project(CppLearning CXX)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    # 设置编译器选项以使用 GBK 字符集输出
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finput-charset=UTF-8 -fexec-charset=GBK")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=GBK")
    endif()
    if(MSVC)
        add_compile_options("/source-charset:utf-8")
        add_compile_options("/execution-charset:GBK")
    endif()
endif()
if(LINUX)
    if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
    endif()
    if(MSVC)
        add_compile_options("/utf-8")
    endif()
endif()

add_subdirectory(src)