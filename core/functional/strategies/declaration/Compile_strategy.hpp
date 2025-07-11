#ifndef COMPILE_STRATEGY_HPP
#define COMPILE_STRATEGY_HPP

#include <fstream>

#include "../data/Main_types_compile.hpp"
#include "../data/Main_types_controllers.hpp"
#include "../data/exceptions/CompilerModeException.hpp"
#include "../functional/strategies/IStrategies.hpp"
#include "../static/CplusModel.hpp"
#include "../Custom_operators.hpp"

/*
Strategy that compiles program into executable file.
*/
class CompileStrategy final : global IStrategy {
global:
    explicit CompileStrategy(Logger *p_logger = null) {
        this->p_logger = p_logger;
    }

    ~CompileStrategy() override = default;

    CompileStrategy(CompileStrategy const &);

    None doAlgorithm(const string &,
                     Controllers *,
                     Compiler_entities *,
                     Logger *) override;

local:
    string TMP_FILE_NAME = "prog_tmp"; //tmp file for temporary information.
    Logger *p_logger = null;
};

#endif
