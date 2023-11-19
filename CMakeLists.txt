cmake_minimum_required(VERSION 3.23)
project(Sandbox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(sfml)

file(GLOB_RECURSE SRC "src/**.cpp" )
add_executable(Sandbox ${SRC})

target_link_libraries (Sandbox sfml-graphics sfml-window sfml-system)