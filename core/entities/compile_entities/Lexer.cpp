/*
This package is for spliting line for lexems.
*/

#include <data/exceptions/LexerException.cpp>
#include <data/Variables.hpp>
#include <mutex>
#include <regex>
#include <UtilFuncs.hpp>
#include <static/CplusModel.hpp>
#include <unordered_map>

using namespace utility;

static string value_modifiers[3] = { "nosign", "const", "extented" };
static string visibility_modifiers[4] = { "public", "private", "inherit", "package" };

/*
Structure representing value in C+ language
*/
struct Value
{
    string name;
    string val;
    string visible_mod;
    string modifier;
};

/*
Structure representing functions (methods) in C+ language
*/
struct Function
{
    string name;
    string * arguments;
    string visible_mod;
};

/*
Structure representing structures (class in other langs) in C+ language
*/
struct Lang_struct
{
    string name;
    string * values;    // structure values
    string * functions; // structure methods
};

using namespace std;
typedef const regex const_reg; //define constant regex value type.

//Enum class to define different types of tokens
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

    Token(TokenEnum t, const string& v) : type(t), value(v)
    {
        //
    }
};

// Class that implements the lexical analyzer
class Lexer {

private:
    string line = ""; //line in the file

    string file_name;
    size_t position;
    LexerException exceptions;

    static Lexer* pinstance_;
    static std::mutex mutex_;
    unordered_map<string, TokenEnum> keywords;

    Lexer();

    void initKeywords();
    bool isWhitespace(char c);
    bool isAlpha(char c); //check if given symbol - letter
    bool isDigit(char c); //check if given symbol - digit
    bool isAlphaNumeric(char c);
    bool isQuoteNext(char c); //for string and char types
    string getNextWord();
    string getNextNumber();

public:
    vector<Token> tokenize();

    static Lexer* GetInstance();

    //Constructor for LexicalAnalyzer
    Lexer(const string& file_name): file_name(file_name), position(0)
    {
        cout << "Lexer is init";
        initKeywords();
    }
};

Lexer* Lexer::pinstance_{ nullptr };
std::mutex Lexer::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Lexer* Lexer::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Lexer();
    }
    return pinstance_;
}

//Function to initialize the keywords map
void Lexer::initKeywords()
{
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

//Function to check if a character is whitespace
bool Lexer::isWhitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

//Function to check if a character is alphabetic
bool Lexer::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//Function to check if a character is a digit
bool Lexer::isDigit(char c) {
    return c >= '0' && c <= '9';
}

//Function to check if a character is alphanumeric
bool Lexer::isAlphaNumeric(char c)
{
    return isAlpha(c) || isDigit(c);
}

//Function to check if next symbol is quote.
bool Lexer::isQuoteNext(char c)
{
    return false;
}

/*
Function to get the next word (identifier or keyword)
from the input
*/
string Lexer::getNextWord()
{
    size_t start = position;
    while (position < line.length() && isAlphaNumeric(line[position])) {
        position++;
    }
    return line.substr(start, position - start);
}

/*
Function to get the next number (integer or float)
from the input
*/
string Lexer::getNextNumber()
{
    size_t start = position;
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

//Main function to tokenize the input string.
vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;
    std::ifstream in(file_name); //open file for read.

    if (in.is_open()) {
        while (std::getline(in, line)) {

            while (position < line.length()) {
                char currentChar = line[position];

                //Skip whitespace
                if (isWhitespace(currentChar)) {
                    position++;
                    continue;
                }

                //Identify keywords or identifiers
                if (isAlpha(currentChar)) {
                    string word = getNextWord();
                    if (keywords.find(word) != keywords.end())
                    {
                        tokens.emplace_back(TokenEnum::KEYWORD, word);
                    }
                    else {
                        tokens.emplace_back(TokenEnum::IDENTIFIER, word);
                    }
                }

                //Identify integer or float literals
                else if (isDigit(currentChar)) {
                    string number = getNextNumber();
                    if (number.find('.') != string::npos) {
                        tokens.emplace_back(TokenEnum::FLOAT_LITERAL, number);
                    }
                    else {
                        tokens.emplace_back(TokenEnum::INTEGER_LITERAL, number);
                    }
                }

                //Identify operators
                else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
                    tokens.emplace_back(TokenEnum::OPERATOR, string(1, currentChar));
                    position++;
                }

                //Identify punctuators
                else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}') {
                    tokens.emplace_back(TokenEnum::PUNCTUATOR, string(1, currentChar));
                    position++;
                }

                //Handle unknown characters
                else {
                    tokens.emplace_back(TokenEnum::UNKNOWN, string(1, currentChar));
                    position++;
                }
            }
        }
    }
    else {
        exceptions.ErrorInOpenFile();
    }
    in.close(); //close file
    return tokens;
}

//Function to convert TokenType to string for printing
static string getTokenTypeName(TokenEnum type)
{
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

//Function to print all tokens in inner vector container
static void printTokens(const vector<Token>& tokens)
{
    for (const auto& token : tokens) {
        cout << "Type: " << getTokenTypeName(token.type) << endl << "Value: " << token.value << endl;
    }
}
