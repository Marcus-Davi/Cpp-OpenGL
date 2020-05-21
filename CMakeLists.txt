cmake_minimum_required(VERSION 3.8)
project(opengltest)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

file(GLOB SOURCES "src/*.cpp")

add_executable(open_exe ${SOURCES})
target_link_libraries(open_exe glut GL GLU)
