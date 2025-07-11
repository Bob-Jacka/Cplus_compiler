#include "../declaration/Binary_generator.hpp"
#define OBJECT_FILE_NAME "object"

Binary_generator::Binary_generator() {
    //
}

Binary_generator::~Binary_generator() {
    del&mutex_;
}

/**
 * Main entry point of the Binary generator entity
 */
ifstream Binary_generator::generate_binary(const FileAccessController *f_controller) {
    return f_controller->create_object_file(OBJECT_FILE_NAME);
}

Binary_generator *Binary_generator::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new Binary_generator();
    }
    return pinstance_;
}
