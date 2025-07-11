#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include "../Custom_operators.hpp"

/*
Class for logging info and warns and critical errors
*/
class Logger final {
    std::string logger_name;
    std::ifstream *log_file;

    None create_log_file();

    None create_logger_name();

global:
    generic<typename T>
    None log(T val);

    ~Logger() = default;

    Logger() = default;
};

#endif