#pragma once

#ifndef MAIN_TYPES.HPP
#define MAIN_TYPES .HPP

// Controllers dependencies.
#include <functional/FileAccessController.cpp>
#include <functional/MemoryController.cpp>

//Strategies
#include <functional/strategies/Strategy_context.cpp>

//Include compiler entities.
#include <entities/Lexer.cpp>
#include <entities/Linker.cpp>
#include <entities/Preprocessor.cpp>
#include <entities/Assembly_generator.cpp>
#include <Binary_generator.cpp>

//Structure with controllers.
struct Controllers
{
private:
	FileAccessController *file_controller;
	MemoryController *mem_controller;

public:
	FileAccessController* getFileController() const;
	MemoryController* getMemoryController() const;

	void init_controllers()
	{
		try {
			this->file_controller = FileAccessController::GetInstance();
			this->mem_controller = MemoryController::GetInstance();
		}
		catch (std::exception& e) {
			colored_txt_output("Error in initializing global controller entities.", Color::red);
			throw e;
		}
	}

	void destroy_controllers()
	{
		try {
			delete this->file_controller;
			delete this->mem_controller;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in destroying global controller entities.", Color::red);
			throw e;
		}
	}

	FileAccessController* Controllers::getFileController() const
	{
		try {
			return file_controller;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in returning file controller", Color::red);
			throw e;
		}
	}

	MemoryController* Controllers::getMemoryController() const
	{
		try {
			return mem_controller;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in returning memory conroller", Color::red);
			throw e;
		}
	}
};

// Compilator entities structure.
struct Compiler_entities
{
private:
	Lexer *lexer;
	Linker *linker;
	Preprocessor *preprocessor;
	Assembly_generator *asm_gen;
	Binary_generator* bin_gen;

	Strategy_context *s_context;

public:
	Lexer* getLexer() const;
	Linker* getLinker() const;
	Preprocessor* getPreprocessor() const;
	Assembly_generator* getAssemblyGenerator() const;
	Binary_generator* Compiler_entities::getBinaryGenerator() const;
	Strategy_context* getStrategyContext() const;

	void init_entities()
	{
		try {
			this->lexer = Lexer::GetInstance();
			this->linker = Linker::GetInstance();
			this->preprocessor = Preprocessor::GetInstance();
			this->asm_gen = Assembly_generator::GetInstance();
			this->bin_gen = Binary_generator::GetInstance();

			this->s_context = new Strategy_context();
		}
		catch (std::exception& e) {
			colored_txt_output("Error in initializing global compiler entities.", Color::red);
			throw e;
		}
	};

	/*
	Function for destroying created entities.
	*/
	void destroy_entities()
	{
		try {
			delete this->lexer;
			delete this->linker;
			delete this->preprocessor;
			delete this->asm_gen;
			delete this->bin_gen;
			delete this->s_context;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in destroying global compiler entities.", Color::red);
			throw e;
		}
	};

	Lexer* Compiler_entities::getLexer() const
	{
		try {
			return lexer;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in return lexer", Color::red);
			throw e;
		}
	}

	Linker* Compiler_entities::getLinker() const
	{
		try {
			return linker;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in return linker", Color::red);
			throw e;
		}
	}

	Preprocessor* Compiler_entities::getPreprocessor() const
	{
		try {
			return preprocessor;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in return preprocessor", Color::red);
			throw e;
		}
	}

	Binary_generator* Compiler_entities::getBinaryGenerator() const
	{
		try {
			return bin_gen;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in return assembly generator", Color::red);
			throw e;
		}
	}

	Assembly_generator* Compiler_entities::getAssemblyGenerator() const
	{
		try {
			return asm_gen;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in return assembly generator", Color::red);
			throw e;
		}
	}

	Strategy_context* Compiler_entities::getStrategyContext() const
	{
		try {
			return s_context;
		}
		catch (std::exception& e) {
			colored_txt_output("Error in return strategy context", Color::red);
			throw e;
		}
	}
};

/*
Structure only for compiler parameters.
In other words compiler flags.
*/
struct Compiler_params {
	const_string ASSEMBLER = "assembler";
	const_string VM = "vm";
	const_string AI = "ai";
	const_string BINARY = "binary";
	const_string COMPILE = "compile";

	const_string MODE = "mode";
};

/*
Several modes of the compiler.
*/
enum Compile_mode {
	DEBUG = 1, //compiles program without optimizations.
	TEST = 2, //SPECIAL MODE. Runs compiler tests.
	RELEASE = 3, //compiles program with optimizations.
};

//Структура для параметров загрузки.
struct Load_compiler_parameter
{
	bool is_vm = false; //(Mode) Enters virtual machine mode.
	bool is_cplus_only = false; //(Mode) generates only executable file.

	bool is_ai = false; //Turns on artificial intelligence to tell you that your code on cp is sh*t.
	bool is_assembler = false; //Generates assembly file, that you can watch.
	bool is_binary = false; //Generates binary file that you can watch.

	Compile_mode compiler_mode; // Debug or release or dev or test.
};

#endif MAIN_TYPES.HPP