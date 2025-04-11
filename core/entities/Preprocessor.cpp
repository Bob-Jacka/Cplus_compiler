/*
This class used for preprocessing file with code.
*/

#include <data/exceptions/PreprocessorException.hpp>
#include <data/Variables.hpp>

class Preprocessor
{

private:
string []list_of_directives = {"include", "pragma", "define"};
static Preprocessor * pinstance_;
static std::mutex mutex_;

protected:
Preprocessor()
    {
    }
~Preprocessor() {}

public:
    Preprocessor();
    ~Preprocessor();
    Preprocessor(Preprocessor &other) = delete;

    void operator=(const Preprocessor &) = delete;

    static Preprocessor *GetInstance(const std::string& value);

    void preprocess();
};

/**
 * Static methods should be defined outside the class.
 */

 Preprocessor* Preprocessor::pinstance_{nullptr};
 std::mutex Preprocessor::mutex_;
 
 /**
  * The first time we call GetInstance we will lock the storage location
  *      and then we make sure again that the variable is null and then we
  *      set the value. RU:
  */
 Preprocessor *Preprocessor::GetInstance(const std::string& value)
 {
     std::lock_guard<std::mutex> lock(mutex_);
     if (pinstance_ == nullptr)
     {
         pinstance_ = new Preprocessor(value);
     }
     return pinstance_;
 }

Preprocessor::Preprocessor(/* args */)
{
    //
}

Preprocessor::~Preprocessor()
{
    //
}

Preprocessor::preprocess() {
    //
}