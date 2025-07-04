/*
This file represents virtual machine in C+ language.
*/

#include "core/data/Variables.hpp"
#include "core/data/exceptions/VirtualMachineException.cpp"
#include <mutex>
#include "core/entities/VM/GarbageCollector/CollectorWithStop.cpp"
#include "core/entities/Logger.hpp"

struct VM_settings {
    string name = "";
    bool is_multi_thread = false;
    bool is_ai_enabled = false;
    long long vm_memory = 0;
    IGarbageCollector *garbage_collector = nullptr;

    //functions
    static std::string generate_vm_name();

    VM_settings &operator=(const VM_settings &other_settings);

    VM_settings::VM_settings(const string &name,
                             bool is_multi_thread,
                             bool is_ai_enabled,
                             long long vm_memory,
                             IGarbageCollector *garbage_collector);

    VM_settings::VM_settings(const string &name, bool is_multi_thread, bool is_ai_enabled, long long vm_memory);

    VM_settings::VM_settings() = delete;

    VM_settings::~VM_settings() = default;
};

VM_settings::VM_settings(const string &name,
                         const bool is_multi_thread,
                         const bool is_ai_enabled,
                         const long long vm_memory,
                         IGarbageCollector *garbage_collector) {
    this->name = name;
    this->is_multi_thread = is_multi_thread;
    this->is_ai_enabled = is_ai_enabled;
    this->vm_memory = vm_memory;

    this->garbage_collector = garbage_collector;
}

VM_settings::VM_settings(const string &name,
                         const bool is_multi_thread,
                         const bool is_ai_enabled,
                         const long long vm_memory) {
    this->name = name;
    this->is_multi_thread = is_multi_thread;
    this->is_ai_enabled = is_ai_enabled;
    this->vm_memory = vm_memory;

    this->garbage_collector = nullptr;
}


/*
Generates name of the virtual machine
*/
std::string VM_settings::generate_vm_name() {
    return "VM" + rand();
}

VM_settings &VM_settings::operator=(const VM_settings &other_settings) {
    auto res = VM_settings{
        .name = other_settings.name,
        .is_multi_thread = other_settings.is_multi_thread,
        .is_ai_enabled = other_settings.is_ai_enabled,
        .vm_memory = other_settings.vm_memory,
    };
    return res;
}

/*
Registers of the virtual machine.
*/
struct VM_registers {
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
class VirtualMachine {
    static VirtualMachine *pinstance_;
    static std::mutex mutex_;
    static VM_settings *vm_settings;

    Logger *VirtualMachine::logger;

    bool vm_running = false;

    explicit VirtualMachine(VM_settings *);

    void proceed_line();

    void _create_threads() const; //method for creating threads in virtual machine
    void main_cycle();

public:
    ~VirtualMachine();

    VirtualMachine(VirtualMachine &other) = delete;

    static VirtualMachine *GetInstance(VM_settings *settings);

    static VM_settings *get_machine_settings();

    void start_vm();

    void start_ai() const;

    void shutdown_vm();

    void assign_garbage_collector_strategy() const;

    [[nodiscard]] bool is_start_machine() const;

    [[nodiscard]] bool is_exit_machine() const;

    [[nodiscard]] bool is_ai_enabled() const;

    [[nodiscard]] bool is_multithread() const;

    void operator=(const VirtualMachine &) = delete;
};

VirtualMachine *VirtualMachine::pinstance_{nullptr};
std::mutex VirtualMachine::mutex_;

//Constructor and destructor
VirtualMachine::VirtualMachine(VM_settings *settings) {
    VirtualMachine::vm_settings = settings;
    this->logger = new Logger();
    if (settings->is_multi_thread) {
        this->_create_threads();
    }
}

VirtualMachine::~VirtualMachine() {
    delete&vm_settings;
    delete&mutex_;
    delete&logger;
}

VirtualMachine *VirtualMachine::GetInstance(VM_settings *settings) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        vm_settings = settings;
        pinstance_ = new VirtualMachine(settings);
    }
    return pinstance_;
}

VM_settings *VirtualMachine::get_machine_settings() {
    return vm_settings;
}

/*
Method for starting virtual machine entity
*/
void VirtualMachine::start_vm() {
    try {
        vm_running = true;
    } catch (const exception &e) {
        this->logger->log("Error occurred in starting virtual machine");
        this->logger->log(e.what());
        cerr << e.what() << "\n";
    }
}

/*
 *Method for starting AI functionality
 */
void VirtualMachine::start_ai() const {
    this->logger->log("Starting ai");
    VirtualMachine::vm_settings->is_ai_enabled = true;
}

/*
Method for shutdown virtual machine entity
*/
void VirtualMachine::shutdown_vm() {
    try {
        vm_running = false;
    } catch (const exception &e) {
        this->logger->log("Error occurred in virtual machine shutdown");
        this->logger->log(e.what());
        cerr << e.what() << "\n";
    }
}

void VirtualMachine::assign_garbage_collector_strategy() const {
    try {
    } catch (const exception &e) {
        this->logger->log("Error occurred in assign garbage collector");
        this->logger->log(e.what());
        cerr << e.what() << "\n";
    }
}

void VirtualMachine::proceed_line() {
    //
}

void VirtualMachine::_create_threads() const {
    try {
    } catch (const exception &e) {
        this->logger->log("Error occurred in creating threads in virtual machine");
        this->logger->log(e.what());
        cerr << e.what() << "\n";
    }
}

/*
Main cycle of the virtual machine execution.
Runs program by vm operations.
*/
void VirtualMachine::main_cycle() { {
        Load Arguments,



        12
    } {
        Setup, 12
    }

    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while (running) {
        /* FETCH */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op) {
            case VM_instructions::OP_ADD: {
                ADD, 6
            }
            break;
            case VM_instructions::OP_AND: {
                AND, 7
            }
            break;
            case VM_instructions::OP_NOT: {
                NOT, 7
            }
            break;
            case VM_instructions::OP_BR: {
                BR, 7
            }
            break;
            case VM_instructions::OP_JMP: {
                JMP, 7
            }
            break;
            case VM_instructions::OP_JSR: {
                JSR, 7
            }
            break;
            case VM_instructions::OP_LD: {
                LD, 7
            }
            break;
            case VM_instructions::OP_LDI: {
                LDI, 6
            }
            break;
            case VM_instructions::OP_LDR: {
                LDR, 7
            }
            break;
            case VM_instructions::OP_LEA: {
                LEA, 7
            }
            break;
            case VM_instructions::OP_ST: {
                ST, 7
            }
            break;
            case VM_instructions::OP_STI: {
                STI, 7
            }
            break;
            case VM_instructions::OP_STR: {
                STR, 7
            }
            break;
            case VM_instructions::OP_TRAP: {
                TRAP, 8
            }
            break;
            case VM_instructions::OP_RES: {
            }
            case VM_instructions::OP_RTI: {
            }
            default: {
                BAD OPCODE,



                7
            }
            break;
        }
    }
}

/*
Method for checking if virtual machine switching on.
*/
bool VirtualMachine::is_start_machine() const {
    return this->vm_running;
}

/*
Method for checking if virtual machine switching off.
*/
bool VirtualMachine::is_exit_machine() const {
    return !vm_running;
}

bool VirtualMachine::is_ai_enabled() const {
    return vm_settings->is_ai_enabled();
}

bool VirtualMachine::is_multithread() const {
    return vm_settings->is_multi_thread;
}
