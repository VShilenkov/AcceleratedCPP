cmake_minimum_required(VERSION 3.12)


configure_file(input10.txt      input10.txt     COPYONLY)
configure_file(input1000.txt    input1000.txt   COPYONLY)
configure_file(input10000.txt   input10000.txt  COPYONLY)


add_library(c05.e02 OBJECT)

target_sources(c05.e02
    PRIVATE
        grade.cpp
        median.cpp
        Student_info.cpp
)

add_library(c05.e02.input10 INTERFACE)
target_compile_definitions(c05.e02.input10
    INTERFACE
        INPUT_FILE_NAME=\"input10.txt\"
)

add_library(c05.e02.input1000 INTERFACE)
target_compile_definitions(c05.e02.input1000
    INTERFACE
        INPUT_FILE_NAME=\"input1000.txt\"
)

add_library(c05.e02.input10000 INTERFACE)
target_compile_definitions(c05.e02.input10000
    INTERFACE
        INPUT_FILE_NAME=\"input10000.txt\"
)

add_executable(c05.e02.list10 main_list.cpp)

target_link_libraries(c05.e02.list10
    PRIVATE
        c05.e02
        c05.e02.input10
)

add_executable(c05.e02.list1000 main_list.cpp)

target_link_libraries(c05.e02.list1000
    PRIVATE
        c05.e02
        c05.e02.input1000
)

add_executable(c05.e02.list10000 main_list.cpp)

target_link_libraries(c05.e02.list10000
    PRIVATE
        c05.e02
        c05.e02.input10000
)

add_executable(c05.e02.vector10 main_vector.cpp)

target_link_libraries(c05.e02.vector10
    PRIVATE
        c05.e02
        c05.e02.input10
)

add_executable(c05.e02.vector1000 main_vector.cpp)

target_link_libraries(c05.e02.vector1000
    PRIVATE
        c05.e02
        c05.e02.input1000
)

add_executable(c05.e02.vector10000 main_vector.cpp)

target_link_libraries(c05.e02.vector10000
    PRIVATE
        c05.e02
        c05.e02.input10000
)

add_custom_target(c05.e02.all ALL 
    DEPENDS
        c05.e02.list10
        c05.e02.list1000
        c05.e02.list10000
        c05.e02.vector10
        c05.e02.vector1000
        c05.e02.vector10000
)