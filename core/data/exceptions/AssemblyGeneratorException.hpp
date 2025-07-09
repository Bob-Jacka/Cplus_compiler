/*
Exception class for assembly generator
*/

#ifndef ASSEMBLY_GEN_HPP_EXCEPTION
#define ASSEMBLY_GEN_HPP_EXCEPTION
#include "BaseException.hpp"

class AssemblyGeneratorException final : public BaseException {
public:
    static int error_in_assembly_generation(); //general exception in assembly generator
    static int wrong_assembly_line();
};

inline int AssemblyGeneratorException::error_in_assembly_generation() {
    std::cerr << "Error in assembly generation occurred";
    return 0;
}

inline int AssemblyGeneratorException::wrong_assembly_line() {
    return 0;
}

#endif