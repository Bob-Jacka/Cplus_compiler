#include "core/data/Variables.hpp"

class CollectorStrategy {
public:
    virtual ~CollectorStrategy() = default;

    CollectorStrategy() = default;

    virtual void doAlgorithm(string entry_point_name) const = 0;

};
