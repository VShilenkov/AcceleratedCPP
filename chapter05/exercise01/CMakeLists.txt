cmake_minimum_required(VERSION 3.12)

add_executable(c05.e01)

target_sources(c05.e01
    PRIVATE
        main.cpp
)

add_custom_command(TARGET c05.e01 POST_BUILD
    COMMAND cmake -E 
        copy_if_different 
            ${CMAKE_CURRENT_LIST_DIR}/input.txt 
            ${CMAKE_CURRENT_BINARY_DIR} 
    COMMENT "Copy input file"
)