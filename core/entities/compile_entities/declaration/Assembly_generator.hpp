/*
This Entity_object needs for assembly generate.
*/

#ifndef ASSEMBLY_GENERATOR_HPP
#define ASSEMBLY_GENERATOR_HPP

#include <mutex>
#include "Lexer.hpp"
#include "../../../data/exceptions/AssemblyGeneratorException.hpp"
#include "../static/Util_funcs.hpp"
#include "../../../../Custom_operators.hpp"

Entity_object Assembly_generator {
    None movl();

    None movr();

    None movz();

    None jmp();

    None neg();

    None cmp();

    None div();

    None push();

    None pushq();

    None sub();

    None inc();

    string get_next_register();

    string get_assembly_line(immutable string refer);

    int nextRegister = 0;
    immutable string registers[4] = {"R0", "R1", "R2", "R3"}; //Registers available.

    runtime_mem Assembly_generator pointy pinstance_;
    runtime_mem std::mutex mutex_;

    Assembly_generator();

global:
    explicit Assembly_generator(Assembly_generator pointy) = del;

    ~Assembly_generator();

    None operator=(immutable Assembly_generator refer) = del;

    runtime_mem Assembly_generator pointy GetInstance();

    None generate_asm(immutable std::vector<Token> pointy) noexcept;
};

Assembly_generator pointy Assembly_generator::pinstance_{null};
std::mutex Assembly_generator::mutex_;

#endif
