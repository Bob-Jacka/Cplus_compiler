/*
This class used for preprocessing file with code.
*/

#include <data/exceptions/PreprocessorException.cpp>
#include <data/Variables.hpp>
#include <mutex>

class Preprocessor
{
private:
    string list_of_directives[3] = {"include", "pragma", "define"};
    static Preprocessor *pinstance_;
    static std::mutex mutex_;
    Preprocessor() {};

public:
    ~Preprocessor();
    Preprocessor(Preprocessor &other) = delete;

    void operator=(const Preprocessor &) = delete;

    static Preprocessor *GetInstance();

    void preprocess() const;
};

/**
 * Static methods should be defined outside the class.
 */

Preprocessor *Preprocessor::pinstance_{nullptr};
std::mutex Preprocessor::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Preprocessor *Preprocessor::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Preprocessor();
    }
    return pinstance_;
}

Preprocessor::Preprocessor()
{
    //
}

Preprocessor::~Preprocessor()
{
    delete& mutex_;
}

void Preprocessor::preprocess() const
{
    //
}