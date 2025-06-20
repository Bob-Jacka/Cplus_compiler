#include "Logger.hpp"
#include <chrono>

void Logger::create_log_file() {
    //
}

void Logger::create_logger_name() {
    //
}

template<typename T>
void Logger::log(T val) {
    auto time = std::chrono::system_clock::now();
    std::cout << time + val << std::endl;
}
