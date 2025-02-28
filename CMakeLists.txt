cmake_minimum_required(VERSION 3.10)
project(Raytracing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find and include SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add the executable
add_executable(raytracing src/main.cpp)
target_link_libraries(raytracing ${SDL2_LIBRARIES})

# Enable folders in IDEs for better project structure
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Create a source directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/src)
