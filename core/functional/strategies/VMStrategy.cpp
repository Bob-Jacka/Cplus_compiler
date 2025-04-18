#include <IStrategy.cpp>
#include <entities/VM/VirtualMachine.cpp>

/*
Strategy that runs program one line by one.
*/
class VMStrategy : Strategy
{
public:
    VMStrategy() {}
    ~VMStrategy() {}
    void doAlgorithm(string file_name);
};

/*
Algorithm of the virtual machine strategy.
*/
void VMStrategy::doAlgorithm(string file_name)
{
    //Virtual machine strategy set up.
    VirtualMachine *vm_instance = VirtualMachine::GetInstance(VM_settings());

    //End of the virtual machine strategy
    delete vm_instance;
}
