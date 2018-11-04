set(LLVM_INSTALL            "C:/Program Files/LLVM/bin")
set(CMAKE_SYSTEM_NAME       "Generic")
set(CMAKE_C_COMPILER        "${LLVM_INSTALL}/clang-cl.exe")
set(CMAKE_C_COMPILER_ID     "Clang")
set(CMAKE_CXX_COMPILER      "${LLVM_INSTALL}/clang-cl.exe")
set(CMAKE_CXX_COMPILER_ID   "Clang")
set(CMAKE_LINKER            "${LLVM_INSTALL}/lld-link.exe")


SET(CMAKE_CXX_FLAGS         "/Wall")
SET(CMAKE_CXX_FLAGS_DEBUG   "/Od")
SET(CMAKE_CXX_FLAGS_RELEASE "/O2")