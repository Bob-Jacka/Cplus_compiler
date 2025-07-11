#include "../declaration/Lexer.hpp"

#include <fstream>

Lexer::~Lexer() {
    del pinstance_;
    del[] p_tokens;
}

/*
  The first time we call GetInstance we will lock the storage location,
  and then we make sure again that the variable is null, and then we set value
 */
Lexer *Lexer::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new Lexer("");
    }
    return pinstance_;
}

/*
 Private function to initialize the keywords map
 */
void Lexer::_init_keywords() {
    //Types words
    keywords["int"] = TokenEnum::KEYWORD; //default int, just like in C++
    keywords["float"] = TokenEnum::KEYWORD; //default float, just like in C++
    keywords["string"] = TokenEnum::KEYWORD; //default string, just like in Python
    keywords["bool"] = TokenEnum::KEYWORD; //default bool, just like in Python
    keywords["char"] = TokenEnum::KEYWORD; //default char, just like in C++

    //Branching operators
    keywords["if"] = TokenEnum::KEYWORD;
    keywords["elif"] = TokenEnum::KEYWORD; //same as elif in Python
    keywords["else"] = TokenEnum::KEYWORD; //same as else in C++
    keywords["branch"] = TokenEnum::KEYWORD; //same as switch in C++

    //Visibility modifiers
    keywords["public"] = TokenEnum::KEYWORD; //default public
    keywords["private"] = TokenEnum::KEYWORD; //default private
    keywords["inherit"] = TokenEnum::KEYWORD; //only if inherit
    keywords["package"] = TokenEnum::KEYWORD; //visibility in package

    //Value modifiers
    keywords["nosign"] = TokenEnum::KEYWORD; //same as unsigned in C++
    keywords["const"] = TokenEnum::KEYWORD; //default const word
    keywords["extended"] = TokenEnum::KEYWORD; //word for extended allocation memory for variable

    //Cycle operators
    keywords["do"] = TokenEnum::KEYWORD; //default do, just like in C++
    keywords["while"] = TokenEnum::KEYWORD; //default while, just like in C++
    keywords["for"] = TokenEnum::KEYWORD; //!! only foreach cycle available
    keywords["repeat"] = TokenEnum::KEYWORD; //repeat given sentence given times

    //Other words
    keywords["in"] = TokenEnum::KEYWORD; //operator for checking if element in container
    keywords["struct"] = TokenEnum::KEYWORD; //default struct in C
    keywords["return"] = TokenEnum::KEYWORD; //default return
}

/*
 Private function to check if a character is whitespace
 Returns - bool value if char is space
 */
bool Lexer::_is_whitespace(const char c) const {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

/*
 Private function to check if a character is alphabetic
 Returns - bool value if char is alphabetic
 */
bool Lexer::_is_alpha(const char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/*
 Private function to check if a character is a digit
 Returns - bool value if char is digit
 */
bool Lexer::_is_digit(const char c) const {
    return c >= '0' && c <= '9';
}

/*
 Private function to check if a character is alphanumeric
 Returns - bool value if char is alphanumeric
 */
bool Lexer::_is_alpha_numeric(const char c) const {
    return _is_alpha(c) || _is_digit(c);
}

/*
 Private function to check if next symbol is quote.
 Needs to identify char ('c') or string ("string") objects
 */
bool Lexer::_is_quote_next(const char c) const {
    return c == '\'' || c == '"' || c == '`';
}

/*
Private function to get the next word (identifier or keyword)
from the input
Returns - string, representing next word
*/
string Lexer::_get_next_word() {
    const size_t start = position;
    while (position < line.length() && _is_alpha_numeric(line[position])) {
        position++;
    }
    return line.substr(start, position - start);
}

/*
Private function to get the next number (integer or float)
from the input
Returns - string, representing next number
*/
string Lexer::_get_next_number() {
    const size_t start = position;
    bool hasDecimal = false;
    while (position < line.length() && (_is_digit(line[position]) || line[position] == '.')) {
        if (line[position] == '.') {
            if (hasDecimal)
                break;
            hasDecimal = true;
        }
        position++;
    }
    return line.substr(start, position - start);
}

/*
Main function to tokenize the input string.
Entry point of the lexer.
Returns - point to vector with tokens
*/
vector<Token> *Lexer::tokenize() {
    std::ifstream in(file_name); //open file for read.

    if (in.is_open()) {
        while (std::getline(in, line)) {
            while (position < line.length()) {
                const char currentChar = line[position];

                //Skip whitespace
                if (_is_whitespace(currentChar)) {
                    position++;
                    continue;
                }

                //Identify keywords or identifiers
                if (_is_alpha(currentChar)) {
                    string word = _get_next_word();
                    if (keywords.contains(word)) {
                        this->p_tokens->emplace_back(TokenEnum::KEYWORD, word);
                    } else {
                        this->p_tokens->emplace_back(TokenEnum::IDENTIFIER, word);
                    }
                }

                //Identify integer or float literals
                else if (_is_digit(currentChar)) {
                    string number = _get_next_number();
                    if (number.find('.') != string::npos) {
                        this->p_tokens->emplace_back(TokenEnum::FLOAT_LITERAL, number);
                    } else {
                        this->p_tokens->emplace_back(TokenEnum::INTEGER_LITERAL, number);
                    }
                }

                //Identify operators
                else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
                    this->p_tokens->emplace_back(TokenEnum::OPERATOR, string(1, currentChar));
                    position++;
                }

                //Identify punctuators
                else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}') {
                    this->p_tokens->emplace_back(TokenEnum::PUNCTUATOR, string(1, currentChar));
                    position++;
                }

                //Handle unknown characters
                else {
                    this->p_tokens->emplace_back(TokenEnum::UNKNOWN, string(1, currentChar));
                    position++;
                    throw LexerException::unknown_word_type();
                }
            }
        }
    } else {
        throw LexerException::error_in_open_file();
    }
    in.close(); //close file
    return this->p_tokens;
}

/*
Method for returning inner vector representation of tokens.
*/
vector<Token> *Lexer::get_token_vector() const {
    if (!this->p_tokens->empty()) {
        return this->p_tokens;
    } else {
        utility::println("Token vector is empty, return nullptr");
        return nullptr;
    }
}

/*
 Function to convert TokenType to string for printing
 */
string Lexer::get_token_type_name(const TokenEnum type) {
    match (type) {
        case TokenEnum::KEYWORD:
            return "KEYWORD";
        case TokenEnum::IDENTIFIER:
            return "IDENTIFIER";
        case TokenEnum::CHAR_LITERAL:
            return "CHAR_LITERAL";
        case TokenEnum::STRING_LITERAL:
            return "STRING_LITERAL";
        case TokenEnum::INTEGER_LITERAL:
            return "INTEGER_LITERAL";
        case TokenEnum::FLOAT_LITERAL:
            return "FLOAT_LITERAL";
        case TokenEnum::OPERATOR:
            return "OPERATOR";
        case TokenEnum::PUNCTUATOR:
            return "PUNCTUATOR";
        case TokenEnum::UNKNOWN:
            return "UNDEFINED";
        default:
            return "UNKNOWN";
    }
}

/*
 Function to print all p_tokens in inner vector container
 */
void Lexer::print_tokens(const vector<Token> &p_tokens) {
    for (val2 &token: p_tokens) {
        cout << "Type: " << get_token_type_name(token.type) << endl << "Value: " << token.value << endl;
    }
}
