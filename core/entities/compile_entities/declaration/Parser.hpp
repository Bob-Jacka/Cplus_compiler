/*
Class used for building syntax tree.
Get stream from lexer and build syntax tree;
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <mutex>
#include <vector>

#include "Custom_operators.hpp"
#include "Lexer.hpp"

class Parser {
    static Parser *pinstance_;
    static std::mutex mutex_;

    //methods for react on different tokens
    None react_on_keyword() const;

    None react_on_intval() const;

    None react_on_stringval() const;

    None react_on_floatval() const;

    None react_on_operator() const;

    None react_on_identifier() const;

global:
    Parser() = default;

    ~Parser() = default;

    Parser(Parser &other) = del;

    None operator=(const Parser &) = del;

    static Parser *GetInstance();

    None build_tree() const;

    std::vector<Token> *parse_tokens(std::vector<Token> *) const; //Entry point of the Parser

    friend class ParserTest;
};

Parser *Parser::pinstance_{null};
std::mutex Parser::mutex_;

#endif
