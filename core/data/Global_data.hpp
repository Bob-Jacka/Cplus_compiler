#pragma once

#ifndef GLOBAL_DATA.HPP
#define GLOBAL_DATA.HPP
//EX. Load_data

//Compiler params constans
#define ASSEMBLER "assembler"
#define VM "vm"

#define AI "ai"
#define BINARY "binary"
#define COMPILE "cplus_only"

enum Compile_mode {
    DEBUG = 1,
    RELEASE = 2,
    DEV = 3
}

//Структура для параметров загрузки.
struct Load_compiler_parameter
{
    bool is_vm = false; //(Mode) Enters virtual machine mode.
    bool is_cplus_only = false; //(Mode) generates only executable file.

    bool is_ai = false; //Turns on artificial intelligence to tell you that your code on cp is sh*t.
    bool is_assembler = false; //Generates assembly file, that you can watch.
    bool is_binary = false; //Generates binary file that you can watch.
    
    Compile_mode compiler_mode; // Debug or release or dev.
};

static load_parameter = new Load_compiler_parameter{}; //Global instance of load parameters.
static Comp_entities * program_entites = new Comp_entities(); //Programm entities for actions.
static Controllers controllers = new Controllers(); //Global instance of controllers entities.

#endif GLOBAL_DATA.HPP