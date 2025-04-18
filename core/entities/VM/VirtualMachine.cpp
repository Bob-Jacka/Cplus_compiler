/*
This file represents virtual machine in c+ language.
*/

#include <Variables.hpp>
#include <data/exceptions/VirtualMachineException.cpp>
#include <mutex>
#include <CollectorWithStop.cpp>

struct VM_settings
{
    string name = "";
    bool is_multi_thread = false;
    long mem_allocate = 0;
    long long vm_memory;

    IGarbageCollector* garbageCollector;
};

int VM_settings::operator=(const VM_settings& other_settings) {
    //
}

/*
Registers of the virtual machine.
*/
static struct VM_registers {
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
Instructions numbers of the virtual machine.
*/
enum VM_instructions {
     OP_BR = 0, /* branch */
     OP_ADD = 1,    /* add  */
     OP_LD = 2,     /* load */
     OP_ST = 3,     /* store */
     OP_JSR = 4,    /* jump register */
     OP_AND = 5,    /* bitwise and */
     OP_LDR = 6,    /* load register */
     OP_STR = 7,    /* store register */
     OP_RTI = 8,    /* unused */
     OP_NOT = 9,    /* bitwise not */
     OP_LDI = 10,    /* load indirect */
     OP_STI = 11,    /* store indirect */
     OP_JMP = 12,    /* jump */
     OP_RES = 13,    /* reserved (unused) */
     OP_LEA = 14,    /* load effective address */
     OP_TRAP = 15,    /* execute trap */
};

/*
Virtual Machine runs one line of code one by one.
*/
class VirtualMachine
{
private:
    static VirtualMachine *pinstance_;
    static std::mutex mutex_;
    static VM_settings* vm_settings;

    bool vm_running = false;

    void proceed_line();
    void __generate_vm_name();
    void __create_threads();
    void __main_cycle();

protected:
    VirtualMachine(VM_settings settings) {};

public:
    ~VirtualMachine();
    VirtualMachine(VirtualMachine &other) = delete;
    
    static VirtualMachine *GetInstance(VM_settings settings);
    static VM_settings* get_machine_settings();
    void start_vm();
    void shutdown_vm();
    void assign_garbage_collector_strategy();

    bool is_start_machine() const;
    bool is_exit_machine() const;
    bool is_multithread() const;

    void operator=(const VirtualMachine&) = delete;
};

VirtualMachine *VirtualMachine::pinstance_{nullptr};
std::mutex VirtualMachine::mutex_;

VirtualMachine::~VirtualMachine()
{
    delete& vm_settings;
    delete& mutex_;
}

VirtualMachine *VirtualMachine::GetInstance(VM_settings settings)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        vm_settings = new VM_settings();
        pinstance_ = new VirtualMachine(settings);
    }
    return pinstance_;
}

VM_settings* VirtualMachine::get_machine_settings()
{
    return vm_settings;
}

void VirtualMachine::start_vm()
{
    vm_running = true;
}

void VirtualMachine::shutdown_vm()
{
    vm_running = false;
}

void VirtualMachine::assign_garbage_collector_strategy()
{
    //
}

void VirtualMachine::proceed_line()
{
    //
}

void VirtualMachine::__generate_vm_name()
{
    VirtualMachine::vm_settings->name = "VM" + rand();
}

void VirtualMachine::__create_threads()
{
    //
}

/*
Main cycle of the virtual machine execution.
Runs program by vm operations.
*/
void VirtualMachine::__main_cycle()
{
    { Load Arguments, 12 }
    { Setup, 12 }

    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running)
    {
        /* FETCH */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op)
        {
        case VM_instructions::OP_ADD:
        { ADD, 6 }
        break;
        case VM_instructions::OP_AND:
        { AND, 7 }
        break;
        case VM_instructions::OP_NOT:
        { NOT, 7 }
        break;
        case VM_instructions::OP_BR:
        { BR, 7 }
        break;
        case VM_instructions::OP_JMP:
        { JMP, 7 }
        break;
        case VM_instructions::OP_JSR:
        { JSR, 7 }
        break;
        case VM_instructions::OP_LD:
        { LD, 7 }
        break;
        case VM_instructions::OP_LDI:
        { LDI, 6 }
        break;
        case VM_instructions::OP_LDR:
        { LDR, 7 }
        break;
        case VM_instructions::OP_LEA:
        { LEA, 7 }
        break;
        case VM_instructions::OP_ST:
        { ST, 7 }
        break;
        case VM_instructions::OP_STI:
        { STI, 7 }
        break;
        case VM_instructions::OP_STR:
        { STR, 7 }
        break;
        case VM_instructions::OP_TRAP:
        { TRAP, 8 }
        break;
        case VM_instructions::OP_RES:
        case VM_instructions::OP_RTI:
        default:
        { BAD OPCODE, 7 }
        break;
        }
    }
    shutdown_vm();
}

/*
Method for cheching if virtual machine switching on.
*/
bool VirtualMachine::is_start_machine() const
{
    return this->vm_running;
}

/*
Method for cheching if virtual machine switching off.
*/
bool VirtualMachine::is_exit_machine() const
{
    return !this->vm_running;
}

bool VirtualMachine::is_multithread() const
{
    return VirtualMachine::vm_settings->is_multi_thread;
}
