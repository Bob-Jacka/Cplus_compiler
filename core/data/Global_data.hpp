#pragma once

#ifndef GLOBAL_DATA.HPP
#define GLOBAL_DATA.HPP

#include "core/data/Main_types.hpp"
#include "core/entities/Logger.cpp"

static Load_compiler_parameter* load_parameter = new Load_compiler_parameter{}; //Global instance of load parameters.
static Compiler_params* compile_params = new Compiler_params(); //Global instance of compiler params.

static Compiler_entities* program_entites = new Compiler_entities(); //Programm entities for actions.
static Controllers* controllers = new Controllers(); //Global instance of controllers entities.

static Logger* logger = new Logger();
#endif GLOBAL_DATA.HPP