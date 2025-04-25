#include <mutex>

class Analyzer {

private:
    static Analyzer* pinstance_;
    static std::mutex mutex_;
    Analyzer() {};

public:
    Analyzer(Analyzer* another_obj) = delete;

    void operator=(const Analyzer&) = delete;

    static Analyzer* GetInstance();
    ~Analyzer() {}
};

Analyzer* Analyzer::pinstance_{ nullptr };
std::mutex Analyzer::mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Analyzer* Analyzer::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Analyzer();
    }
    return pinstance_;
}