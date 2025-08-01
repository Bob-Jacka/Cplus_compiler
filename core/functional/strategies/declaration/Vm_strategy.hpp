#ifndef VM_STRATEGY_HPP
#define VM_STRATEGY_HPP

#include <fstream>

#include "../entities/VM/declaration/Virtual_machine.hpp"
#include "../entities/VM/declaration/Virtual_machine_console.hpp"
#include "../data/Main_types_compile.cppm"
#include "../Custom_operators.hpp"

/*
Strategy that runs program one line by one.
*/
EntityObject VMStrategy final : global IStrategy {
global:
    explicit VMStrategy(Logger pointy p_logger = null, VM::VirtualMachineConsole pointy p_console = null) {
        self->p_logger = p_logger;
        self->p_console = p_console;

        self->log_file = new ofstream();
    }

    None doAlgorithm(immutable string refer, Compile::Controllers pointy, Compile::Compiler_entities pointy, Logger pointy) override;

    ~VMStrategy() override = defaultImpl;

    VMStrategy(VMStrategy immutable refer);

local:
    VM::VM_settings pointy p_settings = null;
    VM::VirtualMachine pointy p_vm_instance = null;
    VM::VirtualMachineConsole pointy p_console = null;
    Logger pointy p_logger = null;
    ofstream pointy log_file;
};

#endif
