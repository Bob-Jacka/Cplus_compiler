/*
This class needs for assembly generate.
*/

#include <data/exceptions/AssemblyGeneratorException.hpp>

class Assembly_generator
{

private:
void movl();
void movr();
void jmp();
void neg();
void cmp();
void div();
void push();
void pushq();
void sub();
void inc();

protected:
    Assembly_generator()
    {
    }
    ~Assembly_generator() {}

public:
Assembly_generator(/* args */);
Assembly_generator(Assembly_generator another_obj) = delete;
~Assembly_generator();

void operator=(const Assembly_generator &) = delete;

static Assembly_generator *GetInstance(const std::string& value);
    
};

Assembly_generator* Assembly_generator::pinstance_{nullptr};
std::mutex Assembly_generator::mutex_;


/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Assembly_generator *Assembly_generator::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Assembly_generator(value);
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

Assembly_generator *Assembly_generator::GetInstance(const std::string &value)
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
