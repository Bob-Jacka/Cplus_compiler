#include "../declaration/Virtual_machine.hpp"

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
