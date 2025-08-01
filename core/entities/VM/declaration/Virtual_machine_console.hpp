#ifndef VIRTUAL_MACHINE_CONSOLE_HPP
#define VIRTUAL_MACHINE_CONSOLE_HPP

#include "../Custom_operators.hpp"
/*
UI app
Console that represents abstract machine parameters and execution path.
*/

#include <mutex>

namespace VM {
    EntityObject VirtualMachineConsole {
        runtimeMem VirtualMachineConsole pointy pinstance_;
        runtimeMem std::mutex mutex_;

        None _update_UI() immutable;

        None _disconnect() immutable; //disconnect console from abstract machine

        VirtualMachineConsole();

    global:
        ~VirtualMachineConsole();

        VirtualMachineConsole(VirtualMachineConsole refer other) = del;

        runtimeMem VirtualMachineConsole pointy GetInstance();

        None draw_UI() immutable;

        None operator=(immutable VirtualMachineConsole refer) = del;
    };

    VirtualMachineConsole pointy VirtualMachineConsole::pinstance_{null};
    std::mutex VirtualMachineConsole::mutex_;
}

#endif
