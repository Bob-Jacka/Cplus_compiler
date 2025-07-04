/*
Compiler entry point.
Main file in the compiler program
*/

//Useful header files.
#include "static/UtilFuncs.hpp"
#include "core/data/Main_types_compile.hpp"

//Strategy headers files
#include "core/functional/strategies/CompileStrategy.cpp"
#include "core/functional/strategies/VMStrategy.cpp"

//Exceptions
#include "core/data/exceptions/MainExceptions.cpp"

static void check_flags(char *); //Checks compiler given flags

static void assign_compiler_mode(const string &); //Assigns compiler mode

bool assign_strategy(); //function for assigning strategy to execute

void print_help(); //Function for printing for poor user, who want help...

/*
 Global instance of load parameters.
*/
const Load_compiler_parameter *load_parameter = new Load_compiler_parameter{};

/*
 Global instance of compiler params.
 */
const Compiler_params *compile_params = new Compiler_params();

/*
 Program entities for actions.
 */
Compiler_entities *program_entities = new Compiler_entities();

/*
 Global instance of controllers entities.
 */
Controllers *controllers = new Controllers();

string entry_point_name;

using namespace utility;

int main(const int argc, char *argv[]) {
    if (argc >= 2) {
        try {
            check_flags(*argv);
            if (assign_strategy() == 1) {
                program_entities->get_strategy_context()->doLogic(
                    entry_point_name,
                    controllers,
                    program_entities,
                    nullptr //logger entity
                ); //Main logic to proceed.
            } else {
                throw MainExceptions::context_not_initialized();
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
        program_entities->destroy_entities();
        controllers->destroy_controllers();
        delete program_entities;
        delete controllers;
    }
}

/*
Function for assigning strategy for the compiler flow.
Returns true if strategy assigned or false if not.
*/
bool assign_strategy() {
    mutex mutex_;
    lock_guard lock(mutex_);
    if (load_parameter->is_cplus_only) {
        colored_txt_output("Using compile strategy.");
        program_entities->get_strategy_context()->set_strategy(
            make_unique<CompileStrategy>(CompileStrategy())
        );
        return true;
    }
    if (load_parameter->is_vm) {
        colored_txt_output("Using virtual machine strategy.");
        program_entities->get_strategy_context()->set_strategy(
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
static void check_flags(char *str_to_check) {
    const auto check_func_full = [](const string &str) -> bool {
        return contains(str, "=") and contains(str, "--");
    };
    //lambda for checking if string is a flag.
    for (const string argument: str_to_check) {
        if (check_func_full(argument)) {
            const string *split_line = line_splitter(str_to_check, "=");
            const string flag_name = to_lower_case(replace_string_all(split_line[0], "-", ""));
            const char *flag_value = split_line[1].c_str();

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
        entry_point_name = argument;
    }
}

/*
Function for checking compiler mode.
Str_to_check - string value that you need to check.
*/
static void assign_compiler_mode(const string &str_to_check) {
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
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
}
