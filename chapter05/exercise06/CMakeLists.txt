cmake_minimum_required(VERSION 3.12)

configure_file(input.txt input.txt COPYONLY)

add_executable(c05.e06)
target_sources(c05.e06
    PRIVATE
        main.cpp
        grade.cpp
        median.cpp
        Student_info.cpp
)
