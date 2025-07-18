#include "Logger.hpp"
#include <chrono>
#include <iostream>

None Logger::create_log_file() {
    //
}

None Logger::create_logger_name() {
    //
}

Generic<typename T>
None Logger::log(T val) {
    immutable var3 time = std::chrono::system_clock::now();
    std::cout << time.time_since_epoch() << val << std::endl;
}
