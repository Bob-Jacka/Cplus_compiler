/*
This class needs for assembly generate.
*/

#ifndef ASSEMBLY_GENERATOR_HPP
#define ASSEMBLY_GENERATOR_HPP

#include <mutex>
#include "Lexer.hpp"
#include "../../../data/exceptions/AssemblyGeneratorException.hpp"
#include "../static/Util_funcs.hpp"

class Assembly_generator {
    void movl();

    void movr();

    void movz();

    void jmp();

    void neg();

    void cmp();

    void div();

    void push();

    void pushq();

    void sub();

    void inc();

    string get_next_register();

    string get_assembly_line(const string &);

    int nextRegister = 0;
    const string registers[4] = {"R0", "R1", "R2", "R3"}; //Registers available.

    static Assembly_generator *pinstance_;
    static std::mutex mutex_;

    Assembly_generator();

public:
    explicit Assembly_generator(Assembly_generator *) = delete;

    ~Assembly_generator();

    void operator=(const Assembly_generator &) = delete;

    static Assembly_generator *GetInstance();

    void generate_asm(const std::vector<Token> *) noexcept;
};

Assembly_generator *Assembly_generator::pinstance_{nullptr};
std::mutex Assembly_generator::mutex_;

#endif
