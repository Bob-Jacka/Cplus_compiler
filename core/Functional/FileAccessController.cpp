#include <data/Variables.hpp>
#include <fstream>

using namespace std;

/*
Class, that used for file actions.
*/
class FileAccessController
{
private:
	auto check_file_ext{[](string str) -> bool { return contains(str, ".cp"); }};
	void __write_to_file__(const string file_name);
	std::ifstream file_to_compile; //global variable name of the file with .cp extension.

public:
	FileAccessController(/* args */) {}
	~FileAccessController() {}
	void create_tmp_file(const string file_name);
	ifstream open_file(const string file_name);
};

void FileAccessController::__write_to_file__(const string file_name) {
    fstream input(file_name);
}

/*
Function for creating temporary file.
*/
void FileAccessController::create_tmp_file(const string file_name) {
	//
}

/*
Function for opening file.
*/
ifstream FileAccessController::open_file(const string file_name)
{
	if (check_file_ext(file_name)) {
		try
		{
			ifstream out;          // поток для записи
			out.open(file_name); // окрываем файл для записи
			file_to_compile = out;
		}
		catch(const exception& e)
		{
			cerr << e.what() << '\n';
		}
	} else {
		throw "File of wrong extesion";
	}
	return nullptr;
}

/*
Methor that responsible for closing file.
*/
void FileAccessController::close_file() {
	try
	{
		file_to_compile.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}