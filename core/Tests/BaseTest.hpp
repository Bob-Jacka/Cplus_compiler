#pragma once

#define TEST_MODE //TODO для проверки, удалить позже

#ifdef TEST_MODE
//Test dependencies

#include <iostream>
#include "../data/dependencies/catch_amalgamated.hpp"

//Static dependencies
#include "../functional/controllers_entities/FileAccessController.cpp"
#include "../functional/controllers_entities/MemoryController.cpp"
#include "../../static/UtilFuncs.hpp"

//VM entities to test
#include "../entities/VM/VirtualMachine.cpp"
#include "../entities/VM/VirtualMachineConsole.cpp"
#include "../entities/VM/GarbageCollector/CollectorWithStop.cpp"

/*
Base class of the unit tests.
Encapsulate all dependencies, so you not need to include all the dependencies
*/
class BaseTest;

#endif
