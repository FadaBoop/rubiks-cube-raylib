cmake_minimum_required(VERSION 3.10)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib 5.0 REQUIRED)   # Arch ships 5.x

add_executable(rubiks src/main.c)

target_link_libraries(rubiks raylib)

# Extra libs for Linux:
target_link_libraries(rubiks m pthread dl rt X11)