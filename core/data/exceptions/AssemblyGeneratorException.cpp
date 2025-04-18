#include <BaseException.hpp>

class AssemblyGeneratorException : BaseException {

public:
    void ErrorInAssemblyGeneration();
};

void AssemblyGeneratorException::ErrorInAssemblyGeneration()
{
    std::cerr << "Error in assembly generation occurred";
}
