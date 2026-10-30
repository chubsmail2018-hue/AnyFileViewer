cmake_minimum_required(VERSION 3.16)
project(AnyFileViewer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(anyfileviewer
    src/main.cpp
    src/FileTypeDetector.cpp
    src/TmpInterpreter.cpp
)

target_include_directories(anyfileviewer
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(anyfileviewer PRIVATE /W4)
else()
    target_compile_options(anyfileviewer PRIVATE -Wall -Wextra -Wpedantic)
endif()
