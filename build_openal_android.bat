@echo off

REM Set the Android NDK path (adjust this to your setup)
set ANDROID_NDK=C:/android-ndk-r27

REM Set Android ABI (e.g., arm64-v8a, armeabi-v7a, etc.)
set ABI=arm64-v8a

REM Save the current directory and change to the OpenAL Soft build directory
pushd C:\Libs\openal-soft\build

REM Remove previous CMake cache and files if they exist
if exist CMakeCache.txt del CMakeCache.txt
if exist CMakeFiles rmdir /s /q CMakeFiles

REM Run CMake to configure for Android
cmake -G "Ninja" ^
    -DCMAKE_TOOLCHAIN_FILE=%ANDROID_NDK%/build/cmake/android.toolchain.cmake ^
    -DANDROID_ABI=%ABI% ^
    -DANDROID_PLATFORM=android-21 ^
    .. || goto :error

REM Run Ninja to build OpenAL Soft
ninja || goto :error

REM Clean up and return to the original directory
echo Build completed successfully.
goto :end

:error
echo An error occurred during the build process.
popd
pause
exit /b 1

:end
popd
pause
exit /b 0
