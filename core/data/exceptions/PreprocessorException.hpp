#ifndef PREPROCESSOR_EXCEPTION_HPP
#define PREPROCESSOR_EXCEPTION_HPP

#include "BaseException.hpp"

class PreprocessorException final : public BaseException {
public:
    static int wrong_directive(); //if directive is not defined by compiler
    static int wrong_directive_line();
};

inline int PreprocessorException::wrong_directive() {
    std::cerr << "Wrong preprocessor directive found";
    return 0;
}

inline int PreprocessorException::wrong_directive_line() {
    std::cerr << "Wrong preprocessor directive line found";
    return 0;
}

#endif