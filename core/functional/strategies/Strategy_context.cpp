#include "IStrategies.hpp"
#include <memory>

class Logger;
using namespace std;

class Strategy_context {
    unique_ptr<IStrategy> strategy_;

public:
    Strategy_context() = default;

    ~Strategy_context() = default;

    explicit Strategy_context(unique_ptr<IStrategy> &&strategy = {}) : strategy_(std::move(strategy)) {
    }

    void set_strategy(unique_ptr<IStrategy> &&strategy);

    void doLogic(const string &entry_point_name,
                 Controllers *controllers,
                 Compiler_entities *compiler_entities,
                 Logger *logger) const;
};

void Strategy_context::set_strategy(unique_ptr<IStrategy> &&strategy) {
    this->strategy_ = std::move(strategy);
}

/*
 *Function for do logic with given strategy in strategy_ param.
 */
void Strategy_context::doLogic(const string &entry_point_name,
                               Controllers *controllers,
                               Compiler_entities *compiler_entities,
                               Logger *logger) const {
    if (strategy_) {
        strategy_->doAlgorithm(entry_point_name,
                               controllers,
                               compiler_entities,
                               logger);
    } else {
        cout << "Context: Strategy isn't set\n";
    }
}
