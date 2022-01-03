cmake_minimum_required(VERSION 3.8)

add_executable(m25t2 main.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp)
target_include_directories(m25t2 PUBLIC ${MY_INCLUDE_DIR})