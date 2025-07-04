/*
Header file with virtual machine types included
 */

#pragma once

#ifndef MAIN_TYPES_VM_HPP
#define MAIN_TYPES_VM_HPP

#include "../entities/VM/VirtualMachine.cpp"
#include "../entities/VM/VirtualMachineConsole.cpp"
#include "../entities/VM/GarbageCollector/IGarbageCollector.cpp"

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
};

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
