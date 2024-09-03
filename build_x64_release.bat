@echo off

REM Delete the build directory if it exists
if exist build rmdir /S /Q build

REM Create and navigate to the build directory
mkdir build
pushd build

REM Run CMake to configure the build for Windows
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ..

REM Build the project
ninja

popd

REM Pause the command prompt to see output
pause
