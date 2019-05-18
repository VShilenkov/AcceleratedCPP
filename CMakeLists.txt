cmake_minimum_required(VERSION 3.0.0)
project(AcceleratedCPP VERSION 0.1.0)

if (NOT WIN32)
    set(CMAKE_EXECUTABLE_SUFFIX_CXX ".out" CACHE STRING "" FORCE)
    set(CMAKE_EXECUTABLE_SUFFIX_C   ".out" CACHE STRING "" FORCE)
endif()

add_compile_options("-m64")

add_subdirectory(chapter00)
add_subdirectory(chapter01)
add_subdirectory(chapter02)
add_subdirectory(chapter03)
add_subdirectory(chapter04)
add_subdirectory(chapter05)