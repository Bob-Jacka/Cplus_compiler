#include <data/exceptions/BinaryGeneratorException.cpp>

class Binary_generator
{
private:
    void generate_binary();

    static Binary_generator * pinstance_;
    static std::mutex mutex_;

protected:
    Binary_generator() {}
    ~Binary_generator() {}

public:
    Binary_generator(/* args */) {}
    ~Binary_generator() {}

    Binary_generator(Binary_generator &other) = delete;
    void operator=(const Binary_generator &) = delete;
    static Binary_generator *GetInstance();
};

Binary_generator* Binary_generator::pinstance_{nullptr};
std::mutex Binary_generator::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
void Binary_generator::generate_binary()
{
    //
}

Binary_generator *Binary_generator::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Binary_generator(value);
    }
    return pinstance_;
}