cmake_minimum_required(VERSION 3.28)
project(Cplus_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
message("Cmake C++ version accepted")
set(CMAKE_CXX_STANDARD_REQUIRED True)
message("CMAKE_CXX_STANDARD_REQUIRED switched to True")
set(LIBCXXABI_USE_LLVM_UNWINDER True)
message("LLVM unwinder switched to ON")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}
    -std=c++23
    -pthread
    -O2
    -Wall
    -ftree-vectorize
    -ffast-math
    -funroll-loops")
message("Extended C++ flags accepted")

set(LLVM_DIR "C:\\Program Files\\LLVM\\llvm-project-llvmorg-20.1.8\\")
IF (WIN32)
    message(STATUS "Found LLVM on Windows ${LLVM_PACKAGE_VERSION}.")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}.")
ELSEIF (LINUX)
    message(STATUS "Found LLVM on Linux ${LLVM_PACKAGE_VERSION}.")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}.")
ELSEIF (APPLE)
    message("Jesus Christ, do not use this Satan's system!!")
ELSE ()
    message(STATUS "Error, unknown system")
ENDIF ()

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(Cplus_compiler
        main.cpp
        Custom_operators.hpp #file with ugly custom aliases for C++ operators
)

target_include_directories(Cplus_compiler PRIVATE
        ${PROJECT_SOURCE_DIR}/core
        ${PROJECT_SOURCE_DIR}/static #static components (not in core directory)

        ${PROJECT_SOURCE_DIR}/core/data

        ###Outer dependencies
        ${PROJECT_SOURCE_DIR}/core/data/dependencies/boost
        ${PROJECT_SOURCE_DIR}/core/data/dependencies/catch_amalgamated.hpp
        ${PROJECT_SOURCE_DIR}/core/data/dependencies/termcolor.hpp

        ${PROJECT_SOURCE_DIR}/core/data/exceptions #add exceptions classes

        ${PROJECT_SOURCE_DIR}/core/entities #add all entities (compile or virtual machine)
        ${PROJECT_SOURCE_DIR}/core/functional
        ${PROJECT_SOURCE_DIR}/core/Tests #directory with tests
)