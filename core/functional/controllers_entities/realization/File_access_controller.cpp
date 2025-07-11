#include "../declaration/File_access_controller.hpp"

//Constructor and destructor

FileAccessController::~FileAccessController() {
    del logger;
    del pinstance_;
}

FileAccessController *FileAccessController::GetInstance() {
    lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new FileAccessController();
    }
    return pinstance_;
}

None FileAccessController::_write_to_file(cstr &file_name) const {
    //
}

/*
Function for creating temporary file with given name.
*/
ifstream *FileAccessController::create_tmp_file(cstr &file_name) const {
    try {
        utility::println("Temporary file created.");
        this->logger->log("Temporary file created");
        ifstream input(file_name);
        return &input;
    } catch (const exception &e) {
        this->logger->log("Error in create tmp file");
        this->logger->log(e.what());
        raise FileAccessControllerExceptions::error_in_creating_tmp_file();
    }
    return null;
}

/*
Method for creating object file with given name.
*/
ifstream FileAccessController::create_object_file(cstr &file_name) const {
    try {
        utility::println("Object file created.");
        this->logger->log("Object file created.");
        ifstream input(file_name + OBJECT_EXT);
        return input;
    } catch (const exception &e) {
        this->logger->log("Error in create object file");
        this->logger->log(e.what());
        raise FileAccessControllerExceptions::error_in_object_file();
    }
    return null;
}

ifstream FileAccessController::create_assembly_file(cstr &file_name) const {
    try {
        utility::println("Assembly file created.");
        this->logger->log("Assembly file created.");
        ifstream input(file_name + ASSEMBLY_EXT);
        return input;
    } catch (const exception &e) {
        this->logger->log("Error in assembly file");
        this->logger->log(e.what());
        raise FileAccessControllerExceptions::error_in_assembly_file();
    }
    return null;
}

/*
Define macros method only for unix like systems;
*/
#if defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	#define create_block_file " \
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
bool FileAccessController::del_file(const char *file_to_del) const {
    try {
        cout << file_to_del << " - file deleted.";
        const int res = remove(file_to_del);
        return res;
    } catch (std::exception &e) {
        this->logger->log("Error in deleting file");
        this->logger->log(e.what());
        raise FileAccessControllerExceptions::error_to_del_file();
    }
    return null;
}

/*
Method for coping one file strings into another file.
Input - which file you want to add (file name).
Output_file - into which file you want to add (file name).
Return - link on input file.
*/
ifstream *FileAccessController::copy_file(cstr &file_name_to_include, cstr &output_file) const {
    ifstream infile;
    ifstream outfile;

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
        raise FileAccessControllerExceptions::error_in_copy_file();
    }
    infile.close();
    return &outfile;
}

/*
Method for opening .cp file.
file_name - name of the file to open.
Throws error if file of wrong extension.
*/
ifstream *FileAccessController::open_file(cstr &file_name) const {
    if (utility::contains(file_name, CPLUS_EXT)) {
        try {
            ifstream out;
            out.open(file_name);
            utility::println("File opened.");
            return &out;
        } catch (const exception &e) {
            this->logger->log("Error in open file");
            this->logger->log(e.what());
            raise FileAccessControllerExceptions::error_to_open_file();
        }
    }
    raise FileAccessControllerExceptions::wrong_extension();
}

/*
Method that responsible for closing file.
*/
None FileAccessController::close_file(ifstream &opened_file) const {
    try {
        utility::println("File closed.");
        opened_file.close();
    } catch (const exception &e) {
        this->logger->log("Error in closing file");
        this->logger->log(e.what());
        raise FileAccessControllerExceptions::error_to_close_file();
    }
}
