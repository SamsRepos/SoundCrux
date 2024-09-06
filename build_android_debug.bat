@echo off

REM Delete the build directory if it exists
if exist build rmdir /S /Q build

REM Create and navigate to the build directory
mkdir build
pushd build

REM Path to the Android NDK
set ANDROID_NDK=C:/android-ndk-r27

REM Android ABI and platform settings
set ABI=arm64-v8a
set PLATFORM=21

REM Run CMake to configure the build for Android using the Android NDK
cmake -G "Ninja" ^
  -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%/build/cmake/android.toolchain.cmake ^
  -DANDROID_ABI=%ABI% ^
  -DANDROID_PLATFORM=android-%PLATFORM% ^
  -DCMAKE_BUILD_TYPE=Debug ^
  ..

REM Build the project
ninja

popd

REM Pause the command prompt to see output
pause
