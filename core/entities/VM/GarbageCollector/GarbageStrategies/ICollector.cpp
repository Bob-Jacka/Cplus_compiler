#include <Variables.hpp>

class CollectorStrategy
{
public:
	virtual ~CollectorStrategy() = default;
	virtual void doAlgorithm(string entry_point_name) const = 0;

private:
	//
};
