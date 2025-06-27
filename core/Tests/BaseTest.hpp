#pragma once
//Test dependencies

#include <iostream>
#include "../data/dependencies/catch_amalgamated.hpp"

//Static dependencies
#include "../functional/FileAccessController.cpp"
#include "../functional/MemoryController.cpp"
#include "../../static/UtilFuncs.hpp"

//Compiler entities to test
#include "../entities/compile_entities/Assembly_generator.cpp"
#include "../entities/compile_entities/Binary_generator.cpp"
#include "../entities/compile_entities/Lexer.cpp"
#include "../entities/compile_entities/Linker.cpp"
#include "../entities/compile_entities/Preprocessor.cpp"

/*
Base class of the unit tests.
Encapsulate all dependencies, so you not need to include all the dependencies
*/
inline class BaseTest final;
