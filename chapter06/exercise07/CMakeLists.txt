cmake_minimum_required(VERSION 3.12)

add_executable(c06.e07 main.cpp)

target_link_libraries(c06.e07
    PRIVATE
        grader
        average
)

configure_file(input.txt
               input.txt
    COPYONLY
)