/*
This package is for splitting line for lexemes.
*/

#include <fstream>
#include <regex>
#include <unordered_map>
#include <utility>
#include "../../data/exceptions/LexerException.cpp"

/*
Structure representing value in C+ language
*/
struct Value {
    string name;
    string val;
    string visible_mod;
    string modifier;

    Value() = default;

    ~Value() = default;
};

/*
Structure representing functions (methods) in C+ language
*/
struct Function {
    string name;
    string *arguments;
    string visible_mod;

    Function() {
        arguments = nullptr;
        visible_mod = nullptr;
    }

    ~Function() {
        delete arguments;
        delete visible_mod;
    }
};

/*
Structure representing structures (class in other langs) in C+ language
*/
struct Lang_struct {
    string name;
    string *values; // structure values
    string *functions; // structure methods

    Lang_struct() {
        values = nullptr;
        functions = nullptr;
    }

    ~Lang_struct() {
        delete name;
        delete[] values;
        delete[] functions;
    }
};

using namespace std;
typedef const regex const_reg; //define constant regex value type.

/*
 Enum class to define different types of p_tokens
 */
enum class TokenEnum {
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
        delete value;
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

    bool _is_quote_next(char c) const;

    string _get_next_word();

    string _get_next_number();

    friend class LexerTest; //friend class for lexer

public:
    vector<Token> *tokenize();

    Lexer() = delete;

    ~Lexer();

    static void print_tokens(const vector<Token> &p_tokens);

    static string Lexer::get_token_type_name(TokenEnum type);

    vector<Token> *get_token_vector() const;

    static Lexer *GetInstance();
};

Lexer *Lexer::pinstance_{nullptr};
std::mutex Lexer::mutex_;

Lexer::~Lexer() {
    delete pinstance_;
    delete[] p_tokens;
}

/*
  The first time we call GetInstance we will lock the storage location,
  and then we make sure again that the variable is null, and then we set value
 */
Lexer *Lexer::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
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
    switch (type) {
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
    for (const auto &token: p_tokens) {
        cout << "Type: " << get_token_type_name(token.type) << endl << "Value: " << token.value << endl;
    }
}
