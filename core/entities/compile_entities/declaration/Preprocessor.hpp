/*
This class used for preprocessing file with code.
*/

#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <mutex>
#include <vector>

#include "data/Variables.hpp"
#include "data/exceptions/PreprocessorException.hpp"

class Preprocessor {
    std::vector<string> list_of_directives = {"pragma", "define", "ifdef", "ifndef", "endif"};
    static Preprocessor *pinstance_;
    static std::mutex mutex_;

    Preprocessor();

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

#endif