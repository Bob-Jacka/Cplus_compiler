/*
Class used for building syntax tree.
Get stream from lexer and build syntax tree;
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <mutex>

class Parser {
    static Parser *pinstance_;
    static std::mutex mutex_;

    //methods for react on different tokens
    void react_on_keyword() const;

    void react_on_intval() const;

    void react_on_stringval() const;

    void react_on_floatval() const;

    void react_on_operator() const;

    void react_on_identifier() const;

public:
    Parser() = default;

    ~Parser() = default;

    Parser(Parser &other) = delete;

    void operator=(const Parser &) = delete;

    static Parser *GetInstance();

    void build_tree() const;

    std::vector<Token> *parse_tokens(std::vector<Token> *) const; //Entry point of the Parser

    friend class ParserTest;
};

Parser *Parser::pinstance_{nullptr};
std::mutex Parser::mutex_;

#endif