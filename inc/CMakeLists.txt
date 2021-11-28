add_library(acpp_common INTERFACE)
add_library(acpp::common ALIAS acpp_common)

target_include_directories(acpp_common
    INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)