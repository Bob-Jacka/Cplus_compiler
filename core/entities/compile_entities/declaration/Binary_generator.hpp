#ifndef BINARY_GENERATOR_HPP
#define BINARY_GENERATOR_HPP

#include <mutex>

#include "../data/exceptions/BinaryGeneratorException.hpp"
#include "../functional/controllers_entities/declaration/File_access_controller.hpp"
#include "../Custom_operators.hpp"

Entity_object Binary_generator {
    runtime_mem Binary_generator pointy pinstance_;
    runtime_mem std::mutex mutex_;

    Binary_generator();

global:
    ~Binary_generator();

    ifstream generate_binary(immutable FileAccessController pointy);

    Binary_generator(Binary_generator refer) = del;

    None operator=(immutable Binary_generator refer) = del;

    runtime_mem Binary_generator pointy GetInstance();
};

Binary_generator pointy Binary_generator::pinstance_{null};
std::mutex Binary_generator::mutex_;

#endif
