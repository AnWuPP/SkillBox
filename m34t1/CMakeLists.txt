# CMakeList.txt: проект CMake для m34t1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("m34t1")

set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
find_package(Qt5 COMPONENTS
			Core
			Gui
			Widgets
			REQUIRED)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (m34t1 "m34t1.cpp" "m34t1.h")
target_link_libraries(m34t1
					Qt5::Core
					Qt5::Gui
					Qt5::Widgets)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
