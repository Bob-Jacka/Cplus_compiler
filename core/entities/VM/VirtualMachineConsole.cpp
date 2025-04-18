/*
UI app
Console that represents virtual machine parameters and execution path.
*/

#include <mutex>

class VirtualMachineConsole
{
private:
    static VirtualMachineConsole *pinstance_;
    static std::mutex mutex_;

    void __updateUI() const;

protected:
    VirtualMachineConsole() {};
    ~VirtualMachineConsole() {};

public:
    VirtualMachineConsole(VirtualMachineConsole &other) = delete;
    void operator=(const VirtualMachineConsole &) = delete;
    static VirtualMachineConsole *GetInstance();

    void drawUI() const;
};

VirtualMachineConsole *VirtualMachineConsole::pinstance_{nullptr};
std::mutex VirtualMachineConsole::mutex_;

void VirtualMachineConsole::__updateUI() const
{
    //
}

VirtualMachineConsole *VirtualMachineConsole::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new VirtualMachineConsole();
    }
    return pinstance_;
}

void VirtualMachineConsole::drawUI() const
{
    //
}
