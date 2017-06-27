cmake_minimum_required(VERSION 3.7)
project(BattleShip)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c functions.h types.h logic.c visual.c loadsave.c initialization.c)
add_executable(BattleShip ${SOURCE_FILES})