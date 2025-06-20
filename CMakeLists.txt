cmake_minimum_required(VERSION 3.28)
project(Cplus_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
        core/data/exceptions/FileAccessControllerException.cpp
        core/data/exceptions/MemoryControllerException.cpp
        core/data/dependencies/catch_amalgamated.hpp
)
