/*
This package is for spliting line for lexems.
*/

#include <data/Variables.hpp>
#include <data/exceptions/LexerException.cpp>
#include <mutex>
#include <UtilFuncs.hpp>

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

/*
Class of the lexer entitie to proceed.
*/
class Lexer
{

private:
    auto check_func_full{[](string str) -> bool
                         { return contains(str, "="); }};
    auto check_val_full{[](string str) -> bool
                        { return contains(str, "="); }};

    void split_to_value();
    void split_to_function();
    void split_to_struct();

    void function();
    void value();
    void lang_struct();

    void validate_func();

    static Lexer *pinstance_;
    static std::mutex mutex_;

protected:
    Lexer() {}
    ~Lexer() {}

public:
    Lexer();
    ~Lexer();
    Lexer(Lexer &other) = delete;

    void operator=(const Lexer &) = delete;

    static Lexer *GetInstance();
    static string * value_modifiers = new string[] {"nosign", "const", "extended"};
    static  string * visibility_modifiers = new string[] {"public", "private", "inherit", "package"};
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
        pinstance_ = new Lexer(value);
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

Lexer::Lexer(/* args */)
{
    //
}

Lexer::~Lexer()
{
    //
}

void Lexer::function()
{
    //
}

void Lexer::value()
{
    //
}

void Lexer::lang_struct()
{
    //
}
