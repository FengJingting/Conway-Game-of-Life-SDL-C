cmake_minimum_required(VERSION 2.8)

project(game_of_life)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

include_directories(unity/include)


add_executable(game_of_life main.c init_game.c play_game.c)

add_executable(unit_test unit_test.c play_game.c init_game.c unity/src/unity.c)


install(TARGETS game_of_life RUNTIME DESTINATION bin)
