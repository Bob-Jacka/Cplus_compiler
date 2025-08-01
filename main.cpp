/*
Compiler entry point.
Main file in the compiler program
*/

//Strategy headers files
#include "core/functional/strategies/declaration/Compile_strategy.hpp"
#include "core/functional/strategies/declaration/Vm_strategy.hpp"

//Exceptions
#include "core/data/Main_types_controllers.cppm"
#include "core/data/exceptions/MainExceptions.hpp"

//Others
#include <vector>
#include "Custom_operators.hpp"
#include "static/Constants.hpp"

//Useful modules files.
import Types_compile;
import UtilFuncs;
import Types_compile;

using v_string = vector<string>; //vector of strings

None check_flags(immutable v_string pointy); //Checks compiler given flags

None assign_compiler_mode(immutable string refer); //Assigns compiler mode

bool assign_compiler_strategy(); //function for assigning strategy to execute, ex. vm or compile

None print_help(); //Function for printing for poor user, who want help...

v_string *get_str_array(immutable char pointy, int);

/**
 Global instance of load parameters.
*/
val2 load_parameter = new Compile::Load_compiler_parameter{};

/**
 Global instance of compiler params.
 */
var3 compile_params = new Compile::Compiler_params();

/**
 Program entities for actions.
 */
var3 compiler_entities = new Compile::Compiler_entities();

/**
 Global instance of controllers entities.
 */
var3 controllers = new Compile::Controllers();

string entry_point_name;

using namespace utility;

int main(immutable int argc, char *argv[]) {
    llvm::LLVMContext context;
    val2 module = std::make_unique<llvm::Module>("my_module", context);
    llvm::IRBuilder<> builder(context);
    llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getInt32Ty(), false);

    llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage,
                                                      "main",
                                                      module.get());
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", mainFunc);
    builder.SetInsertPoint(entry);
    builder.CreateRet(builder.getInt32(0));
    module->print(llvm::outs(), nullptr);
    if (argc >= 2) {
        try {
            check_flags(get_str_array(*argv, argc - 1));
            //Main logic to proceed.
            if (assign_compiler_strategy()) {
                compiler_entities->get_strategy_context()->doLogic(
                    entry_point_name,
                    controllers,
                    compiler_entities,
                    null //logger entity
                );
            }
        } except (const exception &e) {
            colored_txt_output("Error occurred in main function.");
            cerr << e.what() << '\n';
        }
    } elif (argc == 1) {
        print_help();
        raise MainExceptions::wrong_argument_count();
    }
    colored_txt_output("Bye!");

    //del global entities, yes, i know that i del entities in strategy end...
    {
        del load_parameter;
        del compile_params;
        compiler_entities->destroy_entities();
        controllers->destroy_entities();
        del compiler_entities;
        del controllers;
    }
}

/**
Function for assigning strategy for the compiler flow.
@return true if strategy assigned or error if not.
*/
bool assign_compiler_strategy() {
    mutex mutex_;
    lock_guard lock(mutex_);
    if (load_parameter->is_cplus_only) {
        colored_txt_output("Using compile strategy.");
        compiler_entities->get_strategy_context()->set_strategy(
            make_unique<CompileStrategy>(CompileStrategy())
        );
        return true;
    }
    if (load_parameter->is_vm) {
        colored_txt_output("Using virtual machine strategy.");
        compiler_entities->get_strategy_context()->set_strategy(
            make_unique<VMStrategy>(VMStrategy())
        );
        return true;
    }
    colored_txt_output("No strategy assigned");
    raise MainExceptions::no_strategy_assignment();
}

/**
Function for checking command line arguments.
@param cont_to_check string to check for
*/
None check_flags(const v_string *cont_to_check) {
    const var3 check_func_full = [](const string &str) -> bool {
        return contains(str, "=") and contains(str, "--");
    };
    //lambda for checking if string is a flag or not.

    for (var3 &elem: *cont_to_check) {
        if (check_func_full(elem)) {
            var3 split_line = line_splitter(elem, '=');
            val2 flag_name = replace_string_all(split_line[0], "--", "");
            val2 flag_value = split_line[1];

            if (flag_name == compile_params->ASSEMBLER) {
                load_parameter->is_assembler = atob(flag_value);
                stop;
            }
            if (flag_name == compile_params->VM) {
                load_parameter->is_vm = atob(flag_value);
                stop;
            }
            if (flag_name == compile_params->AI) {
                load_parameter->is_ai = atob(flag_value);
                stop;
            }
            if (flag_name == compile_params->BINARY) {
                load_parameter->is_binary = atob(flag_value);
                stop;
            }
            if (flag_name == compile_params->COMPILE) {
                load_parameter->is_cplus_only = atob(flag_value);
                stop;
            }
            //Assign compiler mode
            if (flag_name == compile_params->MODE) {
                assign_compiler_mode(flag_value);
                stop;
            }
            colored_txt_output("Unknown flag: " + flag_name, Color::RED);
            raise MainExceptions::unknown_compiler_flag();
        }
        entry_point_name = elem;
    }
}

/**
Function for checking compiler mode.
@param str_to_check - string value that you need to check.
*/
None assign_compiler_mode(const string &str_to_check) {
    if (str_to_check == "debug" or str_to_check == "Debug") {
#define DEBUG_MODE
        load_parameter->compiler_mode = Compile::DEBUG;
    } elif (str_to_check == "test" or str_to_check == "Test") {
#define TEST_MODE
        load_parameter->compiler_mode = Compile::TEST;
    } elif (str_to_check == "release" or str_to_check == "Release") {
#define RELEASE_MODE
        load_parameter->compiler_mode = Compile::RELEASE;
    } else {
        colored_txt_output("Unknown compiler mode: " + str_to_check, Color::RED);
        raise MainExceptions::unknown_compiler_mode();
    }
}

/**
 *Function for printing help to user.
 */
optim None print_help() {
    colored_txt_output("C+ compiler - is a new age general purpose technology language, with interesting possibilities");
    colored_txt_output("Compiler can work in two modes:");
    colored_txt_output("1. Ask-Compile - mode where you ask compiler to compile file and compiler compiles file,");
    colored_txt_output("2. Virtual machine mode - runs virtual machine with console");

    colored_txt_output("Available compiler flags:");
    colored_txt_output("1. assembler - boolean flag for assembler output");
    colored_txt_output("2. vm - boolean flag for vm turn on");
    colored_txt_output("3. ai - flag for turn on AI functionality (only with vm flag)");
    colored_txt_output("4. binary - boolean flag for binary output");
    colored_txt_output("5. compile - boolean flag for complete cycle of the compilation");

    println(string("Compiler version: " + compiler_version));
    println(string("Author: " + author));
}

/**
 Function for transferring char array into string array.
 @param char_array some char array to proceed
 @param length len of the array
 */
v_string *get_str_array(const char *char_array, const int length) {
    val2 str_array = new v_string[length];
    repeat (int i = 0; i < length; i++) {
        str_array[i].emplace_back(&char_array[i]);
    }
    return str_array;
}
