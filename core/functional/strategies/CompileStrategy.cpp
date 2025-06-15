#include "core/functional/strategies/IStrategy.cpp"
#include "core/data/Main_types.hpp"
#include "core/data/exceptions/CompilerModeException.cpp"
#include <fstream>
#include <CplusModel.hpp>

/*
Strategy that compiles program into executable file.
*/
class CompileStrategy : Strategy
{
public:
    CompileStrategy() {};
    ~CompileStrategy() {};
    void doAlgorithm(string file_name) const;

private:
    Load_compiler_parameter* load_parameter = new Load_compiler_parameter{}; //Global instance of load parameters.
    Compiler_params* compile_params = new Compiler_params(); //Global instance of compiler params.

    Compiler_entities* program_entites = new Compiler_entities(); //Programm entities for actions.
    Controllers* controllers = new Controllers(); //Global instance of controllers entities.

    Logger* logger = new Logger(); //Global instance of logger in cp compiler

    string TMP_FILE_NAME = "prog_tmp"; //tmp file for temporary information.
};

/*
Algoritm of the compile strategy.
Params - program entry point name;
*/
void CompileStrategy::doAlgorithm(string file_name) const
{
    //Compiler strategy entities.
    unique_ptr<Linker> linker;
    unique_ptr<Preprocessor> preprocessor;
    unique_ptr<Lexer> lexer;
    unique_ptr<Parser> parser;
    unique_ptr<Assembly_generator> asm_gen;
    unique_ptr<Binary_generator> bin_generator;
    
    std::ifstream entry_file; // main entry point of the program on C+ language.
    std::ifstream program_file; // main entry point of the program on C+ language.

    //Compiler set up block.
    {
        program_entites->init_entities();
        logger->log("Entities initialized");
        controllers->init_controllers();
        logger->log("Controllers initialized");

        linker = program_entites->getLinker();
        preprocessor = program_entites->getPreprocessor();
        lexer = program_entites->getLexer();
        parser = program_entites->getParser();
        asm_gen = program_entites->getAssemblyGenerator();
        bin_generator = program_entites->getBinaryGenerator();
    }

    //Algorithm flow
    /*
       file_name -> entry_file -> program_file
    */
    
    if (file_name == MAIN_FILE_NAME) {
        entry_file = controllers->getFileController()->open_file(file_name);
    }
    else {
        throw CompilerModeException::mainNotFound();
    }

    try
    {
        program_file = controllers->getFileController()->create_tmp_file(TMP_FILE_NAME); //create tmp file

        controllers->getFileController()->copy_file(file_name, TMP_FILE_NAME); //copy all lines into tmp file from main file of the cp program

        linker->link_import_directives(program_file); //copy all include directives into tmp file.

        logger->log("Directives imported");

        preprocessor->preprocess(); //include all directives, ex. import define

        logger->log("Preprocessor finished work");

        auto tokens = lexer->tokenize(); //lex analyze of the program text and tokenize

        logger->log("Tokenizer finished work");

        auto parsed_tokens = parser->parse_tokens(tokens); //parse lexemes and build tree

        asm_gen->generate_asm(parsed_tokens);  //generation of the assembly representation.

        bin_generator->generate_binary(); //generation of the binary representation.
    }
    catch(exception& e) {
        throw CompileModeException::errorInCompileStrategy();
    }

    //Compiler teardown block.
    {
        controllers->getFileController()->close_file(program_file);
        controllers->getFileController()->close_file(entry_file);

        program_entites->destroy_entities();
        controllers->destroy_controllers();

        delete program_entites;
        delete controllers;
    }
}
