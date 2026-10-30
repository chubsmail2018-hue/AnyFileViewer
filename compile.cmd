@echo off
setlocal

cmake -S . -B build
if errorlevel 1 (
    echo Build configuration failed.
    exit /b 1
)

cmake --build build --config Release
if errorlevel 1 (
    echo Build failed.
    exit /b 1
)

echo.
echo Build complete.
echo Run with:
echo   .\build\Release\anyfileviewer.exe example.tmp
exit /b 0
