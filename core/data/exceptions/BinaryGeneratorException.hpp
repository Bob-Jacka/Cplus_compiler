#ifndef BIN_GENERATOR_EXCEPTION_HPP
#define BIN_GENERATOR_EXCEPTION_HPP

#include "BaseException.hpp"

class BinaryGeneratorException final : public BaseException {
public:
    static int ErrorInBinaryGeneration(); //general exception
};

inline int BinaryGeneratorException::ErrorInBinaryGeneration() {
    std::cerr << "Error occurred in binary generation process";
    return 0;
}

#endif