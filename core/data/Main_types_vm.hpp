/*
Header file with virtual machine types included
 */

#ifndef MAIN_TYPES_VM_HPP
#define MAIN_TYPES_VM_HPP

#include "../entities/VM/declaration/Virtual_machine.hpp"
#include "../entities/VM/declaration/Virtual_machine_console.hpp"

//Collector realizations
#include "../entities/VM/GarbageCollector/CollectorWithStop.cpp"
#include "../entities/VM/GarbageCollector/ParallelCollector.cpp"

/*
 Structure with Virtual machine entities
 */
struct VM_entities {
private:
    VirtualMachine *vm;
    VirtualMachineConsole *console;
    IGarbageCollector *gc;

    VM_settings *settings;

public:
    VM_entities(VirtualMachine *_vm, VirtualMachineConsole *_console);

    ~VM_entities();

    void init_entities();

    void destroy_entities() const;

    VirtualMachine *get_virtual_machine() const;

    VirtualMachineConsole *get_vmconsole() const;

    IGarbageCollector *get_gc() const;

    VM_settings *get_settings() const;
};

/*
 Error safety get method for virtual machine
 Return VirtualMachine or nullptr if error
 */
inline VirtualMachine *VM_entities::get_virtual_machine() const -> VirtualMachine * {
    try {
        return vm;
    } catch ([[maybe_unused]] std::exception &e) {
        //
    }
    return nullptr;
}

inline VirtualMachineConsole *VM_entities::get_vmconsole() const -> VirtualMachineConsole * {
    try {
        return console;
    } catch ([[maybe_unused]] std::exception &e) {
        //
    }
    return nullptr;
}

inline IGarbageCollector *VM_entities::get_gc() const -> IGarbageCollector * {
    try {
        return gc;
    } catch ([[maybe_unused]] std::exception &e) {
        //
    }
    return nullptr;
}

inline VM_settings *VM_entities::get_settings() const -> VM_settings * {
    try {
        return settings;
    } catch ([[maybe_unused]] std::exception &e) {
        //
    }
    return nullptr;
}

inline void VM_entities::init_entities() {
    this->settings = new VM_settings("VM_settings", false, false, 0);
    this->vm = VirtualMachine::GetInstance(settings);
    this->console = VirtualMachineConsole::GetInstance();
}

inline void VM_entities::destroy_entities() const {
    delete this->vm;
    delete this->console;
}

#endif //MAIN_TYPES_VM_HPP
