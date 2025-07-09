#ifndef BASE_TEST_EXCEPTION_HPP
#define BASE_TEST_EXCEPTION_HPP

#define TEST_MODE //TODO для проверки, удалить позже

#ifdef TEST_MODE
//Test dependencies

#include <iostream>
#include "../data/dependencies/catch_amalgamated.hpp"

//Static dependencies
#include "../functional/controllers_entities/declaration/File_access_controller.hpp"
#include "../functional/controllers_entities/declaration/Memory_controller.hpp"
#include "../../static/Util_funcs.hpp"

//VM entities to test
#include "../entities/VM/declaration/Virtual_machine.hpp"
#include "../entities/VM/declaration/Virtual_machine_console.hpp"
#include "../entities/VM/GarbageCollector/CollectorWithStop.cpp"

/*
Base class of the unit tests.
Encapsulate all dependencies, so you not need to include all the dependencies
*/
class BaseTest;

#endif

#endif