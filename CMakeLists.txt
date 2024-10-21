cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(MSVC)
	add_compile_definitions(CLAC_MSVC)
endif(MSVC)

project("inf_calc")
add_subdirectory("src")
