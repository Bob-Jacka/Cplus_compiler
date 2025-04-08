/*
This class needs for linkega stage.
*/

#include <data/exceptions/LinkerException.cpp>

class Linker
{

private:
    void append_file();

    static Singleton * pinstance_;
    static std::mutex mutex_;

Linker() {}
~Linker() {}


public:
    Linker();
    ~Linker();
    Singleton(Singleton &other) = delete;

    void operator=(const Linker &) = delete;

    void link();

    static Linker *GetInstance(const std::string& value);
};

/**
 * Static methods should be defined outside the class.
 */

 Linker* Linker::pinstance_{nullptr};
 std::mutex Linker::mutex_;
 
 /**
  * The first time we call GetInstance we will lock the storage location
  *      and then we make sure again that the variable is null and then we
  *      set the value. RU:
  */
 Linker *Linker::GetInstance(const std::string& value)
 {
     std::lock_guard<std::mutex> lock(mutex_);
     if (pinstance_ == nullptr)
     {
         pinstance_ = new Linker(value);
     }
     return pinstance_;
 }

void Linker::append_file()
{
    //
}

Linker::Linker()
{
    //
}

Linker::~Linker()
{
    //
}

void Linker::link()
{
    //
}