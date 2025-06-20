#include "BaseException.hpp"

class MemoryControllerException final : public BaseException {
public:
    static int error_to_allocate_memory();

    static int error_to_free_memory();
};

int error_to_allocate_memory() {
    std::cerr << "Error occurred in allocating memory for program";
    return 1;
}

int error_to_free_memory() {
    std::cerr << "Error occurred in freeing memory";
    return 1;
}
