#include <memory>
#include <entities/VM/GarbageCollector/IGarbageCollector.cpp>
#include <iostream>

using namespace std;

class CollectorContext {
private:
    unique_ptr<Strategy> strategy_;

public:
    CollectorContext() {
    };

    ~CollectorContext() {
    };

    void set_strategy(unique_ptr<IGarbageCollector> &&strategy);

    void doLogic() const;

    CollectorContext(unique_ptr<IGarbageCollector> &&strategy = {}) : strategy_(std::move(strategy)) {
    };
};

void CollectorContext::set_strategy(unique_ptr<IGarbageCollector> &&strategy) {
    this->strategy_ = move(strategy);
}

void CollectorContext::doLogic() const {
    if (strategy_) {
        strategy_->doAlgorithm();
    } else {
        cout << "Context: Strategy isn't set\n";
    }
}
