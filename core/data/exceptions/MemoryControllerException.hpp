#ifndef MEM_CONTROLLER_EXCEPTION_HPP
#define MEM_CONTROLLER_EXCEPTION_HPP

#include "BaseException.hpp"

class MemoryControllerException final : public BaseException {
public:
    static int error_to_allocate_memory();

    static int error_to_free_memory();
};

inline int error_to_allocate_memory() {
    std::cerr << "Error occurred in allocating memory for program";
    return 1;
}

inline int error_to_free_memory() {
    std::cerr << "Error occurred in freeing memory";
    return 1;
}

#endif
