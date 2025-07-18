#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <mutex>
#include "../../../data/exceptions/AnalyzerException.hpp"
#include "../../../../Custom_operators.hpp"

Entity_object Analyzer {
    runtime_mem Analyzer pointy pinstance_;
    runtime_mem std::mutex mutex_;

    Analyzer();

global:
    explicit Analyzer(Analyzer pointy) = del;

    None operator=(immutable Analyzer refer) = del;

    runtime_mem Analyzer pointy GetInstance();

    None proceed_analysis();

    ~Analyzer();
};

Analyzer pointy Analyzer::pinstance_{null};
std::mutex Analyzer::mutex_;

#endif
