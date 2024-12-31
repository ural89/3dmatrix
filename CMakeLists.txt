
cmake_minimum_required(VERSION 3.30)
project(Matrix3D)
set(DCMAKE_EXPORT_COMPILE_COMMANDS ON)



SET(SOURCES
    src/main.cpp
    src/Renderer.cpp
  )
  
  include_directories(src/Headers/)
  ADD_EXECUTABLE(Matrix3D ${SOURCES})

