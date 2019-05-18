set(SOURCE_FILES main.cpp grade.cpp median.cpp Student_info.cpp)
set(HEADER_FILES grade.hpp median.hpp Student_info.hpp)

add_executable(c05.e00.a ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(c05.e00.a PUBLIC ../../../inc)