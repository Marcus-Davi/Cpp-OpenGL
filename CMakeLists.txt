cmake_minimum_required(VERSION 3.8)
project(opengltest)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(include ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${glfw3_INCLUDE_DIRS})



add_executable(app src/app.cpp)

#Copy shaders to bin folder
file(GLOB shaders RELATIVE ${CMAKE_SOURCE_DIR} "shaders/*"})
foreach(shader ${shaders})
    file(COPY ${shader} DESTINATION ${PROJECT_BINARY_DIR}/bin)
endforeach()


target_link_libraries(app GL glfw ${GLEW_LIBRARIES} )

