#include "../declaration/Virtual_machine_console.hpp"

//TODO сделать через паттерн наблюдатель взаимодействие с виртуальной машиной

//Constructor and destructor
VirtualMachineConsole::VirtualMachineConsole() {
    //
}

VirtualMachineConsole::~VirtualMachineConsole() {
    //
}

None VirtualMachineConsole::_update_UI() const {
    //
}

None VirtualMachineConsole::_disconnect() const {
    //
}

VirtualMachineConsole *VirtualMachineConsole::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == null) {
        pinstance_ = new VirtualMachineConsole();
    }
    return pinstance_;
}

None VirtualMachineConsole::draw_UI() const {
    //
}
