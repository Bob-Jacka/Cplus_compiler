#include "../declaration/Virtual_machine_console.hpp"

//TODO сделать через паттерн наблюдатель взаимодействие с виртуальной машиной

//Constructor and destructor
VirtualMachineConsole::VirtualMachineConsole() {
    //
}

VirtualMachineConsole::~VirtualMachineConsole() {
    //
}

void VirtualMachineConsole::_update_UI() const {
    //
}

void VirtualMachineConsole::_disconnect() const {
    //
}

VirtualMachineConsole *VirtualMachineConsole::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new VirtualMachineConsole();
    }
    return pinstance_;
}

void VirtualMachineConsole::draw_UI() const {
    //
}
