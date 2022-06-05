add_executable(c06.e08 main.cpp)
target_link_libraries(c06.e08
    PRIVATE
        grader
)

configure_file(input.txt
               input.txt
    COPYONLY
)