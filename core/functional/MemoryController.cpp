#include <iostream>
#include <mutex>

/*
Class, that used for memory actions.
*/
class MemoryController
{
private:
    static MemoryController * pinstance_;
    static std::mutex mutex_;

protected:
    MemoryController() {}
    
public:
    ~MemoryController() {}
    MemoryController(MemoryController &other) = delete;
    void operator=(const MemoryController &) = delete;
    static MemoryController *GetInstance();

    int **create_2d_array(size_t a, size_t b);
    void MemoryController::kill_2d_array(int **m);
};

MemoryController* MemoryController::pinstance_{nullptr};
std::mutex MemoryController::mutex_;

MemoryController *MemoryController::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new MemoryController();
    }
    return pinstance_;
}

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