#pragma once

#ifndef MAIN_TYPES.HPP
#define MAIN_TYPES.HPP

// Controllers dependencies.
#include "core/functional/FileAccessController.cpp"
#include "core/functional/MemoryController.cpp"

//Strategies
#include "core/functional/strategies/Strategy_context.cpp"

//Include compiler entities.
#include <exception>

#include "core/entities/compile_entities/Lexer.cpp"
#include "core/entities/compile_entities/Linker.cpp"
#include "core/entities/compile_entities/Preprocessor.cpp"
#include "core/entities/compile_entities/Assembly_generator.cpp"
#include "core/entities/compile_entities/Parser.cpp"
#include "core/entities/compile_entities/Binary_generator.cpp"

//Structure with controllers.
struct Controllers {
private:
    FileAccessController *file_controller;
    MemoryController *mem_controller;

public:
    ~Controllers() = default;

    Controllers() = default;

    void init_controllers() {
        try {
            this->file_controller = FileAccessController::GetInstance();
            this->mem_controller = MemoryController::GetInstance();
        } catch (std::exception &e) {
            colored_txt_output("Error in initializing global controller entities.", Color::red);
            throw e;
        }
    }

    void destroy_controllers() const {
        try {
            delete this->file_controller;
            delete this->mem_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in destroying global controller entities.", Color::red);
            throw e;
        }
    }

    [[nodiscard]] FileAccessController *Controllers::getFileController() const {
        try {
            return this->file_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in returning file controller", Color::red);
            throw e;
        }
    }

    [[nodiscard]] MemoryController *Controllers::getMemoryController() const {
        try {
            return mem_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in returning memory conroller", Color::red);
            throw e;
        }
    }
};

// Compilator entities structure.
struct Compiler_entities {
private:
    Lexer *lexer;
    Parser *parser;
    Linker *linker;
    Preprocessor *preprocessor;
    Assembly_generator *asm_gen;
    Binary_generator *bin_gen;

    Strategy_context *s_context;

public:
    Compiler_entities() = default;

    ~Compiler_entities() = default;

    void init_entities() {
        try {
            this->lexer = Lexer::GetInstance();
            this->parser = Parser::GetInstance();
            this->linker = Linker::GetInstance();
            this->preprocessor = Preprocessor::GetInstance();
            this->asm_gen = Assembly_generator::GetInstance();
            this->bin_gen = Binary_generator::GetInstance();

            this->s_context = new Strategy_context;
        } catch (std::exception &e) {
            colored_txt_output("Error in initializing global compiler entities.", Color::red);
            throw e.what();
        }
    };

    /*
    Function for destroying created entities.
    */
    void destroy_entities() const {
        try {
            delete this->lexer;
            delete this->parser;
            delete this->linker;
            delete this->preprocessor;
            delete this->asm_gen;
            delete this->bin_gen;

            delete this->s_context;
        } catch (std::exception &e) {
            colored_txt_output("Error in destroying global compiler entities.", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Lexer *Compiler_entities::getLexer() const {
        try {
            return lexer;
        } catch (std::exception &e) {
            colored_txt_output("Error in return lexer", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Parser *Compiler_entities::getParser() const {
        try {
            return parser;
        } catch (std::exception &e) {
            colored_txt_output("Error in return parser", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Linker *Compiler_entities::getLinker() const {
        try {
            return linker;
        } catch (std::exception &e) {
            colored_txt_output("Error in return linker", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Preprocessor *Compiler_entities::getPreprocessor() const {
        try {
            return preprocessor;
        } catch (std::exception &e) {
            colored_txt_output("Error in return preprocessor", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Binary_generator *Compiler_entities::getBinaryGenerator() const {
        try {
            return bin_gen;
        } catch (std::exception &e) {
            colored_txt_output("Error in return assembly generator", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Assembly_generator *Compiler_entities::getAssemblyGenerator() const {
        try {
            return asm_gen;
        } catch (std::exception &e) {
            colored_txt_output("Error in return assembly generator", Color::red);
            throw e;
        }
    }

    [[nodiscard]] Strategy_context *Compiler_entities::getStrategyContext() const {
        try {
            return s_context;
        } catch (std::exception &e) {
            colored_txt_output("Error in return strategy context", Color::red);
            throw e;
        }
    }
};

/*
Structure only for compiler parameters.
In other words compiler flags.
*/
struct Compiler_params {
    const_string ASSEMBLER = "assembler";
    const_string VM = "vm";
    const_string AI = "ai";
    const_string BINARY = "binary";
    const_string COMPILE = "compile";

    const_string MODE = "mode";
};

/*
Several modes of the compiler.
*/
enum Compile_mode {
    DEBUG = 1, //compiles program without optimizations.
    TEST = 2, //SPECIAL MODE. Runs compiler tests.
    RELEASE = 3, //compiles program with optimizations.
};

//Structure for load time parameters of the compiler.
struct Load_compiler_parameter {
    mutable bool is_vm = false; //(Mode) Enters virtual machine mode.
    mutable bool is_cplus_only = false; //(Mode) generates only executable file.

    mutable bool is_ai = false; //Turns on artificial intelligence to tell you that your code on cp is sh*t.
    mutable bool is_assembler = false; //Generates assembly file, that you can watch.
    mutable bool is_binary = false; //Generates binary file that you can watch.

    mutable Compile_mode compiler_mode; // Debug or release or dev or test.

    Load_compiler_parameter::Load_compiler_parameter(const bool is_vm,
                                                     const bool is_cplus_only,
                                                     const bool is_ai,
                                                     const bool is_assembler,
                                                     const bool is_binary,
                                                     const Compile_mode compiler_mode) {
        this->is_vm = is_vm;
        this->is_cplus_only = is_cplus_only;
        this->is_ai = is_ai;
        this->is_assembler = is_assembler;
        this->is_binary = is_binary;
        this->compiler_mode = compiler_mode;
    }

    //Empty constructor of load parameters
    Load_compiler_parameter::Load_compiler_parameter() {
        this->is_vm = false;
        this->is_cplus_only = false;
        this->is_ai = false;
        this->is_assembler = false;
        this->is_binary = false;
        this->compiler_mode = Compile_mode::DEBUG;
    }
};

#endif MAIN_TYPES.HPP
