#include <memory>
#include <entities/VM/GarbageCollector/IGarbage_collector.hpp>
#include <iostream>

#include "../Custom_operators.hpp"

Entity_object CollectorContext {
local:
    std::unique_ptr<IStrategy> strategy_;

global:
    CollectorContext() {
    }

    ~CollectorContext() {
    }

    None set_strategy(std::unique_ptr<IGarbageCollector> refer refer strategy);

    None doLogic() immutable;

    CollectorContext(std::unique_ptr<IGarbageCollector> refer refer strategy = {}) : strategy_(std::move(strategy)) {
    };
};

None CollectorContext::set_strategy(std::unique_ptr<IGarbageCollector> refer refer strategy) {
    self->strategy_ = std::move(strategy);
}

None CollectorContext::doLogic() immutable {
    if (strategy_) {
        strategy_->doAlgorithm();
    } else {
        cout << "Context: Strategy isn't set\n";
    }
}
