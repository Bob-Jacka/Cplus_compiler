#include "../data/exceptions/BinaryGeneratorException.cpp"

class Binary_generator {
    static Binary_generator *pinstance_;
    static std::mutex mutex_;

    Binary_generator() = default;

public:
    ~Binary_generator();

    void generate_binary(const FileAccessController *f_controller);

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
void Binary_generator::generate_binary(const FileAccessController *f_controller) {
    f_controller->create_object_file(OBJECT_FILE_NAME);
}

Binary_generator *Binary_generator::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Binary_generator();
    }
    return pinstance_;
}

Binary_generator::~Binary_generator() {
    delete&mutex_;
}
