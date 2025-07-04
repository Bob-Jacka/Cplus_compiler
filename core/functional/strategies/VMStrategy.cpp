#include "../../entities/VM/VirtualMachineConsole.cpp"
#include "../../entities/VM/VirtualMachine.cpp"
#include "../../data/Main_types_compile.hpp"

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

        this->log_file = new ofstream();
    }

    void doAlgorithm(const string &, Controllers *, Compiler_entities *, Logger *) override;

    ~VMStrategy() override = default;

private:
    VM_settings *p_settings = nullptr;
    VirtualMachine *p_vm_instance = nullptr;
    VirtualMachineConsole *p_console = nullptr;
    Logger *p_logger = nullptr;
    ofstream *log_file;
};

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

    p_vm_instance->shutdown_vm();

    //End of the virtual machine strategy
    {
        delete p_vm_instance;
        delete p_console;
        delete p_settings;
    }
}
