cmake_minimum_required(VERSION 3.12)


configure_file(input.txt input.txt COPYONLY)

add_executable(c05.e03.list)
target_sources(c05.e03.list
    PRIVATE
        main.cpp
        grade.cpp
        median.cpp
        Student_info.cpp
)

target_compile_definitions(c05.e03.list
    PRIVATE
        USE_LIST
)

add_executable(c05.e03.vector)
target_sources(c05.e03.vector
    PRIVATE
        main.cpp
        grade.cpp
        median.cpp
        Student_info.cpp
)