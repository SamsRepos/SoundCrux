@echo off

REM Save the current directory and change to the build directory
pushd C:\Libs\openal-soft\build

REM Remove previous CMake cache and files if they exist
if exist CMakeCache.txt del CMakeCache.txt
if exist CMakeFiles rmdir /s /q CMakeFiles

REM Run CMake to generate Ninja build files
cmake -G "Ninja" .. || goto :error

REM Run Ninja to build the project
ninja || goto :error

REM Clean up and return to the original directory
echo Build completed successfully.
goto :end

:error
echo An error occurred during the build process.
REM Return to the original directory
popd
pause
exit /b 1

:end
REM Return to the original directory
popd
pause
exit /b 0
