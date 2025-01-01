
cmake_minimum_required(VERSION 3.30)
project(Matrix3D)

#create compile_commands_json
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#set(BUILD_MODE Debug)
set(CMAKE_BUILD_TYPE Debug)

SET(SOURCES
    src/main.cpp
    src/Renderer.cpp
  )

  include_directories(src/Headers/)
  ADD_EXECUTABLE(Matrix3D ${SOURCES})

  target_link_libraries(Matrix3D PRIVATE ncurses)
