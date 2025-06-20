/*
UI app
Console that represents virtual machine parameters and execution path.
*/

#include <mutex>

class VirtualMachineConsole {
    static VirtualMachineConsole *pinstance_;
    static std::mutex mutex_;

    void _updateUI() const;

    VirtualMachineConsole();

public:
    ~VirtualMachineConsole();

    VirtualMachineConsole(VirtualMachineConsole &other) = delete;

    void operator=(const VirtualMachineConsole &) = delete;

    static VirtualMachineConsole *GetInstance();

    void drawUI() const;
};

//Constructor and destructor
VirtualMachineConsole::VirtualMachineConsole() {
    //
}

VirtualMachineConsole::~VirtualMachineConsole() {
    //
}

VirtualMachineConsole *VirtualMachineConsole::pinstance_{nullptr};
std::mutex VirtualMachineConsole::mutex_;

void VirtualMachineConsole::_updateUI() const {
    //
}

VirtualMachineConsole *VirtualMachineConsole::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new VirtualMachineConsole();
    }
    return pinstance_;
}

void VirtualMachineConsole::drawUI() const {
    //
}
