/*
This class used for preprocessing file with code.
*/

#include <mutex>
#include "core/data/Variables.hpp"
#include "core/data/exceptions/PreprocessorException.cpp"

class Preprocessor {
    string list_of_directives[] = {"pragma", "define", "ifdef", "ifndef", "endif"};
    static Preprocessor *pinstance_;
    static std::mutex mutex_;

    Preprocessor() = default;

    void _scan_file_for_directives(std::ifstream file) const;

    void distribute() const; //function for distribute.

public:
    ~Preprocessor();

    Preprocessor(Preprocessor &other) = delete;

    void operator=(const Preprocessor &) = delete;

    static Preprocessor *GetInstance();

    void preprocess() const; //Main function of the Preprocessor entities.
};

/**
 * Static methods should be defined outside the class.
 */

Preprocessor *Preprocessor::pinstance_{nullptr};
std::mutex Preprocessor::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Preprocessor *Preprocessor::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Preprocessor();
    }
    return pinstance_;
}

Preprocessor::~Preprocessor() {
    delete&mutex_;
    delete&pinstance_;
    delete[] pinstance_;
    delete[] list_of_directives;
}

void Preprocessor::_scan_file_for_directives(std::ifstream file) const {
    //for (string line : file) {
    //    if (starts_with_directive(line)) {
    //        distribute(line);
    //    }
    //}
}

void Preprocessor::distribute() const {
    //
}

/*
Main function of the preprocessor entities. Makes preprocess action.
*/
void Preprocessor::preprocess() const {
    throw PreprocessorException();
}
