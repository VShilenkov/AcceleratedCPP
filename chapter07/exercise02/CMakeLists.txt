add_executable(c07.e02)

target_sources(c07.e02
    PRIVATE
        main.cpp 
        grade.cpp 
        median.cpp 
        Student_info.cpp
)

configure_file(input10000.txt   input10000.txt  COPYONLY)