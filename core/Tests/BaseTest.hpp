//Test dependencies
#include <data/dependencies/catch_amalgamated.hpp>
#include <iostream>

//Static dependencies
#include <static/UtilFuncs.hpp>
#include <functional/FileAccessController.cpp>
#include <functional/MemoryController.cpp>

//Compiler entities to test
#include <entities/Assembly_generator.cpp>
#include <entities/Binary_generator.cpp>
#include <entities/Lexer.cpp>
#include <entities/Linker.cpp>
#include <entities/Preprocessor.cpp>

/*
Base class of the tests.
*/
class BaseTest
{
public:
	BaseTest() {};
	virtual ~BaseTest() {};

private:
	//
};
