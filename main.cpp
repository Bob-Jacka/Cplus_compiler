/*
Compiler entry point.
*/

#include <Variables.hpp>
#include <UtilFuncs.hpp>

#include <entities/Lexer.cpp>
#include <entities/Linker.cpp>
#include <entities/Preprocessor.cpp>
#include <entities/Assembly_generator.cpp>

struct Comp_params
{
private:
	Lexer *lexer;
	Linker *linker;
	Preprocessor *preprocessor;
	Assembly_generator *asm_gen;

	void init_entities()
	{
		this->lexer = new Lexer();
		this->linker = new Linker();
		this->preprocessor = new Preprocessor();
		this->asm_gen = new Assembly_generator();
	};

	void destroy_entities()
	{
		delete this->lexer;
		delete this->linker;
		delete this->preprocessor;
		delete this->asm_gen;
	};
};

int main(int argc, char *argv[])
{
	Comp_params * program_entites = new Comp_params();
	if (argc == 2)
	{
		//
	}
};

/*
Функция для проверки флагов командной строки.
*/
void check_flags(string str_to_check)
{
	auto check_func_full{[](string str) -> bool
						 { return contains(str, "="); }};
	if (check_func_full(str_to_check))
	{
		string split_line[] = strings.Split(str_to_check, "=");
		string flag_name = strings.ToLower(strings.ReplaceAll(split_line[0], "-", ""));
		string flag_value = split_line[1];
		switch (flag_name)
		{
		case "suit":
		load_parameter.Suit = flag_value break case "devices":
		load_parameter.Devices = flag_value break case "file_save":
		load_parameter.File_save, _ = strconv.ParseBool(flag_value) break case "file_load":
		load_parameter.File_load, _ = strconv.ParseBool(flag_value) break case "tc_time":
		load_parameter.Tc_time, _ = strconv.ParseBool(flag_value) break case "high_prior":
		load_parameter.High_prior, _ = strconv.ParseBool(flag_value) break case "random_run":
		load_parameter.Random_run, _ = strconv.ParseBool(flag_value) break case "comments":
		load_parameter.Comments, _ = strconv.ParseBool(flag_value) break case "colored":
			load_parameter.Colored, _ = strconv.ParseBool(flag_value) break default : colored_txt_output("Unknown flag: " + flag_name, red)
																						  os.Exit(1)
		}
	}
	else
	{
		colored_txt_output("Error occurred in check_flag func.", red);
		exit(1);
	}
}
