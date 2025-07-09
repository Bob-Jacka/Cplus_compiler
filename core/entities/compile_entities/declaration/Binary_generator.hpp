#ifndef BINARY_GENERATOR_HPP
#define BINARY_GENERATOR_HPP

#include <mutex>

#include "../../../data/exceptions/BinaryGeneratorException.hpp"
#include "../../../functional/controllers_entities/declaration/File_access_controller.hpp"

class Binary_generator {
    static Binary_generator *pinstance_;
    static std::mutex mutex_;

    Binary_generator();

public:
    ~Binary_generator();

    ifstream generate_binary(const FileAccessController *);

    Binary_generator(Binary_generator &) = delete;

    void operator=(const Binary_generator &) = delete;

    static Binary_generator *GetInstance();
};

Binary_generator *Binary_generator::pinstance_{nullptr};
std::mutex Binary_generator::mutex_;

#endif
