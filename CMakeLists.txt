CMAKE_MINIMUM_REQUIRED(VERSION 3.4.0)

project(meta_core)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(meta_core
    src/class_info.cpp
    include/template_tool.h
)
target_include_directories(meta_core PRIVATE include)

add_executable(meta_core_test
    src/class_info.cpp
    src/test/main.cpp
    include/class_info.h
)
target_include_directories(meta_core_test PRIVATE include)



