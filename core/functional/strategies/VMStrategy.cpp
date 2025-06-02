#include "functional/strategies/IStrategy.cpp"
#include "core/entities/VM/VirtualMachine.cpp"
#include "core/entities/VM/VirtualMachineConsole.cpp"

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
    VM_settings *p_settings;
    VirtualMachine* p_vm_instance;
    GarbageCollector* p_g_collector;
    VirtualMachineConsole* p_console;

    //Virtual machine strategy set up.
    {
        p_settings = {
        .name = VM_settings::generate_vm_name(),
        .is_multi_thread = false,
        .vm_memory = 1000000,
        .garbageCollector = CollectorWithStop(),
        }
        
        p_vm_instance = VirtualMachine::GetInstance(p_settings);
        p_g_collector = GarbageCollectro::GetInstance();
        p_console = VirtualMachineConsole::GetInstance();
    }
    
    p_vm_instance->start_vm();

    /*
    Algorithm flow
    */

    p_vm_instance->shutdown_vm();

    //End of the virtual machine strategy
    {
        delete p_vm_instance;
        delete p_g_collector;
        delete p_console;
        delete p_settings;
    }
}
