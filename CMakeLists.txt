cmake_minimum_required(VERSION 3.7)
project(battleship)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES battleship/main.c battleship/functions.h battleship/types.h battleship/logic.c battleship/visual.c battleship/loadsave.c battleship/initialization.c battleship/ai.c)
add_executable(battleship ${SOURCE_FILES})