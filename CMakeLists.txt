cmake_minimum_required(VERSION 3.15)
project(MagicCube2)

set(CMAKE_CXX_STANDARD 14)

add_executable(MagicCube2 main.cpp Cube/Cube.cpp Cube/Cube.h Cube3.cpp Cube3.h)


find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

target_link_libraries(MagicCube2 sfml-graphics sfml-audio)