#ifndef VIRTUAL_MACHINE_EXCEPTION_HPP
#define VIRTUAL_MACHINE_EXCEPTION_HPP
#include "BaseException.hpp"

class VirtualMachineException final : public BaseException {
public:
    static int vm_death();

    static int vm_out_of_memory();

    static int vm_failed_to_start();

    static int failedToInstanceVM();

    static int failed_to_instance_AI(); //throws if AI cannot be instantiated

    static int leak_of_memory();
};

inline int VirtualMachineException::vm_death() {
    std::cerr << "Virtual machine has died.";
    return 0;
}

inline int VirtualMachineException::vm_out_of_memory() {
    std::cerr << "Virtual machine running out of memory.";
    return 0;
}

inline int VirtualMachineException::vm_failed_to_start() {
    std::cerr << "Virtual machine has failed to start working.";
    return 0;
}

inline int VirtualMachineException::failedToInstanceVM() {
    std::cerr << "Error occurred in starting virtual machine";
    return 0;
}

inline int VirtualMachineException::failed_to_instance_AI() {
    std::cerr << "Error occurred in starting AI";
    return 0;
}

inline int VirtualMachineException::leak_of_memory() {
    std::cerr << "Virtual machine has leaked memory.";
    return 0;
}

#endif
