#include <data/exceptions/BinaryGeneratorException.cpp>
#include <mutex>

class Binary_generator
{
private:
    static Binary_generator *pinstance_;
    static std::mutex mutex_;
    Binary_generator() {}
    
public:
    Binary_generator() {};
    ~Binary_generator() {};

    void generate_binary();

    Binary_generator(Binary_generator &other) = delete;
    void operator=(const Binary_generator &) = delete;
    static Binary_generator *GetInstance();
};

Binary_generator *Binary_generator::pinstance_{nullptr};
std::mutex Binary_generator::mutex_;

#define OBJECT_FILE_NAME "object"

/**
 * Main entry point of the Binary generator entity
 */
void Binary_generator::generate_binary()
{
    controllers->getFileController()->create_object_file(OBJECT_FILE_NAME);
}

Binary_generator *Binary_generator::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Binary_generator();
    }
    return pinstance_;
}

Binary_generator::~Binary_generator() {
    delete& mutex_;
}