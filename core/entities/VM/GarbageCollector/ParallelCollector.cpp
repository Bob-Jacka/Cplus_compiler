/*
Collector with parallel execution.
Will execute with program.
*/

#include <IGarbageCollector.cpp>
#include <mutex>

class ParallelCollector : IGarbageCollector {
private:
	static ParallelCollector * pinstance_;
	static std::mutex mutex_;
public:
    ParallelCollector(ParallelCollector& other) = delete;
	void operator=(const ParallelCollector&) = delete;
	static ParallelCollector* GetInstance();
    void collectors_pass();
    void collect_garbage();
};

ParallelCollector* ParallelCollector::pinstance_{ nullptr };
std::mutex ParallelCollector::mutex_;

ParallelCollector* ParallelCollector::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new ParallelCollector();
    }
    return pinstance_;
}

void ParallelCollector::collectors_pass() {
    //
}

void ParallelCollector::collect_garbage()
{
    //
}