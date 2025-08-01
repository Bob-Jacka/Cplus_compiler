#ifndef FILE_CONTROLLER_EXCEPTION_HPP
#define FILE_CONTROLLER_EXCEPTION_HPP

#include "BaseException.hpp"

EntityObject FileAccessControllerExceptions final : BaseException {
global:
    runtimeMem int error_to_open_file();

    runtimeMem int error_to_close_file();

    runtimeMem int error_to_read_file();

    runtimeMem int error_to_write_file();

    runtimeMem int error_to_del_file();

    runtimeMem int wrong_extension();

    runtimeMem int error_in_copy_file();

    runtimeMem int error_in_creating_tmp_file();

    runtimeMem int error_in_object_file();

    runtimeMem int error_in_assembly_file();
};

optim int error_to_open_file() {
    std::cerr << "Failed to open file";
    return 1;
}

optim int error_to_close_file() {
    std::cerr << "Failed to close file";
    return 1;
}

optim int error_to_read_file() {
    std::cerr << "Failed to read from file";
    return 1;
}

optim int error_to_write_file() {
    std::cerr << "Failed to write to file";
    return 1;
}

optim int wrong_extension() {
    std::cerr << "File of wrong extension, only .cp ext file need";
    return 1;
}

optim int error_in_copy_file() {
    std::cerr << "Failed to copy file";
    return 1;
}

optim int error_in_creating_tmp_file() {
    std::cerr << "Failed to create tmp file";
    return 1;
}

optim int error_in_object_file() {
    std::cerr << "Failed to create object file";
    return 1;
}

optim int error_in_assembly_file() {
    std::cerr << "Failed to assembly file";
    return 1;
}

optim int error_in_del_file() {
    std::cerr << "Failed to del file";
    return 1;
}

#endif
