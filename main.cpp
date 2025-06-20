/*
Compiler entry point.
*/

//Useful header files.
#include "core/data/Variables.hpp"
#include "static/UtilFuncs.hpp"
#include "core/data/Main_types.hpp"

//Strategy headers files
#include "core/functional/strategies/CompileStrategy.cpp"
#include "core/functional/strategies/VMStrategy.cpp"

static void check_flags(char *);

static void assign_compiler_mode(const string &);

int assign_strategy();

void print_help();


/*
 *Global instance of load parameters.
*/
const Load_compiler_parameter *load_parameter = new Load_compiler_parameter{};

/*
 *Global instance of compiler params.
 */
const Compiler_params *compile_params = new Compiler_params();

/*
 *Program entities for actions.
 */
const Compiler_entities *program_entities = new Compiler_entities();

/*
 *Global instance of controllers entities.
 */
const Controllers *controllers = new Controllers();

int main(const int argc, char *argv[]) {
    if (argc >= 2) {
        try {
            check_flags(*argv);
            if (assign_strategy() == 1) {
                program_entities->getStrategyContext()->doLogic(
                    entry_point_name,
                    controllers,
                    program_entities,
                    nullptr //logger entity
                ); //Main logic to proceed.
            } else {
                throw "Strategy context has not been initialized.";
            }
        } catch (const exception &e) {
            colored_txt_output("Error occurred in main function.");
            cerr << e.what() << '\n';
        }
    } else if (argc == 1) {
        print_help();
        throw "Wrong argument count, expected two or more with flags, given 1 argument.";
    }
    colored_txt_output("Bye!");
}

/*
Function for assigning strategy for the compiler flow.
Returns 1 if strategy assigned or 0 if not.
*/
int assign_strategy() {
    mutex mutex_;
    lock_guard lock(mutex_);
    if (load_parameter->is_cplus_only) {
        colored_txt_output("Using compile strategy.");
        program_entities->getStrategyContext()->set_strategy(
            make_unique<CompileStrategy>()
        );
        return 1;
    }
    if (load_parameter->is_vm) {
        colored_txt_output("Using virtual machine strategy.");
        program_entities->getStrategyContext()->set_strategy(
            make_unique<VMStrategy>()
        );
        return 1;
    } else {
        colored_txt_output("No strategy assigned");
        return 0;
    }
}

/*
Function for checking command line arguments.
*/
static void check_flags(char *str_to_check) {
    auto check_func_full = [](const string &str) -> bool { return contains(str, "="); };
    //lambda for checking if string is a flag.
    for (const string argument: str_to_check) {
        if (check_func_full(argument)) {
            const string *split_line = line_splitter(str_to_check, "=");
            const string flag_name = toLowerCase(replaceStringAll(split_line[0], "-", ""));
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
            if (flag_name == compile_params->MODE) {
                assign_compiler_mode(flag_value);
                break;
            } else {
                colored_txt_output("Unknown flag: " + flag_name, Color::red);
                exit(1);
            }
        } else {
            controllers->getFileController()->open_file(argument);
        }
    }
}

#define START_TEST

/*
Function for checking compiler mode.
Str_to_check - string value that you need to check.
*/
static void assign_compiler_mode(const string &str_to_check) {
    if (str_to_check == "debug" || str_to_check == "Debug") {
        load_parameter->compiler_mode = Compile_mode::DEBUG;
    } else if (str_to_check == "test" || str_to_check == "Test") {
        load_parameter->compiler_mode = Compile_mode::TEST;
    } else if (str_to_check == "release" || str_to_check == "Release") {
        load_parameter->compiler_mode = Compile_mode::RELEASE;
    } else {
        colored_txt_output("Unknown compiler mode: " + str_to_check, Color::red);
        exit(1);
    }
}

inline void print_help() {
    colored_txt_output("C+ compiler - is a new age general purpose technology language");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
    colored_txt_output("");
}
