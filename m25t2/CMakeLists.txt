# CMakeList.txt: проект CMake для m25t2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("m25t2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (m25t2 "main.cpp"  "cpu.cpp" "cpu.h" "ram.cpp" "ram.h" "disk.cpp" "disk.h" "gpu.h" "gpu.cpp" "kbd.cpp" "kbd.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
