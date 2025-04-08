#pragma once

#ifndef LOAD_DATA.HPP
#define LOAD_DATA.HPP

//Структура для параметров загрузки.
struct Load_compiler_parameter
{
    bool is_assembler = false; //Generates assembly file, that you can watch.
    bool is_vm = false; //(Mode) Enters virtual machine mode.
    bool is_ai = false; //Turns on artificial intelligence to tell you that your code on cp is sh*t.
    bool is_cplus_only = false; //(Mode) generates only executable file.
    bool is_binary = false; //Generates binary file that you can watch.
};

Load_compiler_parameter load_parameter = new Load_compiler_parameter{};

#endif LOAD_DATA.HPP