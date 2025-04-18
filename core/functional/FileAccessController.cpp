#include <data/Variables.hpp>
#include <UtilFuncs.hpp>
#include <mutex>

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
	static FileAccessController *pinstance_;
	static mutex mutex_;

	void __write_to_file__(const string file_name);
	FileAccessController() {}
	
public:
	~FileAccessController() {}
	FileAccessController(FileAccessController &other) = delete;
	void operator=(const FileAccessController &) = delete;

	static FileAccessController *GetInstance();

	//Create different types of files.
	ifstream create_tmp_file(const string file_name);
	ifstream create_object_file(const string file_name);
	ifstream create_assembly_file(const string file_name);

	//Crud operations on files.
	bool delete_file(const char* file_to_delete) const;
	ofstream* copy_file(string input, string output_file) const;
	ifstream* open_file(const string file_name) const;
	void close_file(ifstream& opened_file) const;
};

FileAccessController *FileAccessController::pinstance_{nullptr};
mutex FileAccessController::mutex_;

FileAccessController *FileAccessController::GetInstance()
{
	lock_guard<mutex> lock(mutex_);
	if (pinstance_ == nullptr)
	{
		pinstance_ = new FileAccessController();
	}
	return pinstance_;
}

void FileAccessController::__write_to_file__(const string file_name)
{
	//
}

/*
Function for creating temporary file with given name.
*/
ifstream FileAccessController::create_tmp_file(const string file_name)
{
	try
	{
		cout << "Temporary file created.";
		ifstream input(file_name);
		return input;
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;
	}
}

/*
Method for creating object file with given name.
*/
ifstream FileAccessController::create_object_file(const string file_name)
{
	try
	{
		cout << "Object file created.";
		ifstream input(file_name + OBJECT_EXT);
		return input;
	}
	catch (const exception &e)
	{
		cerr << e.what() << endl;
	}
}

ifstream FileAccessController::create_assembly_file(const string file_name)
{
	try
	{
		cout << "Assembly file created.";
		ifstream input(file_name + ASSEMBLY_EXT);
		return input;
	}
	catch (const exception &e)
	{
		cerr << e.what() << endl;
	}
}

/*
Define macros method only for unix like systems;
*/
#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	#define create_block_file "\
	ifstream create_block_file(const char* file_name);\
	ifstream FileAccessController::create_block_file(const char* file_name)\
		{\
			int fd = -1;\
			while (fd == -1) {\
				fd = open(file_name, O_CREAT | O_EXCL | O_WRONLY, 0500);\
			}\
			char pid[6];\
			itoa(getpid(), pid, 10);\
			write(fd, pid, strlen(pid));\
			close(fd);\
			int mainfd = open("somefile", O_WRONLY, 0500);\
			close(mainfd);\
			unlink("somefile.lock");\
		}"
#endif

/*
Delete file by file controller.
*/
bool FileAccessController::delete_file(const char* file_to_delete) const
{
	try {
		cout << file_to_delete << " - file deleted.";
		int res = remove(file_to_delete);
		return res;
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}
}

/*
Method for coping one file strings into another file.
Input - which file you want to add (file name).
Output_file - into which file you want to add (file name).
Return - link on input file.
*/
ofstream* FileAccessController::copy_file(string file_name_to_include, string output_file) const
{
	ifstream infile;
	ofstream outfile;

	try {
		infile.open(file_name_to_include);
		outfile.open(output_file);

		char buffer[1000];

		while (!infile.eof())
		{
			infile.getline(buffer, sizeof(buffer));
			outfile << buffer << endl;
		}
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}
	infile.close();
	return &outfile;
}

/*
Method for opening .cp file.
Throws error if file of wrong extension.
*/
ifstream* FileAccessController::open_file(string file_name) const
{
	if (utility::contains(file_name, CPLUS_EXT))
	{
		try
		{
			cout << "File opened.";
			ifstream out;
			out.open(file_name);
			return &out;
		}
		catch (const exception &e)
		{
			cerr << e.what() << endl;
		}
	}
	else
	{
		throw "File of wrong extesion";
	}
}

/*
Methor that responsible for closing file.
*/
void FileAccessController::close_file(ifstream& opened_file) const
{
	try
	{
		cout << "File closed.";
		opened_file.close();
	}
	catch (const exception &e)
	{
		cerr << e.what() << endl;
	}
}