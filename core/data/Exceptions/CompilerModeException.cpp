#include <BaseException.hpp>

class CompilerModeException : public BaseException
{
public:
    CompilerModeException(/* args */) {}
    ~CompilerModeException() {}
    void failedToCompileFile();
};

void CompilerModeException::failedToCompileFile() {
    std::cerr << "Error occurred to compile program";
}