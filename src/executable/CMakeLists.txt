cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_executable(inf-calc "src/main.c")

target_link_libraries(inf-calc PRIVATE maths)