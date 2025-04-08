/*
This class needs for printing code (assembly).
*/

#define C_ext ".c"
#define Header_c_ext ".hpp"
#define Assembly_ext ".asm"

class Printer
{

private:
    static Printer * pinstance_;
    static std::mutex mutex_;

    protected:
    Printer()
    {
    }
    ~Printer() {}

public:
    Printer(/* args */);
    ~Printer();
    Printer(Printer &other) = delete;

    void operator=(const Printer &) = delete;

    static Printer *GetInstance();

    void print_assembly();
};

/**
 * Static methods should be defined outside the class.
 */

 Printer* Printer::pinstance_{nullptr};
 std::mutex Printer::mutex_;
 
 /**
  * The first time we call GetInstance we will lock the storage location
  *      and then we make sure again that the variable is null and then we
  *      set the value. RU:
  */
 Printer *Printer::GetInstance(const std::string& value)
 {
     std::lock_guard<std::mutex> lock(mutex_);
     if (pinstance_ == nullptr)
     {
         pinstance_ = new Printer(value);
     }
     return pinstance_;
 }

Printer::Printer()
{
}

Printer::~Printer()
{
}

void Printer::print_assembly()
{
}
