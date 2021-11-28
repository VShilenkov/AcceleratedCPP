cmake_minimum_required(VERSION 3.12.0)
project(AcceleratedCPP VERSION 0.1.0)

if(WITH_IWYU)
    find_program(IWYU_EXECUTABLE include-what-you-use REQUIRED)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${IWYU_EXECUTABLE}")
endif()

if(WITH_CLANG_TIDY)
    find_program(CLANG_TIDY_EXECUTABLE clang-tidy REQUIRED)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXECUTABLE}")
endif()

if(WITH_CPPCHECK)
    find_program(CPPCHECK_EXECUTABLE cppcheck REQUIRED)
    set(CMAKE_CXX_CPPCHECK "${CPPCHECK_EXECUTABLE};--std=c++11")
endif()

if(WITH_CPPLINT)
    find_program(CPPLINT_EXECUTABLE cpplint REQUIRED)
    set(CMAKE_CXX_CPPLINT "${CPPLINT_EXECUTABLE};--linelength=79")
endif()

if(WITH_LWYU)
    set(CMAKE_LINK_WHAT_YOU_USE true)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(inc)

add_subdirectory(chapter00)
add_subdirectory(chapter01)
add_subdirectory(chapter02)
add_subdirectory(chapter03)
add_subdirectory(chapter04)
add_subdirectory(chapter05)