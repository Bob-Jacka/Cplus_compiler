#ifndef MEM_CONTROLLER_HPP
#define MEM_CONTROLLER_HPP

#include <iostream>
#include <mutex>
#include "../data/Variables.hpp"
#include "../entities/Logger.hpp"

/*
Class, that used for memory actions.
*/
class MemoryController {
    static MemoryController *pinstance_;
    static std::mutex mutex_;
    Logger *logger; //local instance of logger in file controller.

    MemoryController();

public:
    ~MemoryController();

    MemoryController(MemoryController &other) = delete;

    void operator=(const MemoryController &) = delete;

    static MemoryController *GetInstance();

    [[nodiscard]] int **create_2d_array(size_t a, size_t b) const;

    void kill_2d_array(int **m) const;

    int **create2DArrayInt(int rows, int cols);

    template<class T>
    void dynamicArrayOutput(T *array, int size, bool reverse, const string &separator);

    template<class T>
    void deleteDynamicArray(T *array, int rows);

    void lineArrayOutput(const_int *array, int array_size, const_string &separator, bool is_inline);

    template<class T>
    void userInput(T &variableAddress);
};

#endif
