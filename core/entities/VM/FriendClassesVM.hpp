#ifndef FRIENDCLASSESVM_HPP
#define FRIENDCLASSESVM_HPP

#include "../data/Main_types_vm.hpp"

class VirtualMachine;

class VirtualMachineTest {
    VirtualMachine *priv_param = VirtualMachine::GetInstance();

global:
    var3 do_test();
};

class VirtualMachineConsoleTest {
    VirtualMachineConsole *priv_param = VirtualMachineConsole::GetInstance();

global:
    //
};

class CollectorWithStopTest {
    CollectorWithStop *priv_param = CollectorWithStop::GetInstance();

global:
    //
};

class ParallelCollectorTest {
    ParallelCollector *priv_param = ParallelCollector::GetInstance();

global:
    //
};

#endif //FRIENDCLASSESVM_HPP
