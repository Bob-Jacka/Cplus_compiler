#include <BaseException.hpp>

class AssemblyGeneratorException : public BaseException {

    public:
    void ErrorInAssemblyGeneration();
};

void AssemblyGeneratorException::ErrorInAssemblyGeneration()
{
    std::cerr << "Error in assembly generation occurred";
}
