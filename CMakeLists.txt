cmake_minimum_required(VERSION 3.28)
project(Cplus_compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}
#    -std=c++20
#    -pthread
#    -O2
#    -Wall
#    -ftree-vectorize
#    -ffast-math
#    -funroll-loops")

#add_executables function
function(add_executables target)
    set(sources "")
    foreach (arg IN LISTS ARGN)
        list(APPEND sources "${arg}")
    endforeach ()

    target_sources(${target} PRIVATE ${sources})
endfunction()

add_executable(Cplus_compiler main.cpp
        core/data/IMain_types.hpp
        static/Custom_operators.hpp)

target_include_directories(Cplus_compiler PRIVATE
        ${PROJECT_SOURCE_DIR}/core
        ${PROJECT_SOURCE_DIR}/static

        ${PROJECT_SOURCE_DIR}/core/data
        ${PROJECT_SOURCE_DIR}/core/entities
        ${PROJECT_SOURCE_DIR}/core/functional
        ${PROJECT_SOURCE_DIR}/core/Tests
)

#add_executable(
#        Cplus_compiler
#
#        #Static section
#        core/data/Variables.hpp
#        static/Constants.hpp
#        static/CplusModel.hpp
#        static/Processor_registers.hpp
#        static/Util_funcs.hpp
#
#        #Exceptions section
#        core/data/exceptions/AnalyzerException.hpp
#        core/data/exceptions/AssemblyGeneratorException.hpp
#        core/data/exceptions/BinaryGeneratorException.hpp
#        core/data/exceptions/CompilerModeException.hpp
#        core/data/exceptions/FileAccessControllerException.hpp
#        core/data/exceptions/LexerException.hpp
#        core/data/exceptions/LinkerException.hpp
#        core/data/exceptions/MainExceptions.hpp
#        core/data/exceptions/MemoryControllerException.hpp
#        core/data/exceptions/PreprocessorException.hpp
#        core/data/exceptions/VirtualMachineException.hpp
#
#        #Test entities
#        ###Classes for private functions
#        core/entities/VM/FriendClassesVM.hpp
#        core/entities/compile_entities/FriendClassesCompile.hpp
#        ###Some tests
#        core/Tests/BaseTest.hpp
#        core/Tests/PositiveTests.cpp
#        core/Tests/NegativeTests.cpp
#        core/Tests/compile_entities/CompilePositiveTests.cpp
#        core/Tests/compile_entities/CompileNegativeTests.cpp
#        core/Tests/vm_entities/VMpositiveTests.cpp
#        core/Tests/vm_entities/VMnegativeTests.cpp
#
#        #Strategies section
#        core/functional/strategies/IStrategies.hpp
#        core/functional/strategies/declaration/Strategy_context.hpp
#        core/functional/strategies/realization/Strategy_context.cpp
#        ###Compile
#        core/functional/strategies/declaration/Compile_strategy.hpp
#        core/functional/strategies/realization/Compile_strategy.cpp
#        ###VM
#        core/functional/strategies/declaration/Vm_strategy.hpp
#        core/functional/strategies/realization/Vm_strategy.cpp
#
#        #Main types section
#        core/data/Main_types_vm.hpp
#        core/data/Main_types_controllers.hpp
#        core/data/Main_types_compile.hpp
#
#        #Compile entities
#        ###Analyzer
#        core/entities/compile_entities/declaration/Analyzer.hpp
#        core/entities/compile_entities/realization/Analyzer.cpp
#        ###Assembly_generator
#        core/entities/compile_entities/declaration/Assembly_generator.hpp
#        core/entities/compile_entities/realization/Assembly_generator.cpp
#        ###Binary_generator
#        core/entities/compile_entities/declaration/Binary_generator.hpp
#        core/entities/compile_entities/realization/Binary_generator.cpp
#        ###Lexer
#        core/entities/compile_entities/declaration/Lexer.hpp
#        core/entities/compile_entities/realization/Lexer.cpp
#        ###Linker
#        core/entities/compile_entities/declaration/Linker.hpp
#        core/entities/compile_entities/realization/Linker.cpp
#        ###Parser
#        core/entities/compile_entities/declaration/Parser.hpp
#        core/entities/compile_entities/realization/Parser.cpp
#        ###Preprocessor
#        core/entities/compile_entities/declaration/Preprocessor.hpp
#        core/entities/compile_entities/realization/Preprocessor.cpp
#
#        #VM entities
#        ###Virtual machine
#        core/entities/VM/declaration/virtual_machine.hpp
#        core/entities/VM/realization/virtual_machine.cpp
#        ###Virtual machine console
#        core/entities/VM/declaration/Virtual_machine_console.hpp
#        core/entities/VM/realization/Virtual_Machine_Console.cpp
#        ###VM Garbage collector
#        core/entities/VM/GarbageCollector/IGarbage_collector.hpp
#        core/entities/VM/GarbageCollector/CollectorWithStop.cpp
#        core/entities/VM/GarbageCollector/ParallelCollector.cpp
#        ###VM Garbage collector strategies
#        core/entities/VM/GarbageCollector/GarbageStrategies/ICollector.cpp
#        core/entities/VM/GarbageCollector/GarbageStrategies/CollectorContext.cpp
#        core/entities/VM/GarbageCollector/GarbageStrategies/ParallelStrategy.cpp
#        core/entities/VM/GarbageCollector/GarbageStrategies/SerialStrategy.cpp
#
#        #Controllers section
#        core/functional/controllers_entities/declaration/File_access_controller.hpp
#        core/functional/controllers_entities/realization/File_access_controller.cpp
#        core/functional/controllers_entities/declaration/Memory_controller.hpp
#        core/functional/controllers_entities/realization/Memory_controller.cpp
#
#        #Static dependencies
#        ###Outer - not my dependencies
#        core/data/dependencies/catch_amalgamated.hpp
#        core/data/dependencies/termcolor.hpp
#        ###Inner - my dependencies
#        core/entities/Logger.hpp
#        core/entities/Logger.cpp
#
#)
