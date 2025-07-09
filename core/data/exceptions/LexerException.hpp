#ifndef LEXER_EXCEPTION_HPP
#define LEXER_EXCEPTION_HPP
#include "BaseException.hpp"

class LexerException final : public BaseException {
public:
    static int wrong_value_type();

    static int wrong_function_type();

    static int error_in_open_file();

    static int unknown_word_type();
};

inline int LexerException::wrong_value_type() {
    std::cerr << "Wrong type error occurred";
    return 0;
}

inline int LexerException::wrong_function_type() {
    std::cerr << "Wrong function type error occurred";
    return 0;
}

inline int LexerException::error_in_open_file() {
    std::cerr << "Error in opening file for analyze";
    return 0;
}

inline int LexerException::unknown_word_type() {
    std::cerr << "Unknown word type error occurred";
    return 0;
}

#endif
