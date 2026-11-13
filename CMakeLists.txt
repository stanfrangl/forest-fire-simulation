# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.23)

# Define the project
project(
  forestFireSimulation
  VERSION 1.0
  DESCRIPTION "Simulating forest fires and management strategies"
  LANGUAGES CXX
)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
  CMAKE_RUNTIME_OUTPUT_DIRECTORY
  "${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

set(
  CMAKE_LIBRARY_OUTPUT_DIRECTORY
  "${CMAKE_BINARY_DIR}/$<CONFIGURATION>"
)

add_executable(forestSimulation
  src/main.cpp
)

if(APPLE)
  set_target_properties(forestSimulation PROPERTIES
    INSTALL_RPATH "@executable_path;@loader_path"
    BUILD_WITH_INSTALL_RPATH TRUE
    MACOSX_RPATH TRUE
  )
elseif(UNIX)
  set_target_properties(forestSimulation PROPERTIES
    INSTALL_RPATH "$ORIGIN"
    BUILD_WITH_INSTALL_RPATH TRUE
  )
endif()

# Specify that we want to build SDL_TTF's dependencies
set(SDLTTF_VENDORED ON) 

# Set a variable for our vendor directory
set(VENDOR_DIR "${PROJECT_SOURCE_DIR}/vendor") 

find_package(SDL3 REQUIRED)

target_link_libraries(forestSimulation 
  SDL3::SDL3 
)