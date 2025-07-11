/*
This package is for splitting line for lexemes.
*/
#ifndef LEXER_HPP
#define LEXER_HPP

#include <mutex>
#include <regex>
#include <unordered_map>
#include <utility>
#include <vector>

#include "data/exceptions/LexerException.hpp"

#include "../static/Util_funcs.hpp"

/*
Structure representing value in C+ language
*/
struct Value {
    string name;
    string val;
    string visible_mod;
    std::vector<string> *modifier;

    Value() {
        modifier = new std::vector<string>();
    }

    ~Value() {
        del modifier;
    }
};

/*
Structure representing functions (methods) in C+ language
*/
struct Function {
    std::vector<string> *arguments;
    string name;
    string visible_mod;

    Function() {
        arguments = new std::vector<string>();
        visible_mod = null;
    }

    ~Function() {
        del arguments;
    }
};

/*
Structure representing structures (class in other langs) in C+ language
*/
struct Lang_struct {
    string name;
    std::vector<string> *values; // structure values
    std::vector<string> *functions; // structure methods

    Lang_struct() {
        values = new std::vector<string>();
        functions = new std::vector<string>();
    }

    ~Lang_struct() {
        del[] values;
        del[] functions;
    }
};

using namespace std;
typedef const regex const_reg; //define constant regex value type.

/*
 Enum class to define different types of p_tokens
 */
enum TokenEnum {
    KEYWORD, //for lang inner word, ex. structure word
    IDENTIFIER, //for ex. value or function name

    CHAR_LITERAL,
    STRING_LITERAL,
    INTEGER_LITERAL,
    FLOAT_LITERAL,

    OPERATOR,
    PUNCTUATOR,
    UNDEFINED,

    UNKNOWN
};

//Struct to represent a token with its type and value
struct Token {
    TokenEnum type;
    string value;

    Token(const TokenEnum t, string v) : type(t), value(std::move(v)) {
        //
    }

    ~Token() {
        //
    }
};

// Class that implements the lexical analyzer
class Lexer {
    string line; //line in the file

    string file_name;
    size_t position;
    vector<Token> *p_tokens; //Inner representation of the tokens.

    static Lexer *pinstance_;
    static std::mutex mutex_;
    unordered_map<string, TokenEnum> keywords; //Map with Lexer keywords of the C+ language

    explicit Lexer(string file_name): file_name(std::move(file_name)), position(0) {
        cout << "Lexer is init";
        this->p_tokens = new vector<Token>();
        _init_keywords();
    }

    void _init_keywords();

    bool _is_whitespace(char) const;

    bool _is_alpha(char) const;

    bool _is_digit(char) const;

    bool _is_alpha_numeric(char) const;

    bool _is_quote_next(char) const;

    string _get_next_word();

    string _get_next_number();

    friend class LexerTest; //friend class for lexer

public:
    vector<Token> *tokenize();

    Lexer() = delete;

    ~Lexer();

    static void print_tokens(const vector<Token> &);

    static string get_token_type_name(TokenEnum);

    vector<Token> *get_token_vector() const;

    static Lexer *GetInstance();
};

Lexer *Lexer::pinstance_{null};
std::mutex Lexer::mutex_;

#endif
