add_executable(c06.e00.i example_i.cpp)
target_link_libraries(c06.e00.i
    PRIVATE
        grader
)

configure_file(input.txt
               input.txt
    COPYONLY
)

add_executable(c06.e00.j example_j.cpp)
target_link_libraries(c06.e00.j
    PRIVATE
        grader
)