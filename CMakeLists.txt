cmake_minimum_required(VERSION 3.7)
project(scr)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES scr/main.c scr/functions.h scr/types.h scr/logic.c scr/visual.c scr/loadsave.c scr/initialization.c scr/ai.c)
add_executable(scr ${SOURCE_FILES})