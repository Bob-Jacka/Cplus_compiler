#pragma once

#ifndef MAIN_TYPES.HPP
#define MAIN_TYPES .HPP

// Controllers dependencies.
#include <functional/FileAccessController.cpp>
#include <functional/MemoryController.cpp>

//Strategies
#include <functional/strategies/Strategy_context.cpp>

// Include compiler entities.
#include <entities/Lexer.cpp>
#include <entities/Linker.cpp>
#include <entities/Preprocessor.cpp>
#include <entities/Assembly_generator.cpp>

// Structure with controllers.
struct Controllers
{
private:
	FileAccessController *file_controller;
	MemoryController *mem_controller;

public:
	void init_controllers()
	{
		this->file_controller = FileAccessController.GetInstance();
		this->mem_controller = MemoryController.GetInstance();
	}

	void destroy_controllers()
	{
		delete this->file_controller;
		delete this->mem_controller;
	}
};

// Compilator entities structure.
struct Comp_entities
{
private:
	Lexer *lexer;
	Linker *linker;
	Preprocessor *preprocessor;
	Assembly_generator *asm_gen;

	Strategy_context *s_context;

public:
	void init_entities()
	{
		this->lexer = new Lexer();
		this->linker = new Linker();
		this->preprocessor = new Preprocessor();
		this->asm_gen = new Assembly_generator();

		this->s_context = new Strategy_context();
	};

	void destroy_entities()
	{
		delete this->lexer;
		delete this->linker;
		delete this->preprocessor;
		delete this->asm_gen;
		delete this->s_context;
	};
};

#endif MAIN_TYPES.HPP