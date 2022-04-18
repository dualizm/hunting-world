cmake_minimum_required(VERSION 3.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(HuntingWorld LANGUAGES CXX VERSION 1.2)
set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Werror -Wall -Wextra -Wpedantic -march=native -g")
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++20 -O2 -march=native")

set(PROJECT_SOURCES_DIR src)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

include_directories(
  src
  src/game_logic
  src/game_logic/actor
  src/game_logic/player
  src/gui
  src/tui
  src/tui/consolereader
  src/tui/consoleprinter
  src/tui/constants
  src/tui/tuimenus/itui
  src/tui/sprites
  src/tui/tuimenus
  src/tui/tuimenus/mainmenu
  src/tui/tuimenus/instructionmenu
  )


add_executable(${PROJECT_NAME} ${SOURCES})

#set_target_properties(
#  ${PROJECT_NAME} PROPERTIES
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
