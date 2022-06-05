add_executable(c06.e00.a example_a.cpp)
add_executable(c06.e00.b example_b.cpp)
target_link_libraries(c06.e00.b PRIVATE acpp::common)

add_executable(c06.e00.c example_c.cpp)
add_executable(c06.e00.d example_d.cpp)