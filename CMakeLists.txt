cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(HuntingWorld LANGUAGES CXX VERSION 1.0)
set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Werror -Wall -Wextra -Wpedantic -march=native -g")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++20 -O2 -march=native")

#set(SRC
#    src/consolereader/istandartreader.cpp
#    src/consolereader/numsreader.cpp
#    src/sprites/spritesenemy.cpp
#    src/tui/screenstack.cpp
#    src/tui/itui/iusermenu.cpp
#    src/tui/tuimenus/mainmenu.cpp
#    src/tui/gametui.cpp
#    src/main.cpp 
#  )

set(PROJECT_SOURCES_DIR src)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

include_directories(
  src
  src/game_logic
  src/gui
  src/tui
  src/tui/consolereader
  src/tui/constants
  src/tui/itui
  src/tui/sprites
  src/tui/tuimenus
  )


add_executable(${PROJECT_NAME} ${SOURCES})

#set_target_properties(
#  ${PROJECT_NAME} PROPERTIES
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
