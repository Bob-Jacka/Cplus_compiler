#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <mutex>
#include "../data/exceptions/AnalyzerException.hpp"
#include "../Custom_operators.hpp"

/**
 One namespace for all compile entities in compiler.
 */
namespace Compile::Analyzer {
    EntityObject Analyzer {
        runtimeMem Analyzer pointy pinstance_;
        runtimeMem std::mutex mutex_;

        Analyzer();

    global:
        explicit Analyzer(Analyzer pointy) = del;

        ~Analyzer();

        None operator=(immutable Analyzer refer) = del;

        runtimeMem Analyzer pointy GetInstance();

        /**
         * Main function in analyzer entity
         */
        None proceed_analysis();
    };

    Analyzer pointy Analyzer::pinstance_{null};
    std::mutex Analyzer::mutex_;
}

#endif
