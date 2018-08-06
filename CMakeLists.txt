cmake_minimum_required(VERSION 2.7)
project(p3)

# Set the C++ Standard (you can use 98, 11, but 14 is recommended now)
set(CMAKE_CXX_STANDARD 17)

# Set the compiling flags (don't modify)
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations")

# Find the OpenGL library (don't modify)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Find the GLUT library (don't modify)
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

# Build Part 1 of the project (add all of related files)
add_executable(p3_part1 part1.cpp part1_functions.h part1_functions.cpp)

# Build Part 2 of the project (add all of related files)
add_executable(p3_part2 main.cpp vec.h vec.cpp figure.cpp figure.h park.cpp park.h draw.cpp draw.h)

# Link the OpenGL, GLUT and Maths library to your project (don't modify)
target_link_libraries(p3_part1 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)
target_link_libraries(p3_part2 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)