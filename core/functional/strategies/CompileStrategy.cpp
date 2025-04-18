#include <IStrategy.cpp>
#include <Global_data.hpp>
#include <fstream>
#include <Main_types.hpp>
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
};

/*
Algoritm of the compile strategy.
Params - program entry point name;
*/
void CompileStrategy::doAlgorithm(string file_name) const
{
    //Compiler strategy entities.
    Linker* linker;
    Preprocessor* preprocessor;
    Lexer* lexer;
    Assembly_generator* asm_gen;
    Binary_generator* bin_generator;
    std::ifstream entry_file; // main entry point of the program on C+ language.
    std::ifstream program_file;

    //Compiler set up block.
    {
        program_entites->init_entities();
        controllers->init_controllers();

        linker = program_entites->getLinker();
        preprocessor = program_entites->getPreprocessor();
        lexer = program_entites->getLexer();
        asm_gen = program_entites->getAssemblyGenerator();
        bin_generator = program_entites->getBinaryGenerator();
    }

    #define TMP_FILE_NAME "prog_tmp"

    //Algorithm flow
    if (file_name == MAIN_FILE_NAME) {
        entry_file = controllers->file_controller.open_file(file_name);
    }
    else {
        throw "Main file not found";
    }
    
    program_file = controllers->file_controller.create_tmp_file(TMP_FILE_NAME); //create tmp file
    controllers->file_controller.copy_file(file_name, TMP_FILE_NAME); //copy all lines into tmp file from main file of the cp program
    linker->link_import_directives(program_file); //copy all include directives into tmp file.
    preprocessor->preprocess();

    //Compiler teardown block.
    {
        controllers->file_controller.close_file(entry_file);

        program_entites->destroy_entities();
        controllers->destroy_controllers();

        delete program_entites;
        delete controllers;
    }
}
