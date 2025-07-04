#include "BaseException.hpp"

class MainExceptions final : public BaseException {
public:
    static int context_not_initialized();

    static int wrong_argument_count();

    static int unknown_compiler_mode();

    static int unknown_compiler_flag();

    static int no_strategy_assignment();
};

int MainExceptions::context_not_initialized() {
    std::cerr << "Strategy context has not been initialized.";
    return 0;
}

int MainExceptions::wrong_argument_count() {
    std::cerr << "Wrong number of arguments.";
    std::cerr << "Wrong argument count, expected two or more with flags, given 1 argument.";
    return 0;
}

int MainExceptions::unknown_compiler_mode() {
    std::cerr << "Unknown compiler mode.";
    return 0;
}

int MainExceptions::unknown_compiler_flag() {
    std::cerr << "Unknown compiler flag.";
    return 0;
}

int MainExceptions::no_strategy_assignment() {
    std::cerr << "No strategy assignment.";
    return 0;
}