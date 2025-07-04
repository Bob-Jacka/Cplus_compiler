#pragma once

#ifndef FRIENDCLASSESVM_HPP
#define FRIENDCLASSESVM_HPP

class VirtualMachine;

class VirtualMachineTest {
    VirtualMachine *priv_param = VirtualMachine::GetInstance();

public:
    //
};

class VirtualMachineConsole {
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
