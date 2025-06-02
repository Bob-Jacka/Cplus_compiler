#pragma once

#include "core/data/Main_types.hpp"

/*
Class for logging info and warns
*/
class Logger {
private:
    string logger_name;
    std::ifstream* log_file;

    void create_log_file();
    void create_logger_name();

public:
    template<typename T>
    void log(T);

    ~Logger();
    Logger();
};