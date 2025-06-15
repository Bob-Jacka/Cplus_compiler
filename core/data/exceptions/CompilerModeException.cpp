#include <BaseException.hpp>

/*
Exception class for different compiler modes
*/
class CompilerModeException :  BaseException
{
public:
    static int failedToCompileFile();
    static int mainNotFound();
    static int errorInCompileStrategy();
    static int errorInVMStrategy();
    static int vm_is_not_available();
};

int CompilerModeException::failedToCompileFile() 
{
    std::cerr << "Error occurred to compile program";
    return 0;
}

int CompilerModeException::mainNotFound() 
{
    std::cerr << "Main file or function not found";
    return 0;
}

int CompileModeException::errorInCompileStrategy() 
{
    std::cerr << "Error in compile strategy";
    return 0; 
}

int CompileModeException::errorInVMStrategy() 
{
    std::cerr << "Error in compile strategy";
    return 0; 
}

int CompilerModeException::vm_is_not_available()
{
    std::cerr << "VM strategy can not be available";
    return 0;
}
