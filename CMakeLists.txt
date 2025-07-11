cmake_minimum_required(VERSION 3.28)
project(Cplus_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}
    -std=c++20
    -pthread
    -O2
    -Wall
    -ftree-vectorize
    -ffast-math
    -funroll-loops")

#add_executables function
function(add_executables target)
    set(sources "")
    foreach (arg IN LISTS ARGN)
        list(APPEND sources "${arg}")
    endforeach ()

    target_sources(${target} PRIVATE ${sources})
endfunction()

add_executable(Cplus_compiler
        main.cpp
        Custom_operators.hpp
)

target_include_directories(Cplus_compiler PRIVATE
        ${PROJECT_SOURCE_DIR}/core
        ${PROJECT_SOURCE_DIR}/static

        ${PROJECT_SOURCE_DIR}/core/data
        ${PROJECT_SOURCE_DIR}/core/entities
        ${PROJECT_SOURCE_DIR}/core/functional
        ${PROJECT_SOURCE_DIR}/core/Tests
)