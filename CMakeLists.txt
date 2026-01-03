cmake_minimum_required(VERSION 4.2.1)

project(ExcelApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tắt build những thứ không cần của OpenXLSX
set(OPENXLSX_BUILD_SAMPLES OFF)
set(OPENXLSX_BUILD_TESTS OFF)
set(OPENXLSX_CREATE_DOCS OFF)

# Thêm OpenXLSX
add_subdirectory(OpenXLSX)

# Chương trình của bạn
add_executable(main
main.cpp
src/menu.cpp
src/linhkien.cpp
src/io_linhkien.cpp
src/structure.cpp
include/menu.h
include/linhkien.h
include/io_linhkien.h
)
target_include_directories(main PRIVATE include)
# Link OpenXLSX
target_link_libraries(main OpenXLSX::OpenXLSX)