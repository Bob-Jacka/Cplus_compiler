#include "../declaration/Analyzer.hpp"

Analyzer::Analyzer() {
    //
}

Analyzer::~Analyzer() {
    delete&mutex_;
}


/**
 * The first time we call GetInstance we will lock the storage location,
 *      and then we make sure again that the variable is null, and then we
 *      set the value. RU:
 */
Analyzer *Analyzer::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Analyzer();
    }
    return pinstance_;
}

/*
 Main function of the analyzer process.
 Scan file for any errors
 */
void Analyzer::proceed_analysis() {
    //
}
