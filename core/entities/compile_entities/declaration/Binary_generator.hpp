#ifndef BINARY_GENERATOR_HPP
#define BINARY_GENERATOR_HPP

#include <mutex>

#include "../data/exceptions/BinaryGeneratorException.hpp"
#include "../Custom_operators.hpp"

namespace Compile::Bin_generator {
    EntityObject Binary_generator {
        runtimeMem Binary_generator pointy pinstance_;
        runtimeMem std::mutex mutex_;

        Binary_generator();

        global:
            ~Binary_generator();

        std::ifstream generate_binary(immutable File_controller::FileAccessController pointy);

        Binary_generator(Binary_generator refer) = del;

        None operator=(immutable Binary_generator refer) = del;

        runtimeMem Binary_generator pointy GetInstance();
    };

    Binary_generator pointy Binary_generator::pinstance_{null};
    std::mutex Binary_generator::mutex_;
}


#endif
