#!/bin/bash

# Navigate to the build directory
pushd /path/to/SoundCrux/build

# Remove old build files
rm -f CMakeCache.txt
rm -rf CMakeFiles

# Run CMake to configure the build for Android
cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=/path/to/android-ndk/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-21 ..

# Build the project
ninja

# Clean up and return to the original directory
popd
