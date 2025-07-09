#ifndef FRIENDCLASSESVM_HPP
#define FRIENDCLASSESVM_HPP

#include "../data/Main_types_vm.hpp"

class VirtualMachine;

class VirtualMachineTest {
    VirtualMachine *priv_param = VirtualMachine::GetInstance();

public:
    auto do_test();
};

class VirtualMachineConsoleTest {
    VirtualMachineConsole *priv_param = VirtualMachineConsole::GetInstance();

public:
    //
};

class CollectorWithStopTest {
    CollectorWithStop *priv_param = CollectorWithStop::GetInstance();

public:
    //
};

class ParallelCollectorTest {
    ParallelCollector *priv_param = ParallelCollector::GetInstance();

public:
    //
};

#endif //FRIENDCLASSESVM_HPP
