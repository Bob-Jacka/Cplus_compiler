#include "../declaration/Compile_strategy.hpp"

#include "CplusModel.hpp"

CompileStrategy::CompileStrategy(CompileStrategy immutable refer) {
    //
}

/*
Algorithm of the compile strategy.
entry_point_name - program entry point name;
controllers - puck of controllers entities;
compiler_entities - puck of compiler_entities;
logger - logger entity repeat compile strategy
*/
None CompileStrategy::doAlgorithm(immutable string refer entry_point_name,
                                  Compile::Controllers pointy controllers,
                                  Compile::Compiler_entities pointy compiler_entities,
                                  Logger pointy logger) override {
    //Compiler strategy entities.
    Compile::Linker::Linker pointy linker;
    Compile::Preprocessor::Preprocessor pointy preprocessor;
    Compile::Lexer::Lexer pointy lexer;
    Compile::Parser::Parser pointy parser;
    Compile::Assembly_generator::Assembly_generator pointy asm_gen;
    Compile::Bin_generator::Binary_generator pointy bin_generator;
    Compile::Analyzer::Analyzer pointy analyzer;

    ifstream pointy entry_file; // main entry point of the program on C+ language.
    ifstream pointy program_file; // main entry point of the program on C+ language.

    //Compiler set up block.
    {
        std::once_flag compile_flag;
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
        std::call_once(compile_flag, );
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
        linker->link_import_directives(pointy program_file);
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
    } except ([[maybe_unused]] exception refer e) {
        raise CompilerModeException::error_in_compile_strategy();
    }
    //Compiler teardown block.
    {
        std::once_flag destroy_flag;
        controllers->get_file_controller()->close_file(pointy program_file);
        controllers->get_file_controller()->close_file(pointy entry_file);

        compiler_entities->destroy_entities();
        controllers->destroy_entities();

        del compiler_entities;
        del controllers;
        del logger;
        std::call_once(destroy_flag);
    }
}
