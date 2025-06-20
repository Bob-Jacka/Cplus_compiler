/*
This package is for spliting line for lexems.
*/

#include <mutex>
#include <regex>
#include <unordered_map>
#include <utility>
#include "core/data/Variables.hpp"
#include "core/data/exceptions/LexerException.cpp"
#include "static/UtilFuncs.hpp"

using namespace utility;

static string value_modifiers[] = {"nosign", "const", "extented"};
static string visibility_modifiers[] = {"public", "private", "inherit", "package"};

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

//Enum class to define different types of p_tokens
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
    LexerException exceptions;
    vector<Token> *p_tokens; //Inner representation of the tokens.

    static Lexer *pinstance_;
    static std::mutex mutex_;
    unordered_map<string, TokenEnum> keywords;

    explicit Lexer(string file_name): file_name(std::move(file_name)), position(0) {
        cout << "Lexer is init";
        this->p_tokens = new vector<Token>();
        this->exceptions = {};
        initKeywords();
    }

    void initKeywords();

    bool isWhitespace(char);

    bool isAlpha(char); //check if given symbol - letter
    bool isDigit(char); //check if given symbol - digit
    bool isAlphaNumeric(char);

    bool isQuoteNext(char c); //for string and char types
    string getNextWord();

    string getNextNumber();

public:
    vector<Token> *tokenize();

    ~Lexer();

    static void printp_Tokens(const vector<Token> &p_tokens);

    static string Lexer::getTokenTypeName(TokenEnum type);

    vector<Token> *getTokenVector() const;

    static Lexer *GetInstance();
};

Lexer *Lexer::pinstance_{nullptr};
std::mutex Lexer::mutex_;

Lexer::~Lexer() {
    delete pinstance_;
    delete[] p_tokens;
}

/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Lexer *Lexer::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Lexer("");
    }
    return pinstance_;
}

//Function to initialize the keywords map
void Lexer::initKeywords() {
    keywords["int"] = TokenEnum::KEYWORD;
    keywords["float"] = TokenEnum::KEYWORD;

    keywords["if"] = TokenEnum::KEYWORD;
    keywords["elif"] = TokenEnum::KEYWORD;
    keywords["else"] = TokenEnum::KEYWORD;

    keywords["do"] = TokenEnum::KEYWORD;
    keywords["while"] = TokenEnum::KEYWORD;
    keywords["repeat"] = TokenEnum::KEYWORD;

    keywords["return"] = TokenEnum::KEYWORD;
}

//Private function to check if a character is whitespace
bool Lexer::isWhitespace(const char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

//Private function to check if a character is alphabetic
bool Lexer::isAlpha(const char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//Private function to check if a character is a digit
bool Lexer::isDigit(const char c) {
    return c >= '0' && c <= '9';
}

//Private function to check if a character is alphanumeric
bool Lexer::isAlphaNumeric(const char c) {
    return isAlpha(c) || isDigit(c);
}

/*
 *Private function to check if next symbol is quote.
 *Needs to identify char ('c') or string ("string") objects
 */
bool Lexer::isQuoteNext(char c) {
    return false;
}

/*
Private function to get the next word (identifier or keyword)
from the input
*/
string Lexer::getNextWord() {
    const size_t start = position;
    while (position < line.length() && isAlphaNumeric(line[position])) {
        position++;
    }
    return line.substr(start, position - start);
}

/*
Private function to get the next number (integer or float)
from the input
*/
string Lexer::getNextNumber() {
    const size_t start = position;
    bool hasDecimal = false;
    while (position < line.length() && (isDigit(line[position]) || line[position] == '.')) {
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
*/
vector<Token> *Lexer::tokenize() {
    std::ifstream in(file_name); //open file for read.

    if (in.is_open()) {
        while (std::getline(in, line)) {
            while (position < line.length()) {
                const char currentChar = line[position];

                //Skip whitespace
                if (isWhitespace(currentChar)) {
                    position++;
                    continue;
                }

                //Identify keywords or identifiers
                if (isAlpha(currentChar)) {
                    string word = getNextWord();
                    if (keywords.find(word) != keywords.end()) {
                        this->p_tokens->emplace_back(TokenEnum::KEYWORD, word);
                    } else {
                        this->p_tokens->emplace_back(TokenEnum::IDENTIFIER, word);
                    }
                }

                //Identify integer or float literals
                else if (isDigit(currentChar)) {
                    string number = getNextNumber();
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
                }
            }
        }
    } else {
        exceptions.ErrorInOpenFile();
    }
    in.close(); //close file
    return this->p_tokens;
}

/*
Method for returning inner vector representation of tokens.
*/
vector<Token> *Lexer::getTokenVector() const {
    return this->p_tokens;
}

//Function to convert TokenType to string for printing
string Lexer::getTokenTypeName(const TokenEnum type) {
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

//Function to print all p_tokens in inner vector container
void Lexer::printp_Tokens(const vector<Token> &p_tokens) {
    for (const auto &token: p_tokens) {
        cout << "Type: " << getTokenTypeName(token.type) << endl << "Value: " << token.value << endl;
    }
}
