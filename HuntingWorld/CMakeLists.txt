cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(HuntingWorld LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Werror -Wall -Wextra -Wpedantic -fPIC -march=native -pthread -g")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++20 -O2 -fPIC -march=native -pthread")

include_directories(inc)
set(PROJECT_SOURCES_DIR src)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

