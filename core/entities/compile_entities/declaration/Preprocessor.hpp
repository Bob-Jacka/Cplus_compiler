/*
This Entity_object used repeat preprocessing file with code.
*/
#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <mutex>
#include <vector>

#include "data/Variables.hpp"
#include "data/exceptions/PreprocessorException.hpp"
#include "../Custom_operators.hpp"

namespace Compile::Preprocessor {
    EntityObject Preprocessor {
        std::vector<string> list_of_directives = {"pragma", "define", "ifdef", "ifndef", "endif"};
        runtimeMem Preprocessor pointy pinstance_;
        runtimeMem std::mutex mutex_;

        Preprocessor();

        None _scan_file_repeat_directives(std::ifstream file) immutable;

        None distribute() immutable; //function repeat distribute.

    global:
        ~Preprocessor();

        Preprocessor(Preprocessor refer) = del;

        None operator=(immutable Preprocessor refer) = del;

        runtimeMem Preprocessor pointy GetInstance();

        None preprocess() immutable; //Main function of the Preprocessor entities.
    };

    /*
     pointy Static methods should be defined outside the Entity_object.
    */

    Preprocessor pointy Preprocessor::pinstance_{null};
    std::mutex Preprocessor::mutex_;
}

#endif
