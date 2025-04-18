/*
Compiler entry point.
*/

//Useful header files.
#include <Variables.hpp>
#include <UtilFuncs.hpp>
#include <Global_data.hpp>
#include <Main_types.hpp>

//Strategy headers files
#include <functional/strategies/CompileStrategy.cpp>
#include <functional/strategies/VMStrategy.cpp>
	
static void check_flags(char * str_to_check);
int assign_strategy();
static void assign_compiler_mode(string str_to_check);

using namespace utility;

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		try
		{
			check_flags(*argv);
			if (assign_strategy() == 1) {
				program_entites->s_context->doLogic(); //Main logic to proceed.
			}
			else {
				throw "Strategy context has not been initialized.";
			}
		}
		catch(const std::exception& e)
		{
			colored_txt_output("Error occured in main function.");
			std::cerr << e.what() << '\n';
		}
	} else if (argc == 1) {
		throw "Wrong argument count, expected two or more with flags, given 1 argument.";
	}
	colored_txt_output("Bye!");
};

/*
Fuction for assigning strategy for the compiler flow.
Returns 1 if strategy assigned or 0 if not.
*/
int assign_strategy() {
	std::mutex mutex_;
	lock_guard<mutex> lock(mutex_);
	if (load_parameter->is_cplus_only) {
		colored_txt_output("Using compile strategy.");
		program_entites->s_context.set_strategy(std::make_unique <CompileStrategy>());
		return 1;
	} else if (load_parameter->is_vm) {
		colored_txt_output("Using virtual machine strategy.");
		program_entites->s_context.set_strategy(std::make_unique <VMStrategy>());
		return 1;
	}
	else {
		return 0;
	}
}

/*
Function for cheching command line arguments.
*/
static void check_flags(char * str_to_check)
{
	auto check_func_full = [](string str) -> bool { return contains(str, "="); }; //lambda for cheching if string is a flag.
	for (string argument : str_to_check) {
		if (check_func_full(argument))
			{
				string split_line[] = line_splitter(str_to_check, "=");
				string flag_name = toLowerCase(replaceStringAll(split_line[0], "-", ""));
				const char * flag_value = split_line[1];
				if (flag_name == compile_params->ASSEMBLER) {
					load_parameter->is_assembler = atob(flag_value);
					break;
				}
				else if (flag_name == compile_params->VM) {
					load_parameter->is_vm = atob(flag_value);
					break;
				}
				else if (flag_name == compile_params->AI) {
					load_parameter->is_ai = atob(flag_value);
					break;
				}
				else if (flag_name == compile_params->BINARY) {
					load_parameter->is_binary = atob(flag_value);
					break;
				}
				else if (flag_name == compile_params->COMPILE) {
					load_parameter->is_cplus_only = atob(flag_value);
					break;
				}
				else if (flag_name == compile_params->MODE) {
					assign_compiler_mode(flag_value);
					break;
				}
				else {
					colored_txt_output("Unknown flag: " + flag_name, Color::red);
					exit(1);
				}
			}
		else {
			controllers->file_controller.open_file(argument);
		}
	}
}

/*
Function for checking compiler mode.
Str_to_check - string value that you need to check.
*/
static void assign_compiler_mode(string str_to_check) {
	if (str_to_check == "debug" || str_to_check == "Debug") {
		load_parameter->compiler_mode = Compile_mode::DEBUG;
	}
	else if (str_to_check == "test" || str_to_check == "Test") {
		load_parameter->compiler_mode = Compile_mode::TEST;
		#define START_TEST
	}
	else if (str_to_check == "release" || str_to_check == "Release") {
		load_parameter->compiler_mode = Compile_mode::RELEASE;
	}
	else {
		colored_txt_output("Unknown compiler mode: " + str_to_check, Color::red);
		exit(1);
	}
}
