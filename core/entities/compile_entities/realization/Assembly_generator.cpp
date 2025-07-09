#include "../declaration/Assembly_generator.hpp"

Assembly_generator::Assembly_generator() {
    //
}

Assembly_generator::~Assembly_generator() {
    //
}

/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Assembly_generator *Assembly_generator::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Assembly_generator();
    }
    return pinstance_;
}

void Assembly_generator::movl() {
    //
}

void Assembly_generator::movr() {
    //
}

void Assembly_generator::movz() {
    //
}

void Assembly_generator::jmp() {
    //
}

void Assembly_generator::neg() {
    //
}

void Assembly_generator::cmp() {
    //
}

void Assembly_generator::div() {
    //
}

void Assembly_generator::push() {
    //
}

void Assembly_generator::pushq() {
    //
}

void Assembly_generator::sub() {
    //
}

void Assembly_generator::inc() {
    //
}

string Assembly_generator::get_next_register() {
    return registers[nextRegister++ % registers->length()];
}

/*
Proceed token line into assembly line.
*/
string Assembly_generator::get_assembly_line(const string &token_line) {
    string assemblyCode;
    string *splitted = utility::line_splitter(token_line); //splitted token line.
    if (splitted->size() == 3) {
        string a = splitted[0];
        string op = splitted[1];
        string b = splitted[2];

        string reg = get_next_register();
        assemblyCode += "LOAD " + a + " " + reg + "\n";
        if (op == "+") {
            assemblyCode += "ADD " + b + " " + reg + "\n";
        } else if (op == "-") {
            assemblyCode += "SUB " + b + " " + reg + "\n";
        } else if (op == "*") {
            assemblyCode += "MUL " + b + " " + reg + "\n";
        } else if (op == "/") {
            assemblyCode += "DIV " + b + " " + reg + "\n";
        }
        assemblyCode += "STORE " + reg + " RESULT\n";
    } else {
        assemblyCode = "ERROR: Неверное выражение\n";
        throw AssemblyGeneratorException::error_in_assembly_generation();
    }
    return assemblyCode;
}

/*
Main entry point in Assembly generator
*/
void Assembly_generator::generate_asm(const std::vector<Token> *tokens) noexcept {
    for (const string token_line: tokens) {
        get_assembly_line(token_line);
    }
}
