#include <BaseException.hpp>

class CompilerModeException :  BaseException
{
public:
    void failedToCompileFile();
};

void CompilerModeException::failedToCompileFile() {
    std::cerr << "Error occurred to compile program";
}