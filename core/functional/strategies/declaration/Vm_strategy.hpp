#ifndef VM_STRATEGY_HPP
#define VM_STRATEGY_HPP

#include <fstream>

#include "../../../entities/VM/declaration/Virtual_machine.hpp"
#include "../../../entities/VM/declaration/Virtual_machine_console.hpp"
#include "../../../data/Main_types_compile.hpp"

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
    VMStrategy(VMStrategy const&);

private:
    VM_settings *p_settings = nullptr;
    VirtualMachine *p_vm_instance = nullptr;
    VirtualMachineConsole *p_console = nullptr;
    Logger *p_logger = nullptr;
    ofstream *log_file;
};

#endif
