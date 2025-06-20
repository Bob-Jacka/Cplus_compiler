#include <fstream>

#include "core/data/Main_types.hpp"
#include "core/data/exceptions/CompilerModeException.cpp"
#include "core/functional/strategies/IStrategies.cpp"
#include "static/CplusModel.hpp"

/*
Strategy that compiles program into executable file.
*/
class CompileStrategy : public IStrategy {
public:
    explicit CompileStrategy(Logger *p_logger = nullptr) {
        this->p_logger = p_logger;
    }

    ~CompileStrategy() = default;

    void doAlgorithm(string entry_point_name,
                     Controllers *controllers,
                     Compiler_entities *compiler_entities,
                     Logger *logger) const;

private:
    string TMP_FILE_NAME = "prog_tmp"; //tmp file for temporary information.
};

/*
Algorithm of the compile strategy.
Params - program entry point name;
*/
void doAlgorithm(string entry_point_name,
                 Controllers *controllers,
                 Compiler_entities *compiler_entities,
                 Logger *logger) {
    //Compiler strategy entities.
    Linker *linker;
    Preprocessor *preprocessor;
    Lexer *lexer;
    Parser *parser;
    Assembly_generator *asm_gen;
    Binary_generator *bin_generator;

    ifstream entry_file; // main entry point of the program on C+ language.
    ifstream program_file; // main entry point of the program on C+ language.

    //Compiler set up block.
    {
        compiler_entities->init_entities();
        logger->log("Entities initialized");
        controllers->init_controllers();
        logger->log("Controllers initialized");

        linker = compiler_entities->getLinker();
        preprocessor = compiler_entities->getPreprocessor();
        lexer = compiler_entities->getLexer();
        parser = compiler_entities->getParser();
        asm_gen = compiler_entities->getAssemblyGenerator();
        bin_generator = compiler_entities->getBinaryGenerator();
    }

    //Algorithm flow
    /*
       file_name -> entry_file -> program_file
    */

    if (entry_point_name == MAIN_FILE_NAME) {
        entry_file = controllers->getFileController()->open_file(entry_point_name);
    } else {
        throw CompilerModeException::mainNotFound();
    }

    try {
        program_file = controllers->getFileController()->create_tmp_file(TMP_FILE); //create tmp file

        //copy all lines into tmp file from main file of the cp program
        controllers->getFileController()->copy_file(entry_point_name, TMP_FILE);

        //copy all include directives into tmp file.
        linker->link_import_directives(*program_file);

        logger->log("Directives imported");

        //include all directives, ex. import define
        preprocessor->preprocess();

        logger->log("Preprocessor finished work");

        auto tokens = lexer->tokenize(); //lex analyze of the program text and tokenize

        logger->log("Tokenizer finished work");

        std::vector<Token> *parsed_tokens = parser->parse_tokens(tokens); //parse lexemes and build tree

        asm_gen->generate_asm(parsed_tokens); //generation of the assembly representation.

        bin_generator->generate_binary(); //generation of the binary representation.
    } catch ([[maybe_unused]] exception &e) {
        throw CompilerModeException::errorInCompileStrategy();
    }

    //Compiler teardown block.
    {
        controllers->getFileController()->close_file(program_file);
        controllers->getFileController()->close_file(entry_file);

        compiler_entities->destroy_entities();
        controllers->destroy_controllers();

        delete compiler_entities;
        delete controllers;
    }
}
