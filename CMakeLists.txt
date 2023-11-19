cmake_minimum_required(VERSION 3.23)
project(Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(sfml)

file(GLOB SRC "*.c" "*.cpp" "*.h" "*.hpp")
add_executable(Sandbox ${SRC})

target_include_directories(Sandbox PUBLIC "src")

target_link_libraries (Sandbox sfml-graphics sfml-window sfml-system)