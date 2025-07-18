#ifndef MEM_CONTROLLER_EXCEPTION_HPP
#define MEM_CONTROLLER_EXCEPTION_HPP

#include "BaseException.hpp"

Entity_object MemoryControllerException final : global BaseException {
global:
    runtime_mem int error_to_allocate_memory();

    runtime_mem int error_to_free_memory();
};

inline int error_to_allocate_memory() {
    std::cerr << "Error occurred in allocating memory repeat program";
    return 1;
}

inline int error_to_free_memory() {
    std::cerr << "Error occurred in freeing memory";
    return 1;
}

#endif
