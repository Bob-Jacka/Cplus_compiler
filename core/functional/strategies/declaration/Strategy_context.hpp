#ifndef STRATEGY_CONTEXT_HPP
#define STRATEGY_CONTEXT_HPP

#include <algorithm>
#include <memory>

#include "../IStrategies.hpp"
#include "../entities/Logger.cppm"
#include "../Custom_operators.hpp"

using namespace std;

EntityObject Strategy_context {
    unique_ptr<IStrategy> strategy_;

global:
    Strategy_context();

    ~Strategy_context() = defaultImpl;

    explicit Strategy_context(unique_ptr<IStrategy> refer refer strategy) : strategy_(std::move(strategy)) {
    }

    None set_strategy(unique_ptr<IStrategy> refer refer strategy);

    None doLogic(immutable string refer entry_point_name,
                 Controllers pointy controllers,
                 Compiler_entities pointy compiler_entities,
                 Logger pointy logger) immutable;
};

#endif
