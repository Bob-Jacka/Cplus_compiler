/*
This package is for spliting line for lexems.
*/

#include <data/exceptions/LexerException.cpp>
#include <data/Variables.hpp>
#include <mutex>
#include <regex>
#include <UtilFuncs.hpp>
#include <static/CplusModel.hpp>

using namespace utility;

static string value_modifiers[3] = { "nosign", "const", "extended" };
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
typedef const regex const_reg;

/*
Structure with all tokens in C+ language.
Contains regex sentences for recognizing lang constructs.
*/
struct Tokens {
    const_string ignore = " \t\r";
    const_string ignore_comment = "\/\/.*";
public:
    const_reg ID = regex("[a-zA-Z_][a-zA-Z0-9_]*"); //regex string for vals ids

    //Values regexes:
    const_reg INTVAL = regex("\d+");
    const_reg DOUBLEVAL = regex("");
    const_reg STRING = regex(""[^"]*"");
    const_reg VAR = regex(""[^"]*"");

    //Arithmetical operators:
    const_string PLUS = "\+";
    const_string MINUS = "-";
    const_string TIMES = "\*";
    const_string DIVIDE = "/";
    const_string MOD = "%";

    //Logical operators:
    const_string LTEQ = "<=";
    const_string LT = "<";
    const_string GTEQ = ">=";
    const_string GT = ">";
    const_string EQ = "==";
    const_string NOTEQ = "!=";

    const_string AND = "and";
    const_string OR = "or";
    const_string NOT = "not";

    //Brackets:
    const_string LPAREN = "\(";
    const_string RPAREN = "\)";

    const_string BEGIN = "\{";
    const_string END = "\}";

    //Other operators:
    const_string ASSIGN = "=";
    const_string COLON = ":";
    const_string COMMA = ",";
};

/*
Class of the lexer entitie to proceed.
*/
class Lexer
{

private:
    bool check_func_full = [](string str) -> bool { return !contains(str, "=") && contains(str, FUNCTION); };
    bool check_val_full = [](string str) -> bool { return contains(str, "="); };
    
    void split_to_value();
    void split_to_function();
    void split_to_struct();

    Function function();
    Value value();
    Lang_struct lang_struct();

    static Lexer *pinstance_;
    static std::mutex mutex_;

protected:
    Lexer() {};

public:
    ~Lexer();
    Lexer(Lexer &other) = delete;

    void operator=(const Lexer &) = delete;

    static Lexer *GetInstance();
};

Lexer *Lexer::pinstance_{nullptr};
std::mutex Lexer::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Lexer *Lexer::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Lexer();
    }
    return pinstance_;
}

void Lexer::split_to_value()
{
    //
}

void Lexer::split_to_function()
{
    //
}

void Lexer::split_to_struct()
{
    //
}

Lexer::Lexer()
{
    //
}

Lexer::~Lexer()
{
    //
}

Function Lexer::function()
{
    //
}

Value Lexer::value()
{
    //
}

Lang_struct Lexer::lang_struct()
{
    //
}
