#include "../declaration/Compile_strategy.hpp"

CompileStrategy::CompileStrategy(CompileStrategy const &) {
    //
}

/*
Algorithm of the compile strategy.
entry_point_name - program entry point name;
controllers - puck of controllers entities;
compiler_entities - puck of compiler_entities;
logger - logger entity for compile strategy
*/
None CompileStrategy::doAlgorithm(const string &entry_point_name,
                                  Controllers *controllers,
                                  Compiler_entities *compiler_entities,
                                  Logger *logger) override {
    //Compiler strategy entities.
    Linker *linker;
    Preprocessor *preprocessor;
    Lexer *lexer;
    Parser *parser;
    Assembly_generator *asm_gen;
    Binary_generator *bin_generator;
    Analyzer *analyzer;

    ifstream *entry_file; // main entry point of the program on C+ language.
    ifstream *program_file; // main entry point of the program on C+ language.

    //Compiler set up block.
    {
        compiler_entities->init_entities();
        logger->log("Entities initialized");
        controllers->init_entities();
        logger->log("Controllers initialized");

        linker = compiler_entities->get_linker();
        preprocessor = compiler_entities->get_preprocessor();
        lexer = compiler_entities->get_lexer();
        parser = compiler_entities->get_parser();
        asm_gen = compiler_entities->get_assembly_generator();
        bin_generator = compiler_entities->get_binary_generator();
        analyzer = compiler_entities->get_analyzer();
    }

    //Algorithm flow
    /*
       file_name -> entry_file -> program_file
    */

    if (entry_point_name == MAIN_FILE_NAME) {
        entry_file = controllers->get_file_controller()->open_file(entry_point_name);
    } else {
        raise CompilerModeException::main_not_found();
    }

    try {
        //create tmp file
        program_file = controllers->get_file_controller()->create_tmp_file(TMP_FILE);
        logger->log("Program file created");

        //copy all lines into tmp file from main file of the cp program
        program_file = controllers->get_file_controller()->copy_file(entry_point_name, TMP_FILE);
        logger->log("Program file created by copying into file");

        //add file controller to linkage things
        linker->set_file_controller(controllers->get_file_controller());
        logger->log("File controller set");

        //copy all include directives into tmp file.
        linker->link_import_directives(*program_file);
        logger->log("Directives imported");

        //include all directives, ex. import define
        preprocessor->preprocess();
        logger->log("Preprocessor finished work");

        //Analyze variables and functions
        analyzer->proceed_analysis();

        //lex analyze of the program text and tokenize
        val2 tokens = lexer->tokenize(); //return tokens from lexer
        logger->log("Tokenizer finished work");

        //parse lexemes and build tree
        val2 parsed_tokens = parser->parse_tokens(tokens); //return tokens into var
        logger->log("Tokens parsed");

        //generation of the assembly representation.
        asm_gen->generate_asm(parsed_tokens);
        logger->log("Generated asm");

        //generation of the binary representation.
        bin_generator->generate_binary(controllers->get_file_controller());
        logger->log("Generated binary");
    } catch ([[maybe_unused]] exception &e) {
        raise CompilerModeException::error_in_compile_strategy();
    }
    //Compiler teardown block.
    {
        controllers->get_file_controller()->close_file(*program_file);
        controllers->get_file_controller()->close_file(*entry_file);

        compiler_entities->destroy_entities();
        controllers->destroy_entities();

        del compiler_entities;
        del controllers;
        del logger;
    }
}
