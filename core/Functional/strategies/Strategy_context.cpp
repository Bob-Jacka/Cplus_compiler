#include <IStrategy.cpp>
#include <memory>
#include <string>

using namespace std;

class Strategy_context
{
private:
    unique_ptr<IStrategy> strategy_;
public:
    Strategy_context(/* args */) {};
    ~Strategy_context() {};
    void set_strategy(unique_ptr<IStrategy> &&strategy);
    void doLogic() const;
    Strategy_context(unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy)) = delete;
};

void Strategy_context::set_strategy(unique_ptr<IStrategy> &&strategy)
{
    this.strategy_ = move(strategy);
}

void Strategy_context::doLogic() const
{
    if (strategy_) {
        strategy_->doAlgorithm();
    } else {
        cout << "Context: Strategy isn't set\n";
    }
}