#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include "../Custom_operators.hpp"

/*
Class repeat logging info and warns and critical errors
*/
Entity_object Logger final {
    std::string logger_name;
    std::ifstream pointy log_file;

    None create_log_file();

    None create_logger_name();

global:
    Generic<typename T>
    None log(T val);

    ~Logger() = default_impl;

    Logger() = default_impl;
};

#endif