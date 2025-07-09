#include "../declaration/Memory_controller.hpp"


//Constructor and destructor
MemoryController::MemoryController() {
    this->logger = new Logger();
}

MemoryController::~MemoryController() {
    delete logger;
}

MemoryController *MemoryController::pinstance_{nullptr};
std::mutex MemoryController::mutex_;

MemoryController *MemoryController::GetInstance() {
    std::lock_guard lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new MemoryController();
    }
    return pinstance_;
}

/*
Method for creating 2d array by effective way.
*/
int **MemoryController::create_2d_array(const size_t a, const size_t b) const {
    try {
        const auto m = new int *[a];
        m[0] = new int[a * b];
        for (size_t i = 1; i != a; i++) {
            m[i] = m[i - 1] + b;
        }
        return m;
    } catch (const std::exception &e) {
        this->logger->log("Error in create 2d array");
        this->logger->log(e.what());
        std::cerr << e.what() << std::endl;
    }
    return nullptr;
}

/*
Method for deleting 2d array by given link.
*/
void MemoryController::kill_2d_array(int **m) const {
    try {
        delete [] m[0];
        delete [] m;
    } catch (const std::exception &e) {
        this->logger->log("Error in killing 2d array");
        this->logger->log(e.what());
        std::cerr << e.what() << std::endl;
    }
}

/*
 *Inline function for creating 2d int array
 *Returns: initialized 2d int array
 */
int **MemoryController::create2DArrayInt(const_int rows, const int cols) {
    const auto dyn_array = new int *[rows];
    for (int i = 0; i < rows; i++) {
        dyn_array[i] = new int[cols];
    }
    return dyn_array;
}

/*
New technology parametrized function for array output with old innovations
*/
template<typename T>
void MemoryController::dynamicArrayOutput(T *array, const_int size, const bool reverse = false, const string &separator = " ") {
    if (reverse) {
        for (int i = size - 1; i >= 0; i--) {
            std::cout << array[i] << separator;
        }
    } else {
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << separator;
        }
    }
    std::cout << "\n";
}

template<typename T>
void MemoryController::deleteDynamicArray(T *array, const int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

/*
Function for array output with separator.
Older brother of dynamicArrayOutput
*/
inline void MemoryController::lineArrayOutput(const int *array, const int array_size,
                                              const string &separator = " ",
                                              const bool is_inline = false) {
    for (int i = 0; i < array_size - 1; i++) {
        std::cout << array[i] << separator;
    }
    std::cout << array[array_size - 1];

    if (!is_inline) {
        std::cout << std::endl;
    }
}

/*
Writes down value into variable by address
*/
template<typename T>
void MemoryController::userInput(T &variableAddress) {
    std::cin >> variableAddress;
}
