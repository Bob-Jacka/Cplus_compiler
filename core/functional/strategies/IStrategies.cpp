#include "core/data/Main_types.hpp"

struct Compiler_entities;
struct Controllers;

/*
Interface class for strategy pattern.
*/
class IStrategy {
public:
    virtual ~IStrategy() = default;

    virtual void doAlgorithm(const string &entry_point_name,
                             Controllers *controllers,
                             Compiler_entities *compiler_entities,
                             Logger *logger
    ) const;

    IStrategy(const IStrategy &) = delete;

    IStrategy &operator=(const IStrategy &) = delete;

    IStrategy(IStrategy &&) = delete;

protected:
    IStrategy() = default;
};
