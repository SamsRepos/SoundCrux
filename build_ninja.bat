@echo off

rem Delete the build directory if it exists
if exist build rmdir /S /Q build

rem Run vcpkg install with the correct triplet
vcpkg install --triplet x64-windows

rem Run CMake to configure the project and generate build files with Ninja
cmake -S . -B build -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -DVCPKG_TARGET_TRIPLET="x64-windows"

rem Build the project
cmake --build build --verbose

rem Pause the command prompt to see output (optional)
pause
