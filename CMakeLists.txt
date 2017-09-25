cmake_minimum_required(VERSION 3.7)
project(src)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES src/main.c src/functions.h src/types.h src/logic.c src/visual.c src/loadsave.c src/initialization.c src/ai.c)
add_executable(src ${SOURCE_FILES})