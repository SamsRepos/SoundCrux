cmake_minimum_required(VERSION 3.14)  # Minimum version for good Android support

# Define the project
project(SoundCrux VERSION 1.0 LANGUAGES CXX)

# Define the static library target
add_library(SoundCrux STATIC)

# Recursively find all .cpp source files in the src directory
file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Check if any source files were found
if(NOT SRC_FILES)
    message(FATAL_ERROR "No source files found in ${CMAKE_CURRENT_SOURCE_DIR}/src/. Please check the directory and file paths.")
endif()

# Add source files to the SoundCrux target
target_sources(SoundCrux PRIVATE ${SRC_FILES})

include_directories(${CMAKE_SOURCE_DIR}/include)

set(OPENAL_INCLUDE_DIR "C:/Libs/openal-soft/include")

# Platform-specific settings
if (WIN32)
    # Windows-specific configurations
    message(STATUS "Configuring for Windows")

    # Specify the path to OpenAL's build output directory
    set(OPENAL_DIR "C:/Libs/openal-soft/build")
    
    # Adjust these paths according to your actual OpenAL directory structure
    find_library(OPENAL_LIBRARY OpenAL32 PATHS ${OPENAL_DIR} NO_DEFAULT_PATH)
    find_path(OPENAL_INCLUDE_DIR AL/al.h PATHS ${OPENAL_DIR} ${OPENAL_DIR}/include ${OPENAL_DIR}/../../include NO_DEFAULT_PATH)

    # Check if OpenAL was found and set appropriately
    if (NOT OPENAL_LIBRARY)
        message(FATAL_ERROR "OpenAL library not found. Please check the OPENAL_DIR path.")
    endif()

    if (NOT OPENAL_INCLUDE_DIR)
        message(FATAL_ERROR "OpenAL include directory not found. Please check the OPENAL_DIR path.")
    endif()

    # Link OpenAL and set include directories
    target_link_libraries(SoundCrux PRIVATE ${OPENAL_LIBRARY})
    target_include_directories(SoundCrux PRIVATE ${OPENAL_INCLUDE_DIR})
elseif (ANDROID)
    # Android-specific configurations
    message(STATUS "Configuring for Android")

    # Find OpenAL for Android or use a pre-built version
    find_library(OPENAL_LIBRARY OpenSLES)  # This might vary; adjust accordingly
    find_path(OPENAL_INCLUDE_DIR AL/al.h)  # Modify this to the path where OpenAL for Android includes are located

    # Check if OpenAL was found and set appropriately
    if (NOT OPENAL_LIBRARY)
        message(FATAL_ERROR "OpenAL library for Android not found.")
    endif()

    if (NOT OPENAL_INCLUDE_DIR)
        message(FATAL_ERROR "OpenAL include directory for Android not found.")
    endif()

    # Link OpenAL and set include directories
    target_link_libraries(SoundCrux PRIVATE ${OPENAL_LIBRARY})
    target_include_directories(SoundCrux PRIVATE ${OPENAL_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# Set C++ standard
target_compile_features(SoundCrux PRIVATE cxx_std_17)

if (MSVC)
    target_compile_options(SoundCrux PRIVATE /W4 /WX)  # Use /W4 (all warnings) and /WX (warnings as errors) for MSVC
else()
    target_compile_options(SoundCrux PRIVATE -Wall -Wextra -Werror)  # Use -Wall, -Wextra, and -Werror for GCC/Clang
endif()
