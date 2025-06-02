/*
This class needs for assembly generate.
*/

#include <data/exceptions/AssemblyGeneratorException.cpp>
#include "static/UtilFuncs.hpp"
#include <mutex>

class Assembly_generator
{

private:
    void movl();
    void movr();
    void movz();
    void jmp();
    void neg();
    void cmp();
    void div();
    void push();
    void pushq();
    void sub();
    void inc();

    int nextRegister = 0;
    const string registers[4] = {"R0", "R1", "R2", "R3"}; //Registers available.

    string get_next_register();
    string get_assembly_line(string token_line) const;
    static Assembly_generator *pinstance_;
    static std::mutex mutex_;
    Assembly_generator();

public:
    Assembly_generator(Assembly_generator * another_obj) = delete;
    ~Assembly_generator() {}

    void operator=(const Assembly_generator &) = delete;

    static Assembly_generator *GetInstance();
    void generate_asm(std::vector<string>& tokens) const noexcept;
};

Assembly_generator *Assembly_generator::pinstance_{nullptr};
std::mutex Assembly_generator::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Assembly_generator *Assembly_generator::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Assembly_generator();
    }
    return pinstance_;
}

Assembly_generator::Assembly_generator(/* args */)
{
    //
}

Assembly_generator::~Assembly_generator()
{
    //
}

Assembly_generator *Assembly_generator::GetInstance()
{
    return nullptr;
}

void Assembly_generator::movl()
{
    //
}

void Assembly_generator::movr()
{
    //
}

void Assembly_generator::movz()
{
    //
}

void Assembly_generator::jmp()
{
    //
}

void Assembly_generator::neg()
{
    //
}

void Assembly_generator::cmp()
{
    //
}

void Assembly_generator::div()
{
    //
}

void Assembly_generator::push()
{
    //
}

void Assembly_generator::pushq()
{
    //
}

void Assembly_generator::sub()
{
    //
}

void Assembly_generator::inc()
{
    //
}

string Assembly_generator::get_next_register()
{
    return registers[nextRegister++ % registers->length()];
}

/*
Proceed token line into assembly line.
*/
string Assembly_generator::get_assembly_line(string token_line) const
{
    string assemblyCode;
    string* splitted = utility::line_splitter(token_line); //splitted token line.
    if (splitted->size() == 3) {
        string a = splitted[0];
        string op = splitted[1];
        string b = splitted[2];

        string reg = get_next_register();
        assemblyCode += "LOAD " + a + " " + reg + "\n";
        if (op == "+") {
            assemblyCode += "ADD " + b + " " + reg + "\n";
        } else if (op == "-") {
            assemblyCode += "SUB " + b + " " + reg + "\n";
        } else if (op == "*") {
            assemblyCode += "MUL " + b + " " + reg + "\n";
        } else if (op == "/") {
            assemblyCode += "DIV " + b + " " + reg + "\n";
        }
        assemblyCode += "STORE " + reg + " RESULT\n";
    } else {
        assemblyCode = "ERROR: Неверное выражение\n";
        throw AssemblyGeneratorException::ErrorInAssemblyGeneration();
    }
    return assemblyCode;
}


/*
Main entry point in Assembly generator
*/
void Assembly_generator::generate_asm(std::vector<string>& tokens) const noexcept {
    for (string token_line: tokens) {
        get_assembly_line(token_line);
    }
}