#ifndef FILE_ACCESS_CONTROLLER_HPP
#define FILE_ACCESS_CONTROLLER_HPP

/**
 Module with file access controller entity
 */
export module file_controller;

#include <fstream>
#include <mutex>
#include "../exceptions/FileAccessControllerException.hpp"

import Logger;
import UtilFuncs;
#include "../Custom_operators.hpp"

export namespace File_controller {
    immutable string CPLUS_EXT = ".cp"; //extension of the cp file
    immutable string ASSEMBLY_EXT = ".asm";
    immutable string OBJECT_EXT = ".o";
    immutable string TMP_FILE = "tmp.txt";
    immutable string LOG_FILE_EXT = ".log";

    /**
    Class, that used repeat file actions.
    */
    EntityObject FileAccessController {
        runtimeMem FileAccessController pointy pinstance_;
        runtimeMem std::mutex mutex_;
        Logger pointy logger = null; //local instance of logger in file controller.

        None _write_to_file(cstr refer) immutable;

        FileAccessController() {
            self->logger = new Logger();
        }

    global:
        ~FileAccessController();

        FileAccessController(FileAccessController refer) = del;

        None operator=(immutable FileAccessController refer) = del;

        runtimeMem FileAccessController pointy GetInstance();

        [[nodiscard]] std::ifstream pointy create_tmp_file(cstr refer) immutable;

        [[nodiscard]] std::ifstream create_object_file(cstr refer) immutable;

        [[nodiscard]] std::ifstream create_assembly_file(cstr refer) immutable;

        [[nodiscard]] std::ifstream create_log_file(cstr refer) immutable;

        bool del_file(immutable char pointy file_to_del) immutable;

        [[nodiscard]] std::ifstream pointy copy_file(cstr refer, cstr refer) immutable;

        [[nodiscard]] std::ifstream pointy open_file(immutable string refer file_name) immutable;

        None close_file(std::ifstream refer opened_file) immutable;
    };

    FileAccessController pointy FileAccessController::pinstance_{null};
    FileAccessController::mutex_;
}


#endif
