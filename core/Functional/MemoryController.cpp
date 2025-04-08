#include <iostream>

/*
Class, that used fro memory actions.
*/
class MemoryController
{
private:
    /* data */
public:
    MemoryController(/* args */) {}
    ~MemoryController() {}
    int **create_2d_array(size_t a, size_t b);
    void MemoryController::kill_2d_array(int **m);
};

/*
Method for creating 2d array by effective way.
*/
int** MemoryController::create_2d_array(size_t a, size_t b)
{
    int **m = new int *[a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; i++)
    {
        m[i] = m[i - 1] + b;
    }
    return m;
}

/*
Method for deleting 2d array by given link.
*/
void MemoryController::kill_2d_array(int **m)
{
    delete [] m[0];
    delete [] m;
}