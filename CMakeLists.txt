cmake_minimum_required(VERSION 3.25)
project(demo)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL/include)
set(SDL2_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(demo main.cpp constants.h Window.cpp Window.h Snake.cpp Snake.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)


