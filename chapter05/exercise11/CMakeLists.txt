cmake_minimum_required(VERSION 3.12)

configure_file(input.txt input.txt COPYONLY)

add_executable(c05.e11 main.cpp)

target_compile_definitions(c05.e11
    PRIVATE
        $<BUILD_INTERFACE:INPUT_FILE=\"${CMAKE_CURRENT_LIST_DIR}/input.txt\">
)
