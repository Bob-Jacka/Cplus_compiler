/*
Compiler entry point.
*/

//Useful header files.
#include <Variables.hpp>
#include <UtilFuncs.hpp>
#include <Global_data.hpp>
#include <Main_types.hpp>

void check_flags(string []str_to_check);
void assign_strategy();

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		try
		{
			check_flags(*argv[]);
			if (assign_strategy() == 1) {
				program_entites->s_context->doLogic(); //Main logic to proceed.
			} else {
				throw "Strategy context has not been initialized."
			}
		}
		catch(const std::exception& e)
		{
			utility::colored_txt_output("Error occured in main function.");
			std::cerr << e.what() << '\n';
		}
	} else if (argc == 1) {
		throw "Wrong argument count, expected two or more with flags, given 1 argument.";
	}
	utility::colored_txt_output("Bye!");
};

/*
Fuction for assigning strategy for the compiler flow.
Returns 1 if strategy assigned.
*/
int assign_strategy() {
	if (load_parameter.is_cplus_only) {
		utility::colored_txt_output("Using compile strategy.");
		program_entites.s_context.set_strategy(CompileStrategy());
		return 1;
	} else if (load_parameter.is_vm) {
		utility::colored_txt_output("Using virtual machine strategy.");
		program_entites.s_context.set_strategy(VMStrategy());
		return 1;
	}
}

/*
Функция для проверки флагов командной строки.
*/
void check_flags(string []str_to_check)
{
	auto check_func_full{[](string str) -> bool { return contains(str, "="); }};
	for (auto argument : str_to_check) {
		if (check_func_full(argument))
			{
				string split_line[] = line_splitter(str_to_check, "=");
				string flag_name = strings.ToLower(strings.ReplaceAll(split_line[0], "-", ""));
				string flag_value = split_line[1];
				switch (flag_name)
				{
					case ASSEMBLER:
						load_parameter.is_assembler = atob(flag_value);
						break;
					case VM:
						load_parameter.is_vm = atob(flag_value);
						break;
					case AI:
						load_parameter.is_ai = atob(flag_value);
						break;
					case BINARY:
						load_parameter.is_binary = atob(flag_value);
						break;
					case COMPILE:
						load_parameter.is_cplus_only = atob(flag_value);
						break;
					default : 
						colored_txt_output("Unknown flag: " + flag_name, "red");
						os.Exit(1);
				}
			}
		else {
				controllers->file_controller.open_file(str_to_check);
		}
	}
}
