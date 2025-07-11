/*
This class needs for assembly generate.
*/

#ifndef ASSEMBLY_GENERATOR_HPP
#define ASSEMBLY_GENERATOR_HPP

#include <mutex>
#include "Lexer.hpp"
#include "../../../data/exceptions/AssemblyGeneratorException.hpp"
#include "../static/Util_funcs.hpp"
#include "../../../../Custom_operators.hpp"

class Assembly_generator {
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

    string get_assembly_line(const string &);

    int nextRegister = 0;
    const string registers[4] = {"R0", "R1", "R2", "R3"}; //Registers available.

    static Assembly_generator *pinstance_;
    static std::mutex mutex_;

    Assembly_generator();

global:
    explicit Assembly_generator(Assembly_generator *) = del;

    ~Assembly_generator();

    None operator=(const Assembly_generator &) = del;

    static Assembly_generator *GetInstance();

    None generate_asm(const std::vector<Token> *) noexcept;
};

Assembly_generator *Assembly_generator::pinstance_{null};
std::mutex Assembly_generator::mutex_;

#endif
