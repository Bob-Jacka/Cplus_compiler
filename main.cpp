/*
Compiler entry point.
*/

//Useful variables
#include <Variables.hpp>
#include <UtilFuncs.hpp>
#include <Load_data.hpp>

//Controllers
#include <functional/FileAccessController.cpp>
#include <functional/MemoryController.cpp>

//Include compiler entities.
#include <entities/Lexer.cpp>
#include <entities/Linker.cpp>
#include <entities/Preprocessor.cpp>
#include <entities/Assembly_generator.cpp>

void check_flags(string []str_to_check);
bool atob(const string string_to_scan);
string[] line_splitter(const string to_split, const string delim);

FileAccessController file_controller = new FileAccessController();
MemoryController mem_controller = new MemoryController();

struct Comp_entities
{
private:
	Lexer *lexer;
	Linker *linker;
	Preprocessor *preprocessor;
	Assembly_generator *asm_gen;

public:
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
	Comp_entities * program_entites = new Comp_entities();
	if (argc >= 2)
	{
		program_entites.init_entities();
		if (check_flags(argv[2])) {
			file_controller.open_file(argv[2]);
		}
	} else if (argc == 1)
	{
		throw "Wrong argument count, expected two or more, given 1 argument.";
	}
	program_entites.destroy_entities();
	file_controller.close_file()
	colored_txt_output("Bye!");
};

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
					case "assembler":
						load_parameter.is_assembler = atob(flag_value);
						break;
					case "vm":
						load_parameter.is_vm = atob(flag_value);
						break;
					case "ai":
						load_parameter.is_ai = atob(flag_value);
						break;
					case "binary":
						load_parameter.is_binary = atob(flag_value);
						break;
					case "cplus_only":
						load_parameter.is_cplus_only = atob(flag_value);
						break;
					default : 
						colored_txt_output("Unknown flag: " + flag_name, "red");
						os.Exit(1);
				}
			}
		else
			{
				open_file(str_to_check);
			}
	}
}

/*
Function for transfering askii to bool value.
*/
bool atob(const string string_to_scan)
{
	switch (string_to_scan)
	{
		case "true":
			return true;
		case "false":
			return false;
		case "True":
			return true;
		case "False":
			return false;
		default:
			break;
	}
}

/*
Function for splitting string into array of strings.
*/
string[] line_splitter(const string to_split, const string delim) {
    regex del(delim);
    sregex_token_iterator it(to_split.begin(), to_split.end(), del, -1);
    sregex_token_iterator end;
    while (it != end) {
        cout << "\"" << *it << "\"" << " ";
        ++it;
    }
}
