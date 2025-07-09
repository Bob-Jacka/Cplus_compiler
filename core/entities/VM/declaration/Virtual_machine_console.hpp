#ifndef VIRTUAL_MACHINE_CONSOLE_HPP
#define VIRTUAL_MACHINE_CONSOLE_HPP

/*
UI app
Console that represents virtual machine parameters and execution path.
*/

#include <mutex>

class VirtualMachineConsole {
    static VirtualMachineConsole *pinstance_;
    static std::mutex mutex_;

    void _update_UI() const;

    void _disconnect() const; //disconnect console from virtual machine

    VirtualMachineConsole();

public:
    ~VirtualMachineConsole();

    VirtualMachineConsole(VirtualMachineConsole &other) = delete;

    static VirtualMachineConsole *GetInstance();

    void draw_UI() const;

    void operator=(const VirtualMachineConsole &) = delete;
};

VirtualMachineConsole *VirtualMachineConsole::pinstance_{nullptr};
std::mutex VirtualMachineConsole::mutex_;

#endif