set(HOST_PF_PATH            "C:/Program Files")
set(HOST_PFx86_PATH         "C:/Program Files (x86)")

set(LLVM_INSTALL            "${HOST_PF_PATH}/LLVM/bin")
set(VS_INSTALL              "${HOST_PFx86_PATH}/Microsoft Visual Studio 14.0")
set(WINKITS_INSTALL         "${HOST_PFx86_PATH}/Windows Kits/10")

set(VS_LIB_PATH             "${VS_INSTALL}/VC/lib")
set(WINKITS_LIB_PATH        "${WINKITS_INSTALL}/Lib/10.0.17134.0")

set(CMAKE_SYSTEM_NAME       "Windows")
set(CMAKE_C_COMPILER        "${LLVM_INSTALL}/clang-cl.exe")
set(CMAKE_C_COMPILER_ID     "Clang")
set(CMAKE_CXX_COMPILER      "${LLVM_INSTALL}/clang-cl.exe")
set(CMAKE_CXX_COMPILER_ID   "Clang")
set(CMAKE_LINKER            "${LLVM_INSTALL}/lld-link.exe")

set(CMAKE_CXX_FLAGS         "/Wall")

set(CMAKE_EXE_LINKER_FLAGS  "-libpath:\"${VS_LIB_PATH}/amd64\"          \
                             -libpath:\"${WINKITS_LIB_PATH}/ucrt/x64\"  \
                             -libpath:\"${WINKITS_LIB_PATH}/um/x64\""
)