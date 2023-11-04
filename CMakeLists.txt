cmake_minimum_required(VERSION 3.22)

project(TheGame VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Libraries
set(PLAYERS_LIB players_lib)
set(GAME_LIB game_lib)
set(COOKS_LIB cooks_lib)

# Executable
set(EXECUTABLE_NAME theGame)

add_subdirectory(src)
add_subdirectory(app)