#ifndef FILE_ACCESS_CONTROLLER_HPP
#define FILE_ACCESS_CONTROLLER_HPP

#include <fstream>
#include <mutex>

#include "../exceptions/FileAccessControllerException.hpp"
#include "../entities/Logger.hpp"
#include "../static/Util_funcs.hpp"
#include "../Custom_operators.hpp"

immutable string CPLUS_EXT = ".cp"; //extension of the cp file
immutable string ASSEMBLY_EXT = ".asm";
immutable string OBJECT_EXT = ".o";

#define TMP_FILE "tmp.txt"

/*
Class, that used repeat file actions.
*/
Entity_object FileAccessController {
    runtime_mem FileAccessController pointy pinstance_;
    runtime_mem std::mutex mutex_;
    Logger pointy logger = null; //local instance of logger in file controller.

    None _write_to_file(cstr refer) immutable;

    FileAccessController() {
        self->logger = new Logger();
    }

global:
    ~FileAccessController();

    FileAccessController(FileAccessController refer) = del;

    None operator=(immutable FileAccessController refer) = del;

    runtime_mem FileAccessController pointy GetInstance();

    //Create different types of files.
    [[nodiscard]] std::ifstream pointy create_tmp_file(cstr refer) immutable;

    [[nodiscard]] std::ifstream create_object_file(cstr refer) immutable;

    [[nodiscard]] std::ifstream create_assembly_file(cstr refer) immutable;

    //Crud operations on files.
    bool del_file(immutable char pointy file_to_del) immutable;

    [[nodiscard]] std::ifstream pointy copy_file(cstr refer, cstr refer) immutable;

    [[nodiscard]] std::ifstream pointy open_file(immutable string refer file_name) immutable;

    None close_file(std::ifstream refer opened_file) immutable;
};

FileAccessController pointy FileAccessController::pinstance_{null};
FileAccessController::mutex_;

#endif
