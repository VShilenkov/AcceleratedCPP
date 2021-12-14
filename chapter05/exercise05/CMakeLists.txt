cmake_minimum_required(VERSION 3.12)


configure_file(input.txt input.txt COPYONLY)

add_executable(c05.e05 main.cpp)
target_compile_definitions(c05.e05 PRIVATE INPUT_FILE=\"input.txt\")
