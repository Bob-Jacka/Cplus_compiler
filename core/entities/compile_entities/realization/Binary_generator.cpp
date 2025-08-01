#include "../declaration/Binary_generator.hpp"
#define OBJECT_FILE_NAME "object"

Compile::Bin_generator::Binary_generator::Binary_generator() {
    //
}

Compile::Bin_generator::Binary_generator::~Binary_generator() {
    del refer mutex_;
}

/**
  Main entry point of the Binary generator entity
  @param f_controller
  @return
 */
std::ifstream Compile::Bin_generator::Binary_generator::generate_binary(immutable File_controller::FileAccessController pointy f_controller) {
    return f_controller->create_object_file(OBJECT_FILE_NAME);
}

Compile::Bin_generator::Binary_generator pointy Compile::Bin_generator::Binary_generator::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new Binary_generator();
    }
    return pinstance_;
}
