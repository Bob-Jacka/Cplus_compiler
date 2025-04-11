#include <Variables.hpp>
#include <data/exceptions/VirtualMachineException.cpp>

struct VM_settings {
    string name = "";
    bool is_multi_thread = false;
    long mem_allocate = 0;
};

/*
Virtual Machine runs one line of code by one.
*/
class VirtualMachine
{
private:
    static VirtualMachine * pinstance_;
    static std::mutex mutex_;

    VM_settings vm_settings = settings;

    void proceed_line();
    void generate_vm_name();
    void create_threads();

protected:
    VirtualMachine(VM_settings settings) {};
    ~VirtualMachine() {};

public:
    VirtualMachine(VirtualMachine &other) = delete;
    void operator=(const Singleton &) = delete;
    static VirtualMachine *GetInstance(VM_settings settings);
    VM_settings get_machine_settings();
    bool start_machine();
    bool exit_machine();
    bool is_multithread();
};

VirtualMachine* VirtualMachine::pinstance_{nullptr};
std::mutex VirtualMachine::mutex_;

VirtualMachine *VirtualMachine::GetInstance(VM_settings settings)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        VM_settings settings = new VM_settings();
        pinstance_ = new VirtualMachine(settings);
    }
    return pinstance_;
}

void VirtualMachine::proceed_line()
{
    //
}

void VirtualMachine::generate_vm_name()
{
    //
}

void VirtualMachine::create_threads()
{
    //
}

VM_settings VirtualMachine::get_machine_settings()
{
    return this.vm_settings;
}

bool VirtualMachine::start_machine()
{
    return false;
}

bool VirtualMachine::exit_machine()
{
    return false;
}

bool VirtualMachine::is_multithread()
{
    return this->vm_settings.is_multi_thread;
}
