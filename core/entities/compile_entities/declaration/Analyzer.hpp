#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <mutex>
#include "../../../data/exceptions/AnalyzerException.hpp"

class Analyzer {
    static Analyzer *pinstance_;
    static std::mutex mutex_;

    Analyzer();

public:
    explicit Analyzer(Analyzer *) = delete;

    void operator=(const Analyzer &) = delete;

    static Analyzer *GetInstance();

    void proceed_analysis();

    ~Analyzer();
};

Analyzer *Analyzer::pinstance_{nullptr};
std::mutex Analyzer::mutex_;

#endif
