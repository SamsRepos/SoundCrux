cmake_minimum_required(VERSION 3.15)
project(SoundCrux VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_GENERATOR_PLATFORM x64)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source directory
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create a static library
add_library(SoundCrux STATIC ${SOURCES})

# Set VCPKG to target x64
set(VCPKG_TARGET_TRIPLET "x64-windows")

# Find OpenAL package
find_package(OpenAL CONFIG REQUIRED)

# Debugging
message(STATUS "OpenAL Targets: ${OpenAL_LIBRARIES}")

# Specify include directories for SoundCrux
target_include_directories(SoundCrux PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link OpenAL to SoundCrux
target_link_libraries(SoundCrux PUBLIC OpenAL::OpenAL)
