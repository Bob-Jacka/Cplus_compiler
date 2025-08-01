#include <memory>
#include <entities/VM/GarbageCollector/IGarbage_collector.hpp>
#include <iostream>

#include "../Custom_operators.hpp"
#include "strategies/IStrategies.hpp"

namespace VM {
    Entity_object CollectorContext {
        local:
            std::unique_ptr<IStrategy> strategy_;

        global:
            CollectorContext() {
        }

        ~CollectorContext() {
        }

        None set_strategy(std::unique_ptr<VM::IGarbageCollector> refer refer strategy);

        None doLogic() immutable;

        CollectorContext(std::unique_ptr<VM::IGarbageCollector> refer refer strategy = {}) : strategy_(std::move(strategy)) {
        };
    };

    None CollectorContext::set_strategy(std::unique_ptr<VM::IGarbageCollector> refer refer strategy) {
        self->strategy_ = std::move(strategy);
    }

    None CollectorContext::doLogic() immutable {
        if (strategy_) {
            strategy_->doAlgorithm();
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
}
