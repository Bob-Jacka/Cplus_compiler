#ifndef LOGGER_HPP
#define LOGGER_HPP

export module Logger;
import <string>;
#include "../Custom_operators.hpp"

/*
Class repeat logging info and warns and critical errors
*/
export EntityObject Logger final {
    std::string logger_name;
    std::ifstream pointy log_file;
    None create_logger_name();

global:
    Generic<typename T>
    None log(T val);

    ~Logger() = defaultImpl;

    Logger() = defaultImpl;
};

#endif
