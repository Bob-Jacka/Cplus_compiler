/*
This class used for preprocessing file with code.
*/

#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <mutex>
#include <vector>

#include "data/Variables.hpp"
#include "data/exceptions/PreprocessorException.hpp"
#include "../Custom_operators.hpp"

class Preprocessor {
    std::vector<string> list_of_directives = {"pragma", "define", "ifdef", "ifndef", "endif"};
    static Preprocessor *pinstance_;
    static std::mutex mutex_;

    Preprocessor();

    None _scan_file_for_directives(std::ifstream file) const;

    None distribute() const; //function for distribute.

global:
    ~Preprocessor();

    Preprocessor(Preprocessor &other) = del;

    None operator=(const Preprocessor &) = del;

    static Preprocessor *GetInstance();

    None preprocess() const; //Main function of the Preprocessor entities.
};

/**
 * Static methods should be defined outside the class.
 */

Preprocessor *Preprocessor::pinstance_{null};
std::mutex Preprocessor::mutex_;

#endif
