set(MINGW_INSTALL           "C:/MinGW/bin")
set(CMAKE_SYSTEM_NAME       "Windows")
set(CMAKE_C_COMPILER        "${MINGW_INSTALL}/gcc.exe")
set(CMAKE_C_COMPILER_ID     "GNU")
set(CMAKE_CXX_COMPILER      "${MINGW_INSTALL}/g++.exe")
set(CMAKE_CXX_COMPILER_ID   "GNU")
set(CMAKE_LINKER            "${MINGW_INSTALL}/ld.exe")

set(CMAKE_CXX_FLAGS         "-Wall -Wpedantic -Wextra")