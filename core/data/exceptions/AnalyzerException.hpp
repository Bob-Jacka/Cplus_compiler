#ifndef ANALYZER_HPP_EXCEPTION
#define ANALYZER_HPP_EXCEPTION

#include "BaseException.hpp"

/*
 Class with exceptions in Analyzer entity
 */
class AnalyzerException final : BaseException {
global:
    static int wrong_function_definition();

    static int wrong_struct_definition();

    static int wrong_value_definition();
};

inline int wrong_function_definition() {
    std::cerr << "Error occurred in function definition";
    return 0;
}

inline int wrong_struct_definition() {
    std::cerr << "Error occurred in struct definition";
    return 0;
}

inline int wrong_value_definition() {
    std::cerr << "Error occurred in value definition";
    return 0;
}

#endif
