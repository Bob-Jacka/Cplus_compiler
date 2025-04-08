#include <BaseException.hpp>

class AssemblyGeneratorException : public BaseException {

    public:
    void ErrorInAssemblyGeneration();
};

void AssemblyGeneratorException::ErrorInAssemblyGeneration()
{
    //
}
