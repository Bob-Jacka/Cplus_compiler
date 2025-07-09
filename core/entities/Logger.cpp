#include "Logger.hpp"
#include <chrono>
#include <iostream>

void Logger::create_log_file() {
    //
}

void Logger::create_logger_name() {
    //
}

template<typename T>
void Logger::log(T val) {
    const auto time = std::chrono::system_clock::now();
    std::cout << time.time_since_epoch() << val << std::endl;
}
