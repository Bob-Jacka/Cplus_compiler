#pragma once

/*
 Header file with compile types included
 */

// Controllers dependencies.
#include "../functional/controllers_entities/MemoryController.cpp"

//Strategies
#include "../functional/strategies/Strategy_context.cpp"

//Include compiler entities.
#include "../entities/compile_entities/Lexer.cpp"
#include "../entities/compile_entities/Linker.cpp"
#include "../entities/compile_entities/Preprocessor.cpp"
#include "../entities/compile_entities/Assembly_generator.cpp"
#include "../entities/compile_entities/Parser.cpp"
#include "../entities/compile_entities/Binary_generator.cpp"
#include "../entities/compile_entities/Analyzer.cpp"

using namespace utility;

//Structure with controllers.
struct Controllers {
private:
    FileAccessController *file_controller; //file controller entity
    MemoryController *mem_controller; //memory controller entity

public:
    /*
     Standard controllers constructor
     */
    Controllers::Controllers() {
        file_controller = nullptr;
        mem_controller = nullptr;
    }

    /*
     Standard controllers destructor
     */
    Controllers::~Controllers() {
        delete file_controller;
        delete mem_controller;
    }

    /*
     Method for initializing controllers (file and memory controllers)
     */
    void init_controllers() {
        try {
            this->file_controller = FileAccessController::GetInstance();
            this->mem_controller = MemoryController::GetInstance();
        } catch (std::exception &e) {
            colored_txt_output("Error in initializing global controller entities.", Color::red);
            throw e;
        }
    }

    /*
     Method for destroying inner controllers
     */
    void destroy_controllers() const {
        try {
            delete this->file_controller;
            delete this->mem_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in destroying global controller entities.", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for receive file controller
     */
    [[nodiscard]] FileAccessController *Controllers::get_file_controller() const {
        try {
            return this->file_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in returning file controller", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for receive memory controller
     */
    [[nodiscard]] MemoryController *Controllers::get_memory_controller() const {
        try {
            return mem_controller;
        } catch (std::exception &e) {
            colored_txt_output("Error in returning memory controller", Color::red);
            throw e;
        }
    }
};

/*
 Compilator entities structure.
 */
struct Compiler_entities { //TODO вынести в отдельный файл
private:
    Lexer *lexer;
    Parser *parser;
    Linker *linker;
    Preprocessor *preprocessor;
    Assembly_generator *asm_gen;
    Binary_generator *bin_gen;
    Analyzer *analyzer;

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
            this->analyzer = Analyzer::GetInstance();

            this->s_context = new Strategy_context;
        } catch (std::exception &e) {
            colored_txt_output("Error in initializing global compiler entities.", Color::red);
            throw e;
        }
    }

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
            delete this->analyzer;

            delete this->s_context;
        } catch (std::exception &e) {
            colored_txt_output("Error in destroying global compiler entities.", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting lexer
     Return - lexer
     */
    [[nodiscard]] Lexer *Compiler_entities::get_lexer() const {
        try {
            return lexer;
        } catch (std::exception &e) {
            colored_txt_output("Error in return lexer", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting parser
     Return - parser
     */
    [[nodiscard]] Parser *Compiler_entities::get_parser() const {
        try {
            return parser;
        } catch (std::exception &e) {
            colored_txt_output("Error in return parser", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting linker
     Return - linker
     */
    [[nodiscard]] Linker *Compiler_entities::get_linker() const {
        try {
            return linker;
        } catch (std::exception &e) {
            colored_txt_output("Error in return linker", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting preprocessor
     Return - preprocessor
     */
    [[nodiscard]] Preprocessor *Compiler_entities::get_preprocessor() const {
        try {
            return preprocessor;
        } catch (std::exception &e) {
            colored_txt_output("Error in return preprocessor", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting binary generator
     Return - binary generator
     */
    [[nodiscard]] Binary_generator *Compiler_entities::get_binary_generator() const {
        try {
            return bin_gen;
        } catch (std::exception &e) {
            colored_txt_output("Error in return assembly generator", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting Assembly generator
     Return - Assembly generator
     */
    [[nodiscard]] Assembly_generator *Compiler_entities::get_assembly_generator() const {
        try {
            return asm_gen;
        } catch (std::exception &e) {
            colored_txt_output("Error in return assembly generator", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting Analyzer
     Return - Analyzer
     */
    [[nodiscard]] Analyzer *Analyzer::get_analyzer() const {
        try {
            return analyzer;
        } catch (std::exception &e) {
            colored_txt_output("Error in return analyzer", Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting strategy context
     Return - strategy context
     */
    [[nodiscard]] Strategy_context *Compiler_entities::get_strategy_context() const {
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
    //additional compilation params
    const_string ASSEMBLER = "assembler"; //output assembler file
    const_string VM = "vm"; //turns on virtual machine
    const_string AI = "ai"; //turns on artificial intelligence **only on vm mode
    const_string BINARY = "binary"; //outputs binary file
    const_string COMPILE = "compile"; //only compile and blow out executable file

    //main compilation params
    const_string MODE = "mode"; //compiler modes, ex.debug or release
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
        this->compiler_mode = DEBUG;
    }
};
