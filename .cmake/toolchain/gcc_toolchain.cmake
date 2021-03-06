set(CMAKE_C_COMPILER      "gcc" CACHE STRING "" FORCE)
set(CMAKE_C_COMPILER_ID   "GNU" CACHE STRING "" FORCE)

set(CMAKE_CXX_COMPILER    "g++" CACHE STRING "" FORCE)
set(CMAKE_CXX_COMPILER_ID "GNU" CACHE STRING "" FORCE)

set(CMAKE_LINKER "ld"  CACHE STRING "" FORCE)

if (NOT WIN32)
    set(CMAKE_EXECUTABLE_SUFFIX_CXX ".out" CACHE STRING "" FORCE)
    set(CMAKE_EXECUTABLE_SUFFIX_C   ".out" CACHE STRING "" FORCE)
endif(NOT WIN32)

add_compile_options("SHELL:-Wall -Wextra -Wpedantic")
add_compile_options("SHELL:-fdiagnostics-show-option")