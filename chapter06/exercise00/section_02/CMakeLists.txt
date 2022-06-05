add_library(student_info STATIC Student_info.cpp)
target_include_directories(student_info
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

add_library(median STATIC median.cpp)
target_include_directories(median
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

add_library(grader STATIC grade.cpp)
target_link_libraries(grader
    PUBLIC
        student_info
        median
)


configure_file(input.txt
               input.txt
    COPYONLY
)

add_executable(c06.e00.e example_e.cpp)
target_link_libraries(c06.e00.e
    PRIVATE
        student_info
)

add_executable(c06.e00.f example_f.cpp)
target_link_libraries(c06.e00.f
    PRIVATE
        grader
)

add_library(average STATIC average.cpp)
target_include_directories(average
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(c06.e00.g example_g.cpp)
target_link_libraries(c06.e00.g
    PRIVATE
        grader
        average
)

add_executable(c06.e00.h example_h.cpp)
target_link_libraries(c06.e00.h
    PRIVATE
        grader
        average
)