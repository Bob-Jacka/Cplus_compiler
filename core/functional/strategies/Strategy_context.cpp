#include "IStrategy.cpp"
#include <memory>
#include <string>

using namespace std;

class Strategy_context
{
private:
    unique_ptr<Strategy> strategy_;
    
public:
    Strategy_context() {};
    ~Strategy_context() {};

    Strategy_context(unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy)) {};

    void set_strategy(unique_ptr<Strategy> &&strategy);
    void doLogic(string entry_point_name) const;
    };

void Strategy_context::set_strategy(unique_ptr<Strategy> &&strategy)
{
    this->strategy_ = move(strategy);
}

void Strategy_context::doLogic(string entry_point_name) const
{
    if (strategy_) {
        strategy_->doAlgorithm(entry_point_name);
    } else {
        cout << "Context: Strategy isn't set\n";
    }
}