#pragma once

struct Compiler_entities;
struct Controllers;

/*
Interface class for strategy pattern.
*/
class IStrategy {
public:
    virtual ~IStrategy() = default;

    virtual void doAlgorithm(const string &,
                             Controllers *,
                             Compiler_entities *,
                             Logger *
    ) = 0;

    IStrategy(const IStrategy &) = delete;

    IStrategy &operator=(const IStrategy &) = delete;

    IStrategy(IStrategy &&) = delete;

protected:
    IStrategy() = default;
};
