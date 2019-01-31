set(CMAKE_C_COMPILER      "clang-cl" CACHE STRING "" FORCE)
set(CMAKE_CXX_COMPILER    "clang-cl" CACHE STRING "" FORCE)
set(CMAKE_LINKER          "lld-link" CACHE STRING "" FORCE)
set(CMAKE_C_COMPILER_ID   "Clang"    CACHE STRING "" FORCE)
set(CMAKE_CXX_COMPILER_ID "Clang"    CACHE STRING "" FORCE)

add_compile_options("/Wall")

set(ENV_PFX86    "ProgramFiles\(x86\)")
set(MVS_LIB_PATH "$ENV{${ENV_PFX86}}/Microsoft Visual Studio 14.0/VC/lib")
set(KIT_LIB_PATH "$ENV{${ENV_PFX86}}/Windows Kits/10/Lib/10.0.17134.0")

foreach(LP "${MVS_LIB_PATH}/amd64" "${KIT_LIB_PATH}/um/x64" "${KIT_LIB_PATH}/ucrt/x64" )
    add_link_options("LINKER:SHELL:\"/libpath:${LP}\"")
endforeach()