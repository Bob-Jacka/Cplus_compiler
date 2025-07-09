#ifndef IGARBAGE_COLLECTOR_HPP
#define IGARBAGE_COLLECTOR_HPP

/*
Abstract class for garbage collection process.
*/

#include <mutex>

class IGarbageCollector {
    //One collector pass on objects alive
    virtual void collectors_pass() const = 0;

protected:
    IGarbageCollector() = default;

public:
    //Main function of collector
    virtual void collect_garbage() const = 0;

    virtual ~IGarbageCollector() = default;
};


#endif //IGARBAGE_COLLECTOR_HPP
