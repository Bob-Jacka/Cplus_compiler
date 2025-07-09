#include "../declaration/Vm_strategy.hpp"

VMStrategy::VMStrategy(VMStrategy const &) {
    this->log_file = nullptr;
}


/*
Algorithm of the virtual machine strategy.
*/
void VMStrategy::doAlgorithm(const string &entry_point_name,
                             Controllers *controllers,
                             Compiler_entities *compiler_entities,
                             Logger *logger) override {
    //Virtual machine strategy set up.
    {
        *p_settings = VM_settings{
            .name = VM_settings::generate_vm_name(),
            .is_multi_thread = false,
            .is_ai_enabled = false,
            .vm_memory = 1000000,
        };

        p_vm_instance = VirtualMachine::GetInstance(p_settings);
        p_console = VirtualMachineConsole::GetInstance();
    }

    p_vm_instance->start_vm();

    /*
    Algorithm flow
    */

    //

    p_vm_instance->shutdown_vm();

    //End of the virtual machine strategy
    {
        delete p_vm_instance;
        delete p_console;
        delete p_settings;
        delete logger;
    }
}
