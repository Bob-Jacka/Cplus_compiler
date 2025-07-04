cmake_minimum_required(VERSION 3.28)
project(Cplus_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_executables function
function(add_executables target)
    set(sources "")
    foreach (arg IN LISTS ARGN)
        list(APPEND sources "${arg}")
    endforeach ()

    target_sources(${target} PRIVATE ${sources})
endfunction()

add_executable(
        Cplus_compiler

        main.cpp
        core/data/Variables.hpp

        static/Constants.hpp
        static/CplusModel.hpp
        static/Processor_registers.hpp
        static/UtilFuncs.hpp
        core/data/exceptions/MainExceptions.cpp
        core/entities/VM/FriendClassesVM.hpp
        core/data/Main_types_vm.hpp
)
