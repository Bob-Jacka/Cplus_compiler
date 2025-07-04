/*
Collector with stop.
Will stop program execution during garbage collection process.
*/

#include "IGarbageCollector.cpp"

class CollectorWithStop final : IGarbageCollector {
    static CollectorWithStop *pinstance_;
    static std::mutex mutex_;

    CollectorWithStop();

public:
    ~CollectorWithStop() override;

    CollectorWithStop(CollectorWithStop &other) = delete;

    void operator=(const CollectorWithStop &) = delete;

    static CollectorWithStop *GetInstance();

    void collectors_pass() const override;

    void collect_garbage() const override;
};

CollectorWithStop *CollectorWithStop::pinstance_{nullptr};
std::mutex CollectorWithStop::mutex_;

//Constructor and destructor
CollectorWithStop::CollectorWithStop() {
    //
}

CollectorWithStop::~CollectorWithStop() {
    //
}

CollectorWithStop *CollectorWithStop::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new CollectorWithStop();
    }
    return pinstance_;
}

void CollectorWithStop::collectors_pass() const {
    //
}

void CollectorWithStop::collect_garbage() const {
    //
}
