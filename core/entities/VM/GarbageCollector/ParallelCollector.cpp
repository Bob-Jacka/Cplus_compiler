/*
Collector with parallel execution.
Will execute with program.
*/

#include "IGarbageCollector.cpp"
#include <mutex>

class ParallelCollector final : IGarbageCollector {
private:
    static ParallelCollector *pinstance_;
    static std::mutex mutex_;

    ParallelCollector() {
    };

    void collectors_pass() const override;

public:
    ~ParallelCollector() override;

    ParallelCollector(ParallelCollector &other) = delete;

    void operator=(const ParallelCollector &) = delete;

    static ParallelCollector *GetInstance();

    void collect_garbage() const override;
};

ParallelCollector *ParallelCollector::pinstance_{nullptr};
std::mutex ParallelCollector::mutex_;

//Constructor and destructor
ParallelCollector::~ParallelCollector() {
    //
}

ParallelCollector *ParallelCollector::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new ParallelCollector();
    }
    return pinstance_;
}

void ParallelCollector::collectors_pass() const {
    //
}

void ParallelCollector::collect_garbage() const {
    //
}
