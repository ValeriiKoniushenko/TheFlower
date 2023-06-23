cmake_minimum_required(VERSION 3.20.0)

project(FlowerGame)

set (CMAKE_CXX_STANDARD 20)

add_subdirectory(flower/core)
add_subdirectory(flower/flower)
add_subdirectory(flower/map)
add_subdirectory(flower/player)
add_subdirectory(flower/program)
add_subdirectory(flower/snake)
add_subdirectory(flower/utils)
add_subdirectory(dependencies/SFML-2.6.0)
add_subdirectory(tests)