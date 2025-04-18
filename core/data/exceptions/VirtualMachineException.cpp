#include <BaseException.hpp>

class VirtualMachineException : BaseException
{
public:
    void vm_death();
    void vm_out_of_memory();
    void vm_failed_to_start();
    void failedToInstanceVM();
};

void VirtualMachineException::vm_death()
{
    std::cerr << "Virtual machine has died.";
}

void VirtualMachineException::vm_out_of_memory()
{
    std::cerr << "Virtual machine running out of memory.";
}

void VirtualMachineException::vm_failed_to_start()
{
    std::cerr << "Virtual machine has failed to start working.";
}

void VirtualMachineException::failedToInstanceVM() {
    std::cerr << "Error occurred in starting virtual machine";
}
