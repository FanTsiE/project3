cmake_minimum_required(VERSION 3.10)
project(p3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

add_executable(part2 main.cpp vec.h vec.cpp figure.cpp figure.h park.cpp park.h draw.cpp draw.h)
add_executable(part1 part1.cpp part1_functions.h part1_functions.cpp)
target_link_libraries(part2 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)