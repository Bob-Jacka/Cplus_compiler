/*
Collector with stop.
Will stop program execution during garbage collection process.
*/

#include <IGarbageCollector.cpp>
#include <mutex>

class CollectorWithStop : IGarbageCollector {
private:
	static CollectorWithStop* pinstance_;
	static std::mutex mutex_;
public:
    CollectorWithStop(CollectorWithStop& other) = delete;
	void operator=(const CollectorWithStop&) = delete;
	static CollectorWithStop* GetInstance();
    void collectors_pass();
    void collect_garbage();
};

CollectorWithStop* CollectorWithStop::pinstance_{ nullptr };
std::mutex CollectorWithStop::mutex_;

CollectorWithStop* CollectorWithStop::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new CollectorWithStop();
    }
    return pinstance_;
}

void CollectorWithStop::collectors_pass() {
    //
}

void CollectorWithStop::collect_garbage()
{
    //
}
