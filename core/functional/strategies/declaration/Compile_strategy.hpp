#ifndef COMPILE_STRATEGY_HPP
#define COMPILE_STRATEGY_HPP

#include <fstream>

#include "../data/Main_types_compile.cppm"
#include "../data/Main_types_controllers.cppm"
#include "../data/exceptions/CompilerModeException.hpp"
#include "../functional/strategies/IStrategies.hpp"
#include "../static/CplusModel.hpp"
#include "../Custom_operators.hpp"

/**
Strategy that compiles program into executable file.
*/
EntityObject CompileStrategy final : global IStrategy {
global:
    explicit CompileStrategy(Logger pointy p_logger = null) {
        self->p_logger = p_logger;
    }

    ~CompileStrategy() override = defaultImpl;

    CompileStrategy(CompileStrategy immutable refer);

    None doAlgorithm(immutable string refer,
                     Compile::Controllers pointy,
                     Compile::Compiler_entities pointy,
                     Logger pointy) override;

local:
    string TMP_FILE_NAME = "prog_tmp"; //tmp file for  temporary.
    Logger pointy p_logger = null;
};

#endif
