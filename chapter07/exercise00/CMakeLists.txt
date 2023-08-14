add_executable(c07.e00.a example_a.cpp)
add_executable(c07.e00.b example_b.cpp)
add_executable(c07.e00.c example_c.cpp)

file(COPY grammar.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})