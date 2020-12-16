cmake_minimum_required(VERSION 3.11)
project(oglrender)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(extern)

set(header_files
    src/oglrender/window.h
    src/oglrender/app.h
)

set(source_files
    src/oglrender/main.cpp
    src/oglrender/window.cpp
    src/oglrender/app.cpp
)

add_executable(oglrender ${header_files} ${source_files})

target_include_directories(oglrender PRIVATE extern/glad/include)
target_link_libraries(oglrender PRIVATE glfw glad)