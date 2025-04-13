#include <IStrategy.cpp>
#include <entities/VirtualMachine.cpp>

/*
Strategy that runs program one line by one.
*/
class VMStrategy : public Strategy
{
private:
    /* data */
public:
    VMStrategy(/* args */) {}
    ~VMStrategy() {}
    void doAlgorithm(void);
};

/*
Algorithm of the virtual machine strategy.
*/
void VMStrategy::doAlgorithm(void)
{
    VirtualMachine *vm_instance = VirtualMachine.GetInstance();
}
