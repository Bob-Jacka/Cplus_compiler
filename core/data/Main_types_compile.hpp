/*
Header file with compile types included
 */

#ifndef MAIN_TYPES_COMPILE_HPP
#define MAIN_TYPES_COMPILE_HPP

//Strategies
#include "functional/strategies/declaration/Strategy_context.hpp"

//Include compiler entities.
#include "IMain_types.hpp"
#include "entities/compile_entities/declaration/Lexer.hpp"
#include "entities/compile_entities/declaration/Linker.hpp"
#include "entities/compile_entities/declaration/Preprocessor.hpp"
#include "entities/compile_entities/declaration/Assembly_generator.hpp"
#include "entities/compile_entities/declaration/Parser.hpp"
#include "entities/compile_entities/declaration/Binary_generator.hpp"
#include "entities/compile_entities/declaration/Analyzer.hpp"

/*
 Puck of compiler entities
 */
struct Compiler_entities final : IMainTypes {
local:
    Lexer *lexer;
    Parser *parser;
    Linker *linker;
    Preprocessor *preprocessor;
    Assembly_generator *asm_gen;
    Binary_generator *bin_gen;
    Analyzer *analyzer;

    Strategy_context *s_context;

global:
    Compiler_entities() = default;

    ~Compiler_entities() override = default;

    void init_entities() override {
        try {
            lexer = Lexer::GetInstance();
            parser = Parser::GetInstance();
            linker = Linker::GetInstance();
            preprocessor = Preprocessor::GetInstance();
            asm_gen = Assembly_generator::GetInstance();
            bin_gen = Binary_generator::GetInstance();
            analyzer = Analyzer::GetInstance();

            s_context = new Strategy_context(null);
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in initializing global compiler entities.", utility::Color::red);
            throw e;
        }
    }

    /*
    Function for destroying created entities.
    */
    void destroy_entities() override {
        try {
            del lexer;
            del parser;
            del linker;
            del preprocessor;
            del asm_gen;
            del bin_gen;
            del analyzer;

            del s_context;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in destroying global compiler entities.", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting lexer
     Return - lexer
     */
    [[nodiscard]] auto get_lexer() const -> Lexer * {
        try {
            return lexer;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return lexer", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting parser
     Return - parser
     */
    [[nodiscard]] auto get_parser() const -> Parser * {
        try {
            return parser;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return parser", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting linker
     Return - linker
     */
    [[nodiscard]] auto get_linker() const -> Linker * {
        try {
            return linker;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return linker", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting preprocessor
     Return - preprocessor
     */
    [[nodiscard]] auto get_preprocessor() const -> Preprocessor * {
        try {
            return preprocessor;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return preprocessor", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting binary generator
     Return - binary generator
     */
    [[nodiscard]] auto get_binary_generator() const -> Binary_generator * {
        try {
            return bin_gen;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return assembly generator", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting Assembly generator
     Return - Assembly generator
     */
    [[nodiscard]] auto get_assembly_generator() const -> Assembly_generator * {
        try {
            return asm_gen;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return assembly generator", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting Analyzer
     Return - Analyzer
     */
    [[nodiscard]] auto get_analyzer() const -> Analyzer * {
        try {
            return analyzer;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return analyzer", utility::Color::red);
            throw e;
        }
    }

    /*
     Error safety method for getting strategy context
     Return - strategy context
     */
    [[nodiscard]] auto get_strategy_context() const -> Strategy_context * {
        try {
            return s_context;
        } catch (std::exception &e) {
            utility::colored_txt_output("Error in return strategy context", utility::Color::red);
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
    global:
    mutable bool is_vm = false; //(Mode) Enters virtual machine mode.
    mutable bool is_cplus_only = false; //(Mode) generates only executable file.

    mutable bool is_ai = false; //Turns on artificial intelligence to tell you that your code on cp is sh*t.
    mutable bool is_assembler = false; //Generates assembly file, that you can watch.
    mutable bool is_binary = false; //Generates binary file that you can watch.

    mutable Compile_mode compiler_mode; // Debug or release or dev or test.

    Load_compiler_parameter(const bool is_vm,
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
    Load_compiler_parameter() {
        this->is_vm = false;
        this->is_cplus_only = false;
        this->is_ai = false;
        this->is_assembler = false;
        this->is_binary = false;
        this->compiler_mode = DEBUG;
    }
};

#endif
