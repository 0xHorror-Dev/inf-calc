cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_library(maths "src/maths.c")

target_include_directories(maths PUBLIC "inc/")