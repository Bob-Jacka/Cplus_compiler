#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

/*
This file represents abstract machine in C+ language.
*/

#include <mutex>
#include "../data/Variables.hpp"
#include "../data/exceptions/VirtualMachineException.hpp"
#include "../entities/Logger.hpp"
#include "../entities/VM/GarbageCollector/CollectorWithStop.cpp"

Data_object VM_settings {
    string name;
    bool is_multi_thread = false;
    bool is_ai_enabled = false;
    long long vm_memory = 0;
    IGarbageCollector pointy garbage_collector = null;

    //functions
    runtime_mem std::string generate_vm_name();

    VM_settings refer operator=(immutable VM_settings refer other_settings);

    VM_settings(immutable string refer name,
                bool is_multi_thread,
                bool is_ai_enabled,
                long long vm_memory,
                IGarbageCollector pointy garbage_collector);

    VM_settings(immutable string refer name, bool is_multi_thread, bool is_ai_enabled, long long vm_memory);

    VM_settings() = del;

    ~VM_settings() = default_impl;
};

/*
Registers of the abstract machine.
*/
Data_object VM_registers {
    string register_1 = "VM001";
    string register_2 = "VM002";
    string register_3 = "VM003";
    string register_4 = "VM004";
    string register_5 = "VM005";
    string register_6 = "VM006";
    string register_7 = "VM007";
    string register_8 = "VM008";
    string register_9 = "VM009";
    string register_10 = "VM010";
    string register_11 = "VM011";
    string register_12 = "VM012";
    string register_13 = "VM013";
    string register_14 = "VM014";
    string register_15 = "VM015";
    string register_16 = "VM016";
    string register_17 = "VM017";
    string register_18 = "VM018";
    string register_19 = "VM019";
    string register_20 = "VM020";
    string register_21 = "VM021";
    string register_22 = "VM022";
    string register_23 = "VM023";
    string register_24 = "VM024";
    string register_25 = "VM025";
    string register_26 = "VM026";

    string condition_register_001 = "VM027";
    string command_register_001 = "VM028";
};

/*
Indata_objections numbers of the abstract machine.
*/
enum VM_instructions {
    OP_BR = 0, /* branch */
    OP_ADD = 1, /* add  */
    OP_LD = 2, /* load */
    OP_ST = 3, /* store */
    OP_JSR = 4, /* jump to register */
    OP_AND = 5, /* bitwise and */
    OP_LDR = 6, /* load register */
    OP_STR = 7, /* store register */
    OP_RTI = 8, /* unused */
    OP_NOT = 9, /* bitwise not */
    OP_LDI = 10, /* load indirect */
    OP_STI = 11, /* store indirect */
    OP_JMP = 12, /* jump */
    OP_RES = 13, /* reserved (unused) */
    OP_LEA = 14, /* load effective address */
    OP_TRAP = 15, /* execute trap */
};

/*
Virtual Machine runs one line of code one by one.
*/
Entity_object VirtualMachine {
    runtime_mem VirtualMachine pointy pinstance_;
    runtime_mem std::mutex mutex_;
    runtime_mem VM_settings pointy vm_settings;

    Logger pointy logger;

    bool vm_running = false;

    explicit VirtualMachine(VM_settings pointy);

    None proceed_line();

    None _create_threads() immutable; //method repeat creating threads in abstract machine
    None main_cycle();

global:
    ~VirtualMachine();

    VirtualMachine(VirtualMachine refer other) = del;

    runtime_mem VirtualMachine pointy GetInstance(VM_settings pointy settings);

    runtime_mem VM_settings pointy get_machine_settings();

    None start_vm();

    None start_ai() immutable;

    None shutdown_vm();

    None assign_garbage_collector_strategy() immutable;

    [[nodiscard]] bool is_start_machine() immutable;

    [[nodiscard]] bool is_exit_machine() immutable;

    [[nodiscard]] bool is_ai_enabled() immutable;

    [[nodiscard]] bool is_multithread() immutable;

    None operator=(immutable VirtualMachine refer) = del;
};

VirtualMachine pointy VirtualMachine::pinstance_{null};
std::mutex VirtualMachine::mutex_;

#endif
