#include <mutex>
#include "core/data/Variables.hpp"
#include "core/entities/Logger.hpp"
#include "static/UtilFuncs.hpp"
#include "core/data/exceptions/FileAccessControllerException.cpp"

#define CPLUS_EXT ".cp"
#define ASSEMBLY_EXT ".asm"
#define OBJECT_EXT ".o"

#define TMP_FILE "tmp.txt"

using namespace std;

/*
Class, that used for file actions.
*/
class FileAccessController {
    static FileAccessController *pinstance_;
    static mutex mutex_;
    Logger *logger = nullptr; //local instance of logger in file controller.

    void __write_to_file__(const string &file_name) const;

    FileAccessController() {
        this->logger = new Logger();
    };

public:
    ~FileAccessController();

    FileAccessController(FileAccessController &other) = delete;

    void operator=(const FileAccessController &) = delete;

    static FileAccessController *GetInstance();

    //Create different types of files.
    [[nodiscard]] ifstream create_tmp_file(const string &file_name) const;

    [[nodiscard]] ifstream create_object_file(const string &file_name) const;

    [[nodiscard]] ifstream create_assembly_file(const string &file_name) const;

    //Crud operations on files.
    bool delete_file(const char *file_to_delete) const;

    [[nodiscard]] ofstream *copy_file(string input, string output_file) const;

    [[nodiscard]] ifstream *open_file(string file_name) const;

    void close_file(ifstream &opened_file) const;
};

FileAccessController *FileAccessController::pinstance_{nullptr};
mutex FileAccessController::mutex_;

//Constructor and destructor

FileAccessController::~FileAccessController() {
    delete logger;
    delete pinstance_;
}

FileAccessController *FileAccessController::GetInstance() {
    lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new FileAccessController();
    }
    return pinstance_;
}

void FileAccessController::__write_to_file__(const string &file_name) const {
    //
}

/*
Function for creating temporary file with given name.
*/
ifstream FileAccessController::create_tmp_file(const string &file_name) const {
    try {
        cout << "Temporary file created.";
        this->logger->log("Temporary file created");
        ifstream input(file_name);
        return input;
    } catch (const exception &e) {
        this->logger->log("Error in create tmp file");
        this->logger->log(e.what());
        throw FileAccessControllerExceptions::error_in_creating_tmp_file();
    }
    return nullptr;
}

/*
Method for creating object file with given name.
*/
ifstream FileAccessController::create_object_file(const string &file_name) const {
    try {
        cout << "Object file created.";
        this->logger->log("Object file created.");
        ifstream input(file_name + OBJECT_EXT);
        return input;
    } catch (const exception &e) {
        this->logger->log("Error in create object file");
        this->logger->log(e.what());
        throw FileAccessControllerExceptions::error_in_object_file();
    }
    return nullptr;
}

ifstream FileAccessController::create_assembly_file(const string &file_name) const {
    try {
        cout << "Assembly file created.";
        this->logger->log("Assembly file created.");
        ifstream input(file_name + ASSEMBLY_EXT);
        return input;
    } catch (const exception &e) {
        this->logger->log("Error in assembly file");
        this->logger->log(e.what());
        throw FileAccessControllerExceptions::error_in_assembly_file();
    }
    return nullptr;
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
bool FileAccessController::delete_file(const char *file_to_delete) const {
    try {
        cout << file_to_delete << " - file deleted.";
        const int res = remove(file_to_delete);
        return res;
    } catch (std::exception &e) {
        this->logger->log("Error in deleting file");
        this->logger->log(e.what());
        throw FileAccessControllerExceptions::error_to_delete_file();
    }
    return nullptr;
}

/*
Method for coping one file strings into another file.
Input - which file you want to add (file name).
Output_file - into which file you want to add (file name).
Return - link on input file.
*/
ofstream *FileAccessController::copy_file(string file_name_to_include, string output_file) const {
    ifstream infile;
    ofstream outfile;

    try {
        infile.open(file_name_to_include);
        outfile.open(output_file);

        char buffer[1000];

        while (!infile.eof()) {
            infile.getline(buffer, sizeof(buffer));
            outfile << buffer << endl;
        }
    } catch (std::exception &e) {
        this->logger->log("Error in copy file");
        this->logger->log(e.what());
        throw FileAccessControllerExceptions::error_in_copy_file();
    }
    infile.close();
    return &outfile;
}

/*
Method for opening .cp file.
file_name - name of the file to open.
Throws error if file of wrong extension.
*/
ifstream *FileAccessController::open_file(string file_name) const {
    if (utility::contains(file_name, CPLUS_EXT)) {
        try {
            ifstream out;
            out.open(file_name);
            cout << "File opened.";
            return &out;
        } catch (const exception &e) {
            this->logger->log("Error in open file");
            this->logger->log(e.what());
            throw FileAccessControllerExceptions::error_to_open_file();
        }
    } else {
        throw FileAccessControllerExceptions::wrong_extension();
    }
    return nullptr;
}

/*
Method that responsible for closing file.
*/
void FileAccessController::close_file(ifstream &opened_file) const {
    try {
        cout << "File closed.";
        opened_file.close();
    } catch (const exception &e) {
        this->logger->log("Error in closing file");
        this->logger->log(e.what());
        throw FileAccessControllerExceptions::error_to_close_file();
    }
}
