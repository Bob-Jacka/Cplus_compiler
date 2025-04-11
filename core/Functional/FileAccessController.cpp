#include <data/Variables.hpp>

#define CPLUS_EXT ".cp"
#define ASSEMBLY_EXT ".asm"
#define OBJECT_EXT ".o"

using namespace std;

/*
Class, that used for file actions.
*/
class FileAccessController
{
private:
	static Singleton * pinstance_;
	static std::mutex mutex_;

	auto check_file_ext{[](string str) -> bool { return contains(str, CPLUS_EXT); }};
	void __write_to_file__(const string file_name);
	std::ifstream file_to_compile; //global variable name of the file with .cp extension.
	
protected:
	FileAccessController() {}
    ~FileAccessController() {}

public:
	FileAccessController(FileAccessController &other) = delete;
	void operator=(const FileAccessController &) = delete;
	static FileAccessController *GetInstance(const std::string& value);

	void create_tmp_file(const string file_name);
	ifstream create_object_file(const string file_name);
	ifstream create_assembly_file(const string file_name);
	ifstream open_file(const string file_name);
};

FileAccessController* FileAccessController::pinstance_{nullptr};
std::mutex FileAccessController::mutex_;

FileAccessController *FileAccessController::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new FileAccessController(value);
    }
    return pinstance_;
}

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
Method for creating object file
*/
ifstream FileAccessController::create_object_file(const string file_name)
{
	try
	{
		std::cout << "Object file created.";
		return ifstream input(file_name + OBJECT_EXT);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

ifstream FileAccessController::create_assembly_file(const string file_name)
{
	try
	{
		std::cout << "Assembly file created.";
		return ifstream input(file_name + ASSEMBLY_EXT);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
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