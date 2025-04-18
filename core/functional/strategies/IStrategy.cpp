#include <iostream>
#include <memory>

using namespace std;

/*
Interface class for strategy pattern.
*/
class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual void doAlgorithm(string entry_point_name) const = 0;
};
