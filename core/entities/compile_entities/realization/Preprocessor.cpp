#include "../declaration/Preprocessor.hpp"

#include <fstream>

Preprocessor::Preprocessor() {
    //
}

Preprocessor::~Preprocessor() {
    delete&mutex_;
    delete&pinstance_;
    delete[] pinstance_;
    delete list_of_directives;
}

/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Preprocessor *Preprocessor::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Preprocessor();
    }
    return pinstance_;
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
Main function of the preprocessor entities.
Makes preprocess action.
*/
void Preprocessor::preprocess() const {
    throw PreprocessorException();
}
