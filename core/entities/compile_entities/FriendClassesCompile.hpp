#pragma once

// #ifdef TEST_MODE //Macros for test classes compilation

#ifndef FRIENDCLASSES_HPP
#define FRIENDCLASSES_HPP

#include "../../data/Main_types_compile.hpp"

//special class for testing
class LinkerTest {
    Linker *priv_param = Linker::GetInstance();

public:
    decltype(auto) do_test_get_filename(string &line) const {
        auto ret = priv_param->__get_file_name(line);
        return ret;
    }

    void do_test_scan_file(std::ifstream &input_file) const {
        priv_param->__scan_file(input_file);
    }

    void do_test_import_directives(std::ifstream &input_file) const {
        priv_param->link_import_directives(input_file);
    }
};

//special class for testing
class LexerTest {
    Lexer *priv_param = Lexer::GetInstance();

public:
    void do_test_init_keywords() const {
        priv_param->_init_keywords();
    }

    decltype(auto) do_test_is_whitespace(const char c) const {
        const auto res = priv_param->_is_whitespace(c);
        return res;
    }

    decltype(auto) do_test_is_alpha(const char c) const {
        const auto res = priv_param->_is_alpha(c);
        return res;
    }

    decltype(auto) do_test_is_digit(const char c) const {
        const auto res = priv_param->_is_digit(c);
        return res;
    }

    decltype(auto) do_test_is_alphanumeric(const char c) const {
        const auto res = priv_param->_is_alpha_numeric(c);
        return res;
    }

    decltype(auto) do_test_get_next_word() const {
        const auto res = priv_param->_get_next_word();
        return res;
    }

    decltype(auto) do_test_get_next_number() const {
        const auto res = priv_param->_get_next_number();
        return res;
    }

    decltype(auto) do_get_tokens() const {
        const auto res = priv_param->get_token_vector();
        return res;
    }
};

//special class for testing
class ParserTest {
    Parser *priv_param = Parser::GetInstance();

public:
    void do_test_react() const {
    }
};

//special class for testing
class PreprocessorTest {
    Preprocessor *priv_param = Preprocessor::GetInstance();

public:
    void do_test() const {
    }
};

//special class for testing
class BinaryGeneratorTest {
    Binary_generator *priv_param = Binary_generator::GetInstance();

public:
    void do_test() const {
    }
};

//special class for testing
class AssemblerTest {
    Assembly_generator *priv_param = Assembly_generator::GetInstance();

public:
    void do_test() const {
    }
};

//special class for testing
class AnalyzerTest {
    Analyzer *priv_param = Analyzer::GetInstance();

public:
    void do_test() const {
    }
};

#endif //FRIENDCLASSES_HPP

// #endif
