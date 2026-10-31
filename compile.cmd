@echo off
setlocal

where cmake >nul 2>nul
if errorlevel 1 (
    echo CMake is not installed or not in PATH.
    echo Install CMake and try again.
    exit /b 1
)

echo Configuring project...
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 (
    echo CMake configuration failed.
    exit /b 1
)

echo Building project...
cmake --build build --config Release
if errorlevel 1 (
    echo Build failed.
    exit /b 1
)

echo Checking output...
if exist "build\Release\anyfileviewer.exe" (
    echo EXE created: build\Release\anyfileviewer.exe
    exit /b 0
)
if exist "build\Debug\anyfileviewer.exe" (
    echo EXE created: build\Debug\anyfileviewer.exe
    exit /b 0
)
if exist "build\anyfileviewer.exe" (
    echo EXE created: build\anyfileviewer.exe
    exit /b 0
)

echo No executable file was created.
echo This usually means CMake did not generate a valid build target for this system.
echo Try installing Visual Studio C++ tools or using a proper CMake generator.
exit /b 1
