
#include <mutex>

/*
UI app
Console that represents virtual machine parameters.
*/
class VirtualMachineConsole
{
private:
    static VirtualMachineConsole *pinstance_;
    static std::mutex mutex_;

protected:
    VirtualMachineConsole() {};
    ~VirtualMachineConsole() {};

public:
    VirtualMachineConsole(VirtualMachineConsole &other) = delete;
    void operator=(const VirtualMachineConsole &) = delete;
    static VirtualMachineConsole *GetInstance();
};

VirtualMachineConsole *VirtualMachineConsole::pinstance_{nullptr};
std::mutex VirtualMachineConsole::mutex_;

VirtualMachineConsole *VirtualMachineConsole::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new VirtualMachineConsole();
    }
    return pinstance_;
}