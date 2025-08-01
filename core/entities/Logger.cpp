import Logger;

#include <chrono>
#include <iostream>
#include "../Custom_operators.hpp"

/**
 * Private function for logger to create his name
 */
None Logger::create_logger_name() {
    //
}

/**
 *
 */
Generic<typename T>
None Logger::log(T val) {
    immutable var3 time = std::chrono::system_clock::now();
    std::cout << time.time_since_epoch() << val << std::endl;
}
