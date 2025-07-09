/*
Compiler entry point.
Main file in the compiler program
*/

//Useful header files.
#include "static/Util_funcs.hpp"
#include "core/data/Main_types_compile.hpp"

//Strategy headers files
#include "core/functional/strategies/declaration/Compile_strategy.hpp"
#include "core/functional/strategies/declaration/Vm_strategy.hpp"

//Exceptions
#include "core/data/Main_types_controllers.hpp"
#include "core/data/exceptions/MainExceptions.hpp"

#include <vector>

using v_string = vector<string>; //vector of strings

void check_flags(const v_string *); //Checks compiler given flags

void assign_compiler_mode(const string &); //Assigns compiler mode

bool assign_compiler_strategy(); //function for assigning strategy to execute, ex. vm or compile

void print_help(); //Function for printing for poor user, who want help...

v_string *get_str_array(const char *, int);

/*
 Global instance of load parameters.
*/
const Load_compiler_parameter *load_parameter = new Load_compiler_parameter{};

/*
 Global instance of compiler params.
 */
auto compile_params = new Compiler_params();

/*
 Program entities for actions.
 */
auto compiler_entities = new Compiler_entities();

/*
 Global instance of controllers entities.
 */
auto controllers = new Controllers();

string entry_point_name;

using namespace utility;

int main(const int argc, char *argv[]) {
    if (argc >= 2) {
        try {
            check_flags(get_str_array(*argv, argc - 1));
            if (assign_compiler_strategy() == true) {
                compiler_entities->get_strategy_context()->doLogic(
                    entry_point_name,
                    controllers,
                    compiler_entities,
                    nullptr //logger entity
                ); //Main logic to proceed.
            }
        } catch (const exception &e) {
            colored_txt_output("Error occurred in main function.");
            cerr << e.what() << '\n';
        }
    } else if (argc == 1) {
        print_help();
        throw MainExceptions::wrong_argument_count();
    }
    colored_txt_output("Bye!");

    //Delete global entities, yes, i know that i delete entities in strategy end...
    {
        delete load_parameter;
        delete compile_params;
        compiler_entities->destroy_entities();
        controllers->destroy_controllers();
        delete compiler_entities;
        delete controllers;
    }
}

/*
Function for assigning strategy for the compiler flow.
Returns true if strategy assigned or error if not.
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
    throw MainExceptions::no_strategy_assignment();
}

/*
Function for checking command line arguments.
Returns - void
*/
void check_flags(const v_string *cont_to_check) {
    const auto check_func_full = [](const string &str) -> bool {
        return contains(str, "=") and contains(str, "--");
    };
    //lambda for checking if string is a flag or not.

    for (auto &elem: *cont_to_check) {
        if (check_func_full(elem)) {
            auto split_line = line_splitter(elem, '=');
            const auto flag_name = replace_string_all(split_line[0], "--", "");
            const auto flag_value = split_line[1];

            if (flag_name == compile_params->ASSEMBLER) {
                load_parameter->is_assembler = atob(flag_value);
                break;
            }
            if (flag_name == compile_params->VM) {
                load_parameter->is_vm = atob(flag_value);
                break;
            }
            if (flag_name == compile_params->AI) {
                load_parameter->is_ai = atob(flag_value);
                break;
            }
            if (flag_name == compile_params->BINARY) {
                load_parameter->is_binary = atob(flag_value);
                break;
            }
            if (flag_name == compile_params->COMPILE) {
                load_parameter->is_cplus_only = atob(flag_value);
                break;
            }
            //Assign compiler mode
            if (flag_name == compile_params->MODE) {
                assign_compiler_mode(flag_value);
                break;
            }
            colored_txt_output("Unknown flag: " + flag_name, Color::red);
            throw MainExceptions::unknown_compiler_flag();
        }
        entry_point_name = elem;
    }
}

/*
Function for checking compiler mode.
Str_to_check - string value that you need to check.
*/
void assign_compiler_mode(const string &str_to_check) {
    if (str_to_check == "debug" or str_to_check == "Debug") {
#define DEBUG_MODE
        load_parameter->compiler_mode = DEBUG;
    } else if (str_to_check == "test" or str_to_check == "Test") {
#define TEST_MODE
        load_parameter->compiler_mode = TEST;
    } else if (str_to_check == "release" or str_to_check == "Release") {
#define RELEASE_MODE
        load_parameter->compiler_mode = RELEASE;
    } else {
        colored_txt_output("Unknown compiler mode: " + str_to_check, Color::red);
        throw MainExceptions::unknown_compiler_mode();
    }
}

inline void print_help() {
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
}

/*
 Function for transferring char array into string array
 */
v_string *get_str_array(const char *char_array, const int length) {
    auto *str_array = new v_string[length];
    for (int i = 0; i < length; i++) {
        str_array[i].emplace_back(&char_array[i]);
    }
    return str_array;
}
