#include "BaseException.hpp"

class VirtualMachineException final : BaseException {
public:
    static int vm_death();

    static int vm_out_of_memory();

    static int vm_failed_to_start();

    static int failedToInstanceVM();

    static int failed_to_instance_AI(); //throws if AI cannot be instantiated

    static int leak_of_memory();
};

int VirtualMachineException::vm_death() {
    std::cerr << "Virtual machine has died.";
    return 0;
}

int VirtualMachineException::vm_out_of_memory() {
    std::cerr << "Virtual machine running out of memory.";
    return 0;
}

int VirtualMachineException::vm_failed_to_start() {
    std::cerr << "Virtual machine has failed to start working.";
    return 0;
}

int VirtualMachineException::failedToInstanceVM() {
    std::cerr << "Error occurred in starting virtual machine";
    return 0;
}

int VirtualMachineException::failed_to_instance_AI() {
    std::cerr << "Error occurred in starting AI";
    return 0;
}

int VirtualMachineException::leak_of_memory() {
    std::cerr << "Virtual machine has leaked memory.";
    return 0;
}
