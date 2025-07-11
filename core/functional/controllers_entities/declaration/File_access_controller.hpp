#ifndef FILE_ACCESS_CONTROLLER_HPP
#define FILE_ACCESS_CONTROLLER_HPP

#include <fstream>
#include <mutex>

#include "../data/exceptions/FileAccessControllerException.hpp"
#include "../entities/Logger.hpp"
#include "../static/Util_funcs.hpp"
#include "../Custom_operators.hpp"

constexpr string CPLUS_EXT = ".cp"; //extension of the cp file
constexpr string ASSEMBLY_EXT = ".asm";
constexpr string OBJECT_EXT = ".o";

#define TMP_FILE "tmp.txt"

using namespace std;

/*
Class, that used for file actions.
*/
class FileAccessController {
    static FileAccessController *pinstance_;
    static mutex mutex_;
    Logger *logger = null; //local instance of logger in file controller.

    None _write_to_file(cstr &) const;

    FileAccessController() {
        this->logger = new Logger();
    }

global:
    ~FileAccessController();

    FileAccessController(FileAccessController &) = del;

    None operator=(const FileAccessController &) = del;

    static FileAccessController *GetInstance();

    //Create different types of files.
    [[nodiscard]] ifstream *create_tmp_file(cstr &) const;

    [[nodiscard]] ifstream create_object_file(cstr &) const;

    [[nodiscard]] ifstream create_assembly_file(cstr &) const;

    //Crud operations on files.
    bool del_file(const char *file_to_del) const;

    [[nodiscard]] ifstream *copy_file(cstr &, cstr &) const;

    [[nodiscard]] ifstream *open_file(const string &file_name) const;

    None close_file(ifstream &opened_file) const;
};

FileAccessController *FileAccessController::pinstance_{null};
mutex FileAccessController::mutex_;

#endif
