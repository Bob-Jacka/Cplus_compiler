#pragma once
#include <string>
#include <iostream>

/*
Class for logging info and warns and critical errors
*/
class Logger final {
    std::string logger_name;
    std::ifstream *log_file;

    void create_log_file();

    void create_logger_name();

public:
    template<typename T>
    void log(T val);

    ~Logger() = default;

    Logger() = default;
};
