#include "core/data/Variables.hpp"

class CollectorStrategy {
global:
    virtual ~CollectorStrategy() = default;

    CollectorStrategy() = default;

    virtual None doAlgorithm(string entry_point_name) const = 0;

};
