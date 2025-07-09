#include "../declaration/Strategy_context.hpp"

#include <iostream>

Strategy_context::Strategy_context() {
    this->strategy_ = nullptr;
}

void Strategy_context::set_strategy(unique_ptr<IStrategy> &&strategy) {
    this->strategy_ = std::move(strategy);
}

/*
 Function for do logic with given strategy in strategy_ param.
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
