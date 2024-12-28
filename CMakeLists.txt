
cmake_minimum_required(VERSION 3.30)
project(Matrix3D)


SET(SOURCES
    src/main.cpp
    src/Renderer.cpp
  )
  
  include_directories(src/Headers/)
  ADD_EXECUTABLE(Matrix3D ${SOURCES})

