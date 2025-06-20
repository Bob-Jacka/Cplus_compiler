#include "BaseException.hpp"

class FileAccessControllerExceptions final : public BaseException {
public:
    static int error_to_open_file();

    static int error_to_close_file();

    static int error_to_read_file();

    static int error_to_write_file();

    static int error_to_delete_file();

    static int wrong_extension();

    static int error_in_copy_file();

    static int error_in_creating_tmp_file();

    static int error_in_object_file();

    static int error_in_assembly_file();
};

int error_to_open_file() {
    std::cerr << "Failed to open file";
    return 1;
}

int error_to_close_file() {
    std::cerr << "Failed to close file";
    return 1;
}

int error_to_read_file() {
    std::cerr << "Failed to read from file";
    return 1;
}

int error_to_write_file() {
    std::cerr << "Failed to write to file";
    return 1;
}

int wrong_extension() {
    std::cerr << "File of wrong extension, only .cp ext file need";
    return 1;
}

int error_in_copy_file() {
    std::cerr << "Failed to copy file";
    return 1;
}

int error_in_creating_tmp_file() {
    std::cerr << "Failed to create tmp file";
    return 1;
}

int error_in_object_file() {
    std::cerr << "Failed to create object file";
    return 1;
}

int error_in_assembly_file() {
    std::cerr << "Failed to assembly file";
    return 1;
}

int error_in_delete_file() {
    std::cerr << "Failed to delete file";
    return 1;
}
