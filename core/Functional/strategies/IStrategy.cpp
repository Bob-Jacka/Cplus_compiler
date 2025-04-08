#include <iostream>
#include <memory>

using namespace std;

/*
Interface class for strategy pattern.
*/
class Strategy {
    public:
    virtual ~Strategy() = default;
    virtual void doAlgorithm(void) const = 0;
};

class Context {
private:
    unique_ptr<Strategy> strategy_;

public:
    explicit Context(unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy))
    {
    }
    /**
     * Обычно Контекст позволяет заменить объект Стратегии во время выполнения.
     */
    void set_strategy(unique_ptr<Strategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }
    /**
     * Вместо того, чтобы самостоятельно реализовывать множественные версии
     * алгоритма, Контекст делегирует некоторую работу объекту Стратегии.
     */
    void do_businessLogic() const
    {
        if (strategy_) {
            std::cout << "Context: using strategy - \n";
            std::string result = strategy_->doAlgorithm();
            std::cout << result << "\n";
        } else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }
};