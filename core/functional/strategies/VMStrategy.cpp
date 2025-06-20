#include "core/data/Variables.hpp"
#include "core/entities/VM/VirtualMachine.cpp"
#include "core/entities/VM/VirtualMachineConsole.cpp"
#include "core/functional/strategies/IStrategies.cpp"

class VirtualMachineConsole;
struct VM_settings;
class VirtualMachine;

/*
Strategy that runs program one line by one.
*/
class VMStrategy final : public IStrategy {
public:
    explicit VMStrategy(Logger *p_logger = nullptr, VirtualMachineConsole *p_console = nullptr) {
        this->p_logger = p_logger;
        this->p_console = p_console;

        this->log_file = new std::ofstream();
    };

    ~VMStrategy() = default;

    void doAlgorithm(string entry_point_name,
                     Controllers *controllers,
                     Compiler_entities *compiler_entities,
                     Logger *logger);

private:
    VM_settings *p_settings = nullptr;
    VirtualMachine *p_vm_instance = nullptr;
    VirtualMachineConsole *p_console = nullptr;
    Logger *p_logger = nullptr;
};

/*
Algorithm of the virtual machine strategy.
*/
void VMStrategy::doAlgorithm(string entry_point_name,
                             Controllers *controllers,
                             Compiler_entities *compiler_entities,
                             Logger *logger) {
    //Virtual machine strategy set up.
    {
        *p_settings = VM_settings{
            .name = VM_settings::generate_vm_name(),
            .is_multi_thread = false,
            .is_ai_enabled = false,
            .vm_memory = 1000000,
            .garbage_collector = CollectorWithStop::GetInstance(),
        };

        p_vm_instance = VirtualMachine::GetInstance(p_settings);
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
        delete p_console;
        delete p_settings;
    }
}
