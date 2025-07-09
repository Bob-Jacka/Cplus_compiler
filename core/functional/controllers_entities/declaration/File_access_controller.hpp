#ifndef FILE_ACCESS_CONTROLLER_HPP
#define FILE_ACCESS_CONTROLLER_HPP

#include <fstream>
#include <mutex>

#include "../../../data/exceptions/FileAccessControllerException.hpp"
#include "../../../entities/Logger.hpp"
#include "../static/Util_funcs.hpp"

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
    Logger *logger = nullptr; //local instance of logger in file controller.

    void _write_to_file(cstr &) const;

    FileAccessController() {
        this->logger = new Logger();
    }

public:
    ~FileAccessController();

    FileAccessController(FileAccessController &) = delete;

    void operator=(const FileAccessController &) = delete;

    static FileAccessController *GetInstance();

    //Create different types of files.
    [[nodiscard]] ifstream *create_tmp_file(cstr &) const;

    [[nodiscard]] ifstream create_object_file(cstr &) const;

    [[nodiscard]] ifstream create_assembly_file(cstr &) const;

    //Crud operations on files.
    bool delete_file(const char *file_to_delete) const;

    [[nodiscard]] ifstream *copy_file(cstr &, cstr &) const;

    [[nodiscard]] ifstream *open_file(const string &file_name) const;

    void close_file(ifstream &opened_file) const;
};

FileAccessController *FileAccessController::pinstance_{nullptr};
mutex FileAccessController::mutex_;

#endif
