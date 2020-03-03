cmake_minimum_required(VERSION 3.5)

project(orq LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(Qt5 COMPONENTS Core Widgets Network Gui Svg REQUIRED)

# Glob source files
file(GLOB MAIN_SRC "src/*.[hc]pp")

## Add all source files to main executable
add_executable(orq ${MAIN_SRC})

# Link Qt
target_link_libraries(orq PRIVATE
	Qt5::Core
	Qt5::Widgets
	Qt5::Network
	Qt5::Gui
	Qt5::Svg)